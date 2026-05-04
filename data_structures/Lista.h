//
// Created by camil on 5/3/2026.
//

#ifndef TALLER_LISTA_H
#define TALLER_LISTA_H

#include <iostream>

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
    void ver() {
        nodo<T> *aux = head;
        while (aux != NULL) {
            cout << aux->dato << " ";
            aux = aux->sig;
        }

    }
    void agregar(T dato) {
        Nodo<T> *aux = new Nodo<T>();
        cola->sig = aux;
        aux->ant = cola;
        cola = aux;
    }
    
};



#endif //TALLER_LISTA_H
