//
// Created by camil on 5/6/2026.
//

#ifndef TALLER_REPRODUCTOR_H
#define TALLER_REPRODUCTOR_H
#include "Cancion.h"
#include "../data_structures/Lista.h"


class reproductor {
private:
    Lista<Cancion> canciones;
    Lista<Cancion> playlist;
    Nodo<Cancion> * nodoActual;
    bool reproducir;
    //modo aleatorio

    bool aleatorio;
    int modo;
    public:
    reproductor();
    void iniciar();
    void cargar();
    void menu();
    void lista();
    void  pausar();
    void  anterior();
    void  siguiente();
    void  activar();
    void  repetir();
    void  listaReproduciones();
    void alea();
    void reproducirCanciones(int n);
    void agregarCancion(int n);
    void reproducirPlaylist(int n);
    void listaPlaylist();
    void agregarNueva(int n);
};



#endif //TALLER_REPRODUCTOR_H
