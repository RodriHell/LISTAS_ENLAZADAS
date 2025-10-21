#include <stdio.h>
#include <stdlib.h>
#include "lista.h"


ListaPtr crearLista(){
    ListaPtr Lista = (ListaPtr) malloc (sizeof(struct ListaE));

    Lista->tam = 0;
    Lista->inicio = NULL;

    return Lista;
}

void agregarInicio (ListaPtr lista, int edad, char *nombre){
    NodoPtr nuevoNodo = crearNodo(edad, nombre, lista->inicio);

    lista->inicio = nuevoNodo;
    lista->tam ++;
}

void agregarFinal (ListaPtr lista, int edad, char *nombre){
    NodoPtr nuevoNodo = crearNodo(edad, nombre, NULL);

    if (lista->inicio == NULL){
        lista->inicio = nuevoNodo;
    }
    else{
        NodoPtr actual = lista->inicio;
        while (actual->sig != NULL){
            actual = actual->sig;
        }
        actual->sig = nuevoNodo;
    }
    lista->tam++;

}

void agregarEnPosicion (ListaPtr lista, int edad, char *nombre, int pos){
    if (pos > lista->tam){ return; }
    NodoPtr nuevoNodo = crearNodo(edad, nombre,NULL);
    NodoPtr actual = lista->inicio;
    if (pos == 0 ){
        agregarInicio(lista, edad, nombre);
        return;
    }
    if (pos == lista->tam){
        agregarFinal(lista, edad,nombre);
        return;
    }
    int contador = 0;
    while (contador < pos - 1){
        contador ++;
        actual = actual->sig;
    }
    nuevoNodo->sig = actual->sig;
    actual->sig = nuevoNodo;
    lista->tam++;
}

void mostrarLista (ListaPtr lista){
    NodoPtr actual = lista->inicio;
    printf ("\n<Lista>\n");
    while (actual != NULL){
        mostrarNodo(actual);
        actual = actual->sig;
    }
    printf ("\n\n");

}

void liberarLista (ListaPtr lista){
    NodoPtr actual = lista->inicio;
    NodoPtr siguiente;
    while (actual != NULL){
        NodoPtr aux = actual;
        siguiente = actual->sig;
        free (actual);
        actual = siguiente;
    }
}

int obtenerTamanio (ListaPtr lista){
    return lista->tam;
}

void eliminarNodo (ListaPtr lista, int pos){
    if (lista->inicio == NULL || lista == NULL || pos < 0) return;
    NodoPtr actual = lista->inicio;
    NodoPtr anterior = NULL;
    int i=0;
    while (actual != NULL && i < pos){
        anterior = actual;
        actual = actual -> sig;
        i++;
    }
    if (actual == NULL) return; //Fuera de rango

    if (anterior == NULL){
        lista->inicio = actual->sig;
    }else{
        anterior->sig = actual->sig;
    }

    free (actual->nombre);
    free (actual);
}

int busquedaEdad (ListaPtr lista, int busco){
    NodoPtr actual = lista->inicio;
    int cont = 0;
    while (actual != NULL){
        if (actual->edad == busco){
            return cont;
        }
        actual = actual->sig;
        cont++;
    }
    return -1;
}

void ordenarPorEdad(ListaPtr lista){
    ///metodo burbuja
    NodoPtr actual;
    NodoPtr siguiente;
    int intercambio = 0;
    do {
        intercambio = 0;
        actual = lista->inicio;
        while (actual != NULL && actual->sig != NULL){
            siguiente = actual->sig;
            if (actual->edad > siguiente->edad){
                int tempEdad = actual->edad;
                actual->edad = siguiente->edad;
                siguiente->edad = tempEdad;

                char *tempNombre = actual->nombre;
                actual->nombre = siguiente->nombre;
                siguiente->nombre = tempNombre;

                intercambio = 1;
            }
            actual = actual->sig;
        }
    } while (intercambio);
}

int* crearVectorEdad (ListaPtr lista){
    int tam = lista->tam;
    int i= 0;
    int* vector = (int*)malloc(tam * sizeof(int));
    NodoPtr actual = lista->inicio;
    while (actual != NULL){
        vector[i] = actual->edad;
        i++;
        actual = actual->sig;
    }
    for (int j= 0;j<i;j++){
        printf ("Pos : %d Edad: %d",j, vector[j]);
        printf ("\n");
    }
    return vector;
}
