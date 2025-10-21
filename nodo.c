#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nodo.h"

NodoPtr crearNodo (int edad, char *nombre, NodoPtr sig){
    NodoPtr nodoNuevo = (NodoPtr)malloc (sizeof(struct Nodo));

    nodoNuevo->edad = edad;
    nodoNuevo->nombre = strdup(nombre);
    nodoNuevo -> sig = sig;

    return nodoNuevo;
}

void mostrarNodo (NodoPtr nodo){
    printf ("{ %d | %s }",nodo->edad, nodo->nombre);
    printf ("\n");
}

void liberarNodo (NodoPtr nodo){
    free (nodo->nombre);
    free (nodo);
}
