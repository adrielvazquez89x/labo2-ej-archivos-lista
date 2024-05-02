#include <iostream>
#include "Tarea.h"
#include "Archivo.h"

using namespace std;

int main()
{
    Tarea prueba(3, "Riquelme", 1, Fecha(1, 5, 2024), 1);
    Archivo gestorArchivo;
    int opcion = 1;

    while (opcion == 1) {
     gestorArchivo.cargarArchivo();
     cout << "CARGAR OTRO?: ";
     cin >> opcion;
     cin.ignore();
    }

    gestorArchivo.listarArchivo();
    gestorArchivo.generarReporte();

    //gestorArchivo.generarReporte();


    
   
    
    return 0;
}

