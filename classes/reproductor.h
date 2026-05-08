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
        Nodo<Cancion> *nodo;
    public:
    reproductor();
    void iniciar();
    void cargar();





};



#endif //TALLER_REPRODUCTOR_H
