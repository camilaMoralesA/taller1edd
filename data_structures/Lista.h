//
// Created by camil on 5/3/2026.
//

#ifndef TALLER_LISTA_H
#define TALLER_LISTA_H

#include "Nodo.h"
template <typename T>

class Lista {
private:
    Nodo<T> *head;
    Nodo<T> *cola;
public:
    Lista() {
        this->head = NULL;
        this->cola = NULL;
    }
    Nodo<T> *getCola() {
        return this->cola;
    }
    Nodo<T> *getHead() {
        return this->head;
    }
};



#endif //TALLER_LISTA_H
