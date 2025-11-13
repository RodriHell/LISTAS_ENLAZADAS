# Implementación de Lista Enlazada Simple (C)

Implementación desde cero del Tipo de Dato Abstracto de una Lista Enlazada Simple en C, sin utilizar librerías externas de estructuras de datos.

# Objetivo
Manejo de punteros y memoria dinámica, creando una estructura de datos flexible capaz de crecer y decrecer en tiempo de ejecución.

# Funcionalidades
* Agregar nodos al inicio, al final o en una posición específica.
* Borrado de nodos liberando correctamente la memoria del nodo y de sus datos internos (`strdup`).
* Iteración eficiente sobre la lista.
* Algoritmo de ordenamiento aplicado sobre los nodos de la lista.
* Conversión de la lista a un vector/array estándar.

# Highlights del Código
* Prevención de Fugas de memoria: Se implementaron funciones destructoras (`liberarLista`, `liberarNodo`) para asegurar que toda la memoria asignada con `malloc` sea devuelta al sistema.
* Manejo de Casos Borde: El código maneja robustamente listas vacías o inserciones en índices fuera de rango.
* Separación de Responsabilidades: Archivos `nodo.c` (datos) separados de `lista.c` (contenedor).

# Compilación
```bash
gcc main.c lista.c nodo.c -o lista_app
./lista_app
