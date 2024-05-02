#pragma once
#include <string>
#include "Fecha.h"

class Tarea
{
protected:
	int _ID;
	char _descripcion[100];
	int _prioridad;
	Fecha _fechaLimte;
	int _estado;
	

public:

	//Constructor:
	Tarea(int id = -1,
		std::string desc = "",
		int prioridad = 1,
		Fecha fecha = Fecha(1, 1, 2024),
		int estado = 1);

	//Getters
	int getID();
	std::string getDescripcion();
	int getPrioridad();
	Fecha getFecha();
	int getEstado();

	//Setters
	void setID(int);
	void setDescripcion(std::string);
	void setPrioridad(int);
	void setFecha(Fecha);
	void setEstado(int);

	//Archivo
	void guardarArchivo(Tarea);
};

