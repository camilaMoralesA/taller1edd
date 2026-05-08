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
        this->head = nullptr;
        this->cola = nullptr;
    }
    Nodo<T> *getCola() {
        return this->cola;
    }
    Nodo<T> *getHead() {
        return this->head;
    }
    void ver() {
        Nodo<T> *aux = head;
        while (aux != nullptr) {
            std::cout << aux->dato << " ";
            aux = aux->sig;
        }

    }
    void agregar(T dato) {

        Nodo<T>* aux = new Nodo<T>(dato);

        if (head == nullptr) {
            head = aux;
            cola = aux;
        }
        else {
            cola->sig = aux;
            aux->ant = cola;
            cola = aux;
        }
    }
    
};



#endif //TALLER_LISTA_H
