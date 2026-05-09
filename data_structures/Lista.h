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
        std::cout << std::endl;

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
    void eliminar(int n) {
        if (head == nullptr) {
            return;
        }
        Nodo<T>* aux = head;
        int i =1;
        while (aux != nullptr && i <n) {
            aux = aux->sig;
            i++;
        }
        if (aux == nullptr) {
            return;
        }if (aux == head && aux == cola) {
            head = nullptr;
            cola = nullptr;
        }else if (aux == head){
            head = head->sig;
            if (head != nullptr) {
                head->ant = nullptr;
            }

        }else if (aux == cola) {
            cola = cola->ant;
            if (cola != nullptr) {
                cola->ant = nullptr;
            }
        }else {
            aux->ant->sig = aux->sig;
            aux->sig->ant = aux->ant;
        }
        delete aux;
    }
};




#endif //TALLER_LISTA_H
