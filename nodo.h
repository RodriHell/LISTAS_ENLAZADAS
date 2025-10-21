#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

struct Nodo {
    int edad;
    char *nombre;
    struct Nodo * sig;
};
typedef struct Nodo * NodoPtr;


NodoPtr crearNodo (int edad, char *nombre, NodoPtr sig);

void liberarNodo (NodoPtr sig);

void mostrarNodo (NodoPtr nodo);

#endif // NODO_H_INCLUDED
