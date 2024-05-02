#pragma once
#include "Tarea.h"
#include <string>

class Archivo
{
protected:
	std::string _prioridad[3];
	std::string _estado[3];

public: 

	Archivo();

	//Escribe en archivo.dat
	void guardarArchivo(Tarea);
	// Retorna un archivo, busca por ID
	Tarea leerArchivo(int);
	// Retorna un archivo, busca por indice.
	Tarea leerArchivoIndice(int);
	// Muestra la tarea.
	void mostrarTarea(Tarea);
	// Lista todas las tareas
	void listarArchivo();
	// calcula la cantidad de archivos.
	int getCantidadArchivos();
	//Generar un id
	int generarID();
	//Cargar un archivo nuevo.
	void cargarArchivo();
	//Generar Reporte
	void generarReporte();

	//Retorna la descripción del código de la prioridad
	std::string getPrioridad(int);
	//Retorna la descripción del código del estado.
	std::string getEstado(int);

};

