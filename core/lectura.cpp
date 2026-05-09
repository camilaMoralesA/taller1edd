
#include "lectura.h"
#include <fstream>
#include <sstream>
#include "../classes/Cancion.h"
#include "../data_structures/Lista.h"

//id_interno,nombre_cancion,nombre_artista,nombre_album,año,duración_en_segundos,ubicacion_archivo

using namespace std;
void lectura::leer(Lista<Cancion>& lista) {
    string linea;
    ifstream file("music_source.txt");
    while (getline(file,linea)) {
        stringstream ss(linea);
        string partes[7];
        string campo;
        int i = 0;
        while(getline(ss, campo, ';')) {

            partes[i] = campo;
            i++;
        }
        Cancion c(stoi(partes[0]),partes[1],partes[2],partes[3],stoi(partes[4]),stod(partes[5]),partes[6]);
        lista.agregar(c);
    }
};


