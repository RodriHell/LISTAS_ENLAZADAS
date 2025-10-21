#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "nodo.h"

struct ListaE {
    int tam;
    NodoPtr inicio;
};
typedef struct ListaE * ListaPtr;

ListaPtr crearLista();

void agregarInicio (ListaPtr lista, int edad, char *nombre);

void mostrarLista (ListaPtr lista);

void liberarLista (ListaPtr lista);
void eliminarNodo(ListaPtr lista, int pos);
void agregarFinal (ListaPtr lista, int edad, char *nombre);
void agregarEnPosicion (ListaPtr lista, int edad, char *nombre, int pos);
void ordenarPorEdad(ListaPtr lista);

int obtenerTamanio (ListaPtr lista);
int busquedaEdad (ListaPtr lista, int busco);

int* crearVectorEdad (ListaPtr lista);

#endif // LISTA_H_INCLUDED
