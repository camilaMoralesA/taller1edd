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
    modo = 0;



}
void reproductor::iniciar() {
    cargar();

    menu();
    }

void reproductor::cargar() {
    lectura(canciones);
}
void reproductor::menu() {
    bool ale = false;

    if (reproducir) {
        cout<<"Reproduciendo";
    } else {
        cout<<"Pausado";

    }if ( aleatorio) {
        cout<<"S";
        ale = true;


    }
    if (modo == 1) {
        if (ale) {
            cout<<"-";

        }
        cout<<"R1";
    }else if (modo == 2) {
        if (ale) {
            cout<<"-";

        }
    }
        cout<<"R2";
        cout<<")";
        cout<<":";
        cout<<nodoActual->dato.nombre;
        cout<<"\n";
        cout<<"autor: ";
        cout<<nodoActual->dato.autor;
        cout<<"album: ";
        cout<<nodoActual->dato.album;
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
                case 'S': alea(); break;
                case 'R': repetir(); break;
                case 'A': listaReproduciones(); break;
                case 'L': lista(); break;
                case 'X':
                    cout<<"Saliendo";
                    break;
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
        }if (modo == 1) {
            cout<< nodoActual->dato.nombre<<endl;
            return;
        }else {
            if (modo == 2) {
                nodoActual = canciones.getHead();
            }if (aleatorio) {
                alea();
            }
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
                cout<<"nombre":
                string nombre;
                getline(cin, nombre);
                cout<<"autor":
                string autor;
                cin>>autor;
                cout<<"album":
                string album;
                cin>>nombre;
                cout<<"nombre":
                string nombre;
                cin>>nombre;
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
                    canciones.eliminar(n);
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
        if (aleatorio) {
            cout<<"modo aleatorio activado";
        }else {
            cout<<"modo aleatorio desativado";
        }
    }

    void reproductor::repetir() {
        modo++;
        if (modo >2) {
            modo = 0;
        }
        switch (modo) {
            case 0:
                cout<<"repetiones desativadas";
                break;
            case 1:
                cout<<"repetiendo una cancion";
                break;
            case 2:
                cout<<"repetiendo todas las canciones";
                break;
        }


};