//
// Created by camil on 5/3/2026.
//

#ifndef TALLER_NODO_H
#define TALLER_NODO_H



template <typename T>
struct Nodo {
    T dato;
    Nodo<T> *sig;
    Nodo<T>*ant;
    Nodo(T dato) {
        this->dato = dato;
        this->ant = NULL;
        this->sig = NULL;

    }
}



#endif //TALLER_NODO_H
