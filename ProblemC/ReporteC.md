
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

Test 1:
Input: 3 5
2 4
3 5
4 6
Output: 9

Test 2:
Input: 4 7
3 4
4 5
2 3
5 8
Output: 11

Test 3:
Input: 3 6
1 2
2 4
3 7
Output: 13