//
// Created by camil on 5/6/2026.
//

#include "reproductor.h"

#include "../core/lectura.h"
using namespace std;
reproductor::reproductor() {
    nodoActual = nullptr;
    reproducir = false;
    aleatorio = false;



}
void reproductor::iniciar() {
    cargar();

    menu();
    }

void reproductor::cargar() {
    lectura(canciones);
}
void reproductor::menu() {
    char opcion;
    do {
        cout<<"Opciones \n  W – Reproducir/Pausar \n Q – Pista Anterior \n E – Pista Siguiente";
        cout<<"S – Activar/Desactivar modo aleatorio \n  R – Repetición (Desactivado/Repetir una/Repetir todas)  \n A – Ver lista de reproducción actual \n L – Listado de canciones";
        cout<<"X – Salir \n Ingrese Opción: \n";
        cin >> opcion;

        switch (opcion) {
            case 'W':
                pausar(); break;
            case 'Q': anterior(); break;
            case 'E': siguiente(); break;
            case 'S': activar(); break;
            case 'R': repetir(); break;
            case 'A': listaReproduciones(); break;
            case 'L': lista(); break;
            default: cout<<"Opcion no valida";
        }
    }while(opcion != 'X');

}
void reproductor::pausar(){
reproducir = !reproducir;
    if (reproducir) {
        cout<<"Reproduciendo\n";
    }else {
        cout<<"pausado\n";
    }

}
void reproductor::anterior() {
    if (nodoActual && nodoActual->ant) {
        nodoActual = nodoActual->ant;
        cout <<"actual: ";
        cout<<nodoActual->dato.nombre;
    }
}
void reproductor::siguiente() {
    if (nodoActual && nodoActual->sig) {
        nodoActual = nodoActual->sig;
        cout <<"actual: ";
        cout<<nodoActual->dato.nombre;
    }
}
void reproductor::lista() {
    /*
    *Opciones:
R<num> - Reproducir canción seleccionada
A<num> - Agregar canción seleccionada al final de la lista de reproducción actual
N – Agregar canción al registro de canciones
D<num> – Eliminar canción seleccionada
V – Volver al menú principal

     */

    cout<<nodoActual->dato.nombre<<endl;
    cout<<"Listado de canciones";

    Nodo<Cancion>* aux = canciones.getHead();
    while (aux!= nullptr) {
        cout<<aux->dato.nombre;
        cout<<aux->dato.autor;

        aux = aux->sig;
    }
    string opcion;
    cout<<"R<num> - Reproducir canción seleccionada";
    cout<<"A<num> - Agregar canción seleccionada al final de la lista de reproducción actual";
    cout<<"N – Agregar canción al registro de canciones";
    cout<<"D<num> – Eliminar canción seleccionada";
    cout<<"V – Volver al menú principal";
    cin>>opcion;
    char letra = toupper(opcion[0]);
    switch (letra) {
        case 'V':
            return;
        case 'N':
            agregarNueva(n);
            break;
    }
    if (letra == 'R' || letra == 'A' || letra == 'D') {
    int n = stoi(opcion.substr(1));
        switch (letra) {
            case 'R':
                reproducirCanciones(n);
                break;
            case 'A':
                agregarNueva(n);
                break;
            case 'D':
                playlist.eliminar(n);
                break;
        }

        }
    }
void reproductor::agregarNueva(int n) {
    Nodo<Cancion>* aux = canciones.getHead();
    int i = 1;
    while (aux != nullptr) {
        if (i == n) {
            playlist.agregar(aux->dato);
            cout<<"Cancion agregada"<<endl;
            return;
        }
        aux = aux->sig;
        i++;
    }

}
void reproductor::reproducirCanciones(int n) {
    Nodo<Cancion>* aux = canciones.getHead();
    int i =1;
    while (aux != nullptr) {
        if (i == n) {
            nodoActual = aux;
            reproducir = true;
            cout<<"reproduciento: " + nodoActual->dato.nombre<<endl;
            return;

        }
        aux = aux->sig;
        i++;
    }

}
    void reproductor::listaReproduciones() {
    Nodo<Cancion>* aux = playlist.getHead();
    cout<<"Playlist\n";
    int i = 1;
    while (aux != nullptr) {
        cout<<aux->dato.nombre<<endl;
        cout<<aux->dato.autor<<endl;
        aux = aux->sig;
        i++;
    }
}

    void reproductor::alea() {
        aleatorio = !aleatorio;
    }