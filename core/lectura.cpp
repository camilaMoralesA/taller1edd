//
//id_interno,nombre_cancion,nombre_artista,nombre_album,año,duración_en_segundos,ubicacion_archivo

#include "lectura.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;
void lectura() {
    string linea;
    ifstream file("x.txt");
    while (getline(file,linea)) {
        stringstream ss(linea);
    }
}
