Reporte Tarea 1
Ejercicio 1 - Contar inversiones: 
Para este primer ejercicio utilize el metodo de divide and conquer, use Merge sort
Arreglue el arreglo pero fui contando las inversiones que habia dentro de este. 
Una inversion pasaba cuando el numero de la derecha es menor que uno en la parte izquierda. 
Un ejemplo: 312 
Las inversiones en este caso serian (3,1), (3,2) por lo que el resultado seria 2. 
La parte mas importante se encuentra cuando arr[i] > arr[j]
Como la parte izquierda ya se encuentra ordenada, si arr[i] es mayor que todos los elementos desde i hasta mid tambien seran mayores. 
Aqui tuve un problema ya que estaba aumentando de uno el contador, no contaba que todos los elementos de i hasta mid tambien lo eran. 
Por eso no solamente se aumenta el contador mas uno, si no que se utiliza: 
contador += mid - i +1; 
El pseudocodigo seria algo asi 

MergeSort(arreglo, izquierda, derecha)

    si izquierda >= derecha 
        acaba
    mid = mitad del arreglo
    mergesort(de la parte izquierda)
    mergesort(de la parte derecha)
    merge(izquierda y derecha)


Merge()
    creas un arreglo temporal 
    mientras existen elementos en las 2 mitades hacer: 
        si elemento izquierdo igual o menor que el elemento derecho 
            agregar izquierdo al arreglo temporal 
            avanzas izquierda
        de lo contrario 
            agregas elemento al arreglo temporal 
            haces la suma del contador mencionada anteriormente
            avanzas derecha
        
        agregas lo que queda de la parte izquierda o derecha

        copias el arreglo al original 

COMPLEJIDAD
Merge sort divide el arreglo aproximadamente a la mitad cada vez por lo que existen log n niveles
cada nivel se recorre n veces por lo que el tiempo es O(n log n)
En memoria se utiliza un vector temporal para el merge, en el peor caso puede guardar n elementos
por lo tanto: 
Tiempo: O(n log n)
Espacio: O(n)
    

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


Ejercicio 3 - Dynamic Programming:
Para este ejercicio utilice dynamic programming, la idea era encontrar el mayor valor posible sin pasarme del tiempo maximo T.
Cada modulo tiene un tiempo y un valor.

Por ejemplo un modulo podria ser:
(time = 3, value = 5)

Esto significa que utilizar ese modulo cuesta 3 de tiempo y da un valor de 5.

Para resolverlo cree un arreglo llamado dp de tamaño T + 1.
Cada posicion representa el mejor valor que puedo conseguir utilizando hasta cierta cantidad de tiempo.

Por ejemplo:
dp[5] representa el mejor valor que puedo conseguir utilizando un tiempo maximo de 5.

La parte mas importante es:

dp[tiempo] = max(
    dp[tiempo],
    dp[tiempo - t[i]] + v[i]
);

Aqui se comparan 2 opciones.
La primera es no utilizar el modulo actual, por lo que dejo el valor que ya estaba en dp[tiempo].
La segunda es utilizar el modulo actual, por lo que tomo el mejor valor que tenia antes en dp[tiempo - t[i]] y le sumo el valor del modulo actual.

Al final me quedo con el valor mas grande de los 2.

Tambien fue importante recorrer el tiempo de derecha a izquierda.
Esto se hace porque cada modulo solamente se puede utilizar una vez.
Si recorriera de izquierda a derecha podria actualizar una posicion de dp y despues volver a utilizar ese mismo valor para usar el mismo modulo otra vez.

Por ejemplo si tengo:
T = 5

y los modulos:
(2,4)
(3,5)

Puedo utilizar los 2 porque:
2 + 3 = 5

Y el valor seria:
4 + 5 = 9

Por lo que el resultado seria 9.

El pseudocodigo seria algo asi

crear arreglo dp de tamaño T + 1 lleno de ceros

para cada modulo hacer:

    recorrer tiempo desde T hasta el tiempo del modulo

        opcion1 = no utilizar el modulo

        opcion2 = utilizar el modulo
        dp[tiempo - tiempoModulo] + valorModulo

        guardar en dp[tiempo] la opcion mas grande 
al final
    respuesta = dp[T]

COMPLEJIDAD
Se recorren todos los modulos por lo ciual tenemos n elementos.
Dentro de cada modulo se recorre el tiempo desde T hasta el tiempo del modulo.
En el peor caso este ciclo puede recorrer T posiciones.

Por lo tanto el tiempo es:
O(n * T)

En memoria solamente se utiliza el arreglo dp que tiene T + 1 posiciones.
Por lo tanto:

Tiempo: O(n * T)
Espacio: O(T)