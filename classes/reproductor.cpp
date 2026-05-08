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
    lectura();
}
void reproductor::menu() {
    char opcion;
    do {
        cout<<"Opciones \n  W – Reproducir/Pausar \n Q – Pista Anterior \n E – Pista Siguiente";
        cout<<"S – Activar/Desactivar modo aleatorio \n  R – Repetición (Desactivado/Repetir una/Repetir todas)  \n A – Ver lista de reproducción actual \n L – Listado de canciones";
        cout<<"X – Salir \n Ingrese Opción: \n";
        switch (opcion) {
            case "W": pausar(); break;
            case "Q": anterior(); break;
            case "E": siguiente(); break;
            case "S": activar(); break;
            case "R": repetir(); break;
            case "A": listaReproduciones(); break;
            case "L": lista(); break;
            default: cout<<"Opcion no valida";
        }
    }while(opcion!="X");

}
void pausar() {
    reproducir = !reproducir;

}
void anterior() {
    if (nodoActual && nodoActual->anterior) {
        nodoActual = nodoActual->anterior;
    }
}
void siguiente() {
    if (nodoActual && nodoActual->siguiente) {
        nodoActual = nodoActual->siguiente;
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

    Nodo<Cancion> * aux;
    while (aux!= nullptr) {
        cout<<aux->dato.nombre;
        cout<<aux->dato.autor;

        aux = aux->siguiente;
    }
    cout<<"Reproducir canción seleccionada";
    cout<<"A<num> - Agregar canción seleccionada al final de la lista de reproducción actual";
    cout<<"N – Agregar canción al registro de canciones";
    cout<<"D<num> – Eliminar canción seleccionada";
    cout<<"V – Volver al menú principal";
}


}
    void aleatorio() {
        aleatorio = !aleatorio;
    }