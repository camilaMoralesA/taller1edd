//
// Created by camil on 5/3/2026.
//

#ifndef TALLER_CANCION_H
#define TALLER_CANCION_H
#include <string>
using namespace std;

//id_interno,nombre_cancion,nombre_artista,nombre_album,año,duración_en_segundos,ubicacion_archivo

class Cancion {

    public:
    int id;
    string nombre ;
    string autor;
    string album;
    int año;
    double duracion;
    string direccion;
    Cancion(int id, string nombre, string autor, string album, int año, double duracion, string direccion) {
        this->id = id;
        this->nombre = nombre;
        this->autor = autor;
        this->album = album;
        this -> duracion = duracion;
        this->direccion = direccion;
        this->año = año;

    }
};




#endif //TALLER_CANCION_H
