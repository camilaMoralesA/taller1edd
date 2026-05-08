//
//id_interno,nombre_cancion,nombre_artista,nombre_album,año,duración_en_segundos,ubicacion_archivo

#include "lectura.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;
void lectura::leer(Lista<Cancion>& lista) {
    string linea;
    ifstream file("x.txt");
    while (getline(file,linea)) {
        stringstream ss(linea);
        string partes[8];
        string campo;
        int i = 0;
        while (getline(ss,campo,"{;")) {
            partes[i] = campo;
        }
        cancion c(partes[0],partes[1],partes[2],partes[3],partes[4],partes[5],partes[6],partes[7]);
    }
};


