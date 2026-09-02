Reporte Tarea 1
Ejercicio 1 - Contar inversiones: 
Para este primer ejercicio utilize el metodo de divide and conquer, use Merge sort
Arreglue el arreglo pero fui contando las inversiones que habia dentro de este. 
Una inversion pasaba cuando el numero de la derecha es menor que uno en la parte izquierda. 
Un ejemplo: 3 1 2 
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
    
Test 1: 
input: 3 
3 1 2
Output: 2

Test 2: 
Input: 5
1 2 3 4 5 
Output: 0 

Test 3: 
Input:5 
5 4 3 2 1
Output: 10 
