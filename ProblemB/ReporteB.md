Ejercicio 2 - Salones para reuniones:
Para este ejercicio utilice un metodo greedy, fui revisando las reuniones una por una y viendo si podia reutilizar un salon que ya habia sido usado anteriormente.
Cada reunion tiene un tiempo de inicio y un tiempo de final.

Por ejemplo:
(1,4), (2,5), (5,7)

La primera reunion utiliza un salon.
La segunda empieza en 2 pero el primer salon termina hasta 4, por lo que necesita otro salon.
La tercera empieza en 5 y el primer salon termino en 4, por lo que se puede volver a utilizar ese salon.
En este caso se ocuparian 2 salones.

La parte mas importante se encuentra cuando:
rooms_check[j].second <= meetings[i].first

Esto quiere decir que el tiempo en el que termino la reunion anterior es menor o igual al tiempo en el que empieza la nueva reunion.
Si se cumple esto significa que el salon ya esta disponible y se puede utilizar para la nueva reunion.

Si no se encuentra ningun salon disponible entonces se tiene que agregar otro salon al vector.

El pseudocodigo seria algo asi

crear arreglo de salones

para cada reunion hacer:

    si no hay salones
        crear un salon
        guardar la reunion

    de lo contrario
        revisar cada salon

        si el salon termina antes o al mismo tiempo que empieza la reunion
            guardar la nueva reunion en ese salon
            dejar de revisar

        si llegaste al ultimo salon y ninguno estaba disponible
            crear un nuevo salon

COMPLEJIDAD
Se recorren todas las reuniones por lo que se hace un ciclo de m elementos.
Dentro de este ciclo se pueden recorrer todos los salones que se han creado.
En el peor de los casos podria haber m salones, por lo que se tendrian m recorridos dentro de otros m recorridos.

Por lo tanto:
Tiempo: O(m²)
Espacio: O(m)

El espacio es O(m) porque en el peor de los casos todas las reuniones se cruzan y cada una necesita un salon diferente, por lo que el vector rooms_check tendria m elementos.

Test 1:
Input: 3
1 4
2 5
5 7
Output: 2

Test 2:
Input: 4
1 2
2 3
3 4
4 5
Output: 1

Test 3:
Input: 4
1 10
2 9
3 8
4 7
Output: 4
