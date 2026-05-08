//
// Created by camil on 5/6/2026.
//

#include "reproductor.h"

#include "../core/lectura.h"
using namespace std;
reproductor::reproductor() {

}
void reproductor::iniciar() {
    cargar();

    menu();
    }

void reproductor::cargar() {
    lectura();
}
void reproductor::menu() {
    string opcion;
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
void reproductor::lista() {
    cout<<nodo;

}