//
// Created by camil on 5/3/2026.
//

#ifndef TALLER_NODO_H
#define TALLER_NODO_H



template <typename T>

 struct Nodo {
    T dato;
    Nodo<T>* sig;
    Nodo<T>* ant;

    Nodo(T dato) : dato(dato), sig(nullptr), ant(nullptr) {}
};




#endif //TALLER_NODO_H
