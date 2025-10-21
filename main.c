#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"
#include "lista.h"

int main()
{
    ListaPtr lista = crearLista();
    agregarInicio(lista, 20,"Rodrigo");
    mostrarLista(lista);
    agregarInicio(lista, 21,"Alejo");
    agregarFinal(lista, 22, "Maca");
    agregarEnPosicion(lista, 23, "Tati", 3);
    mostrarLista(lista);

    ordenarPorEdad(lista);
    mostrarLista(lista);

    int* vector = crearVectorEdad(lista);


    return 0;
}
