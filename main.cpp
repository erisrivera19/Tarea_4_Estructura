#include "NodoArbolBinario.h"
#include "Evaluador.h"
#include <iostream>       // std::cin, std::cout
#include <list>          // std::list
using namespace std;

//Devuelve la suma de todos los numeros del arbol con la raiz dada.
int suma(NodoArbolBinario* raiz)
{
    if(raiz==NULL) //con el if verificamos que exista algun valor dentro de la raiz
    return 0; // retornamos cero sino existe el valor

    int suma_total = raiz->num; // se crea una variable que guarde el valor dentro de la raiz
    suma_total += suma(raiz->hijo_der) + suma(raiz->hijo_izq); // se suma la raiz, del hijo derecho y del hijo izquierdo mediante recursividad

    return suma_total; // return la suma total
}

//Devuelve la cantidad de nodos que tiene el arbol con la raiz dada.
int cantidadNodos(NodoArbolBinario* raiz)
{
    int contador =0; // creamos una variable que contara la cantidad de nodos

    if(raiz==NULL) // con el if verificamos que el valor de la raiz exista
    return 0;  // retorna cero si no existe

    contador++; // se le va sumando 1++ al contador
    contador += cantidadNodos(raiz->hijo_der)+cantidadNodos(raiz->hijo_izq); // con recursividad se van sumando todos los nodos de izquierda y derecha

    return contador; // return el valor de los nodos
}

//Devuelve el promedio de los numeros que tiene el arbol con la raiz dada.
int promedio(NodoArbolBinario* raiz)
{
    return suma(raiz)/cantidadNodos(raiz); // reutilizaamos las funiones suma y cantidad de nodos para sacar el promedio
}

int cuantosPasos(NodoArbolBinario* raiz,int num)
{
    int contador =1; // creamos una variable para que cuentes los pasos
    if(raiz==NULL) // con el if verificamos si la raiz existe
    return contador; // return si no existe el valor del contador

    if(raiz->num == num) // si el valor de la raiz es el num que buscamos retorne el contador
        return contador; // retorna 1


    if(num>raiz->num) // con el if verificamos si el numero es mayor que la raiz dada
        contador += cuantosPasos(raiz->hijo_der,num); // si es mayor buscamos por los hijos de la derecha y se cuentan los pasos buscados

    if(num<raiz->num) // con el if verificamos si el numero es menor que la raiz dada
        contador += cuantosPasos(raiz->hijo_izq,num); // si es menor buscamos por los hijos de la izquierda y se cuentan los pasos

    return contador; // retorna los pasos contados
}

//Devuelve verdadero si el arbol dado esta ordenado estilo AVL, de lo contrario devuelve falso.
bool esAVL(NodoArbolBinario* raiz)
{
    if(raiz==NULL) // Revisamos si el arbol ya se encuentra vacio
    return true; // retornamos true si llega al ultimo elemento encontrados

        if(raiz->hijo_izq !=NULL && raiz->hijo_izq->num>raiz->num or raiz->hijo_der!=NULL && raiz->hijo_der->num<raiz->num) // revisando que exista el hijo derecho y el izquierdo, negando el orden AVL para los dos
            return false; // si esto resulta incorrecto, entonces el arbol no esta ordenado

        return esAVL(raiz->hijo_izq) && esAVL(raiz->hijo_der); // recorremos cada nodo mediante recursividad desde la raiz

}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 1;
}
