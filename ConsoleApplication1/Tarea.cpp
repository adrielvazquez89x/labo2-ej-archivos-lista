#define _CRT_SECURE_NO_WARNINGS 1
#include "Tarea.h"
#include <cstring>

Tarea::Tarea(int id,
	std::string desc,
	int prioridad,
	Fecha fecha,
	int estado)
{
	setID(id);
	setDescripcion(desc);
	setPrioridad(prioridad);
	setFecha(fecha);
	setEstado(estado);
}

//GETTERS
int Tarea::getID()
{
	return _ID;
}

std::string Tarea::getDescripcion()
{
	return _descripcion;
}

int Tarea::getPrioridad()
{
	return _prioridad;
}

Fecha Tarea::getFecha()
{
	return _fechaLimte;
}

int Tarea::getEstado()
{
	return _estado;
}

//SETTERS
void Tarea::setID(int id)
{
	if (id < 0)
		_ID = -1;
	else
		_ID = id;
}

void Tarea::setDescripcion(std::string desc)
{
	if (desc.length() > 50)
		strcpy(_descripcion, "La descripción fue muy larga hermano");
	else 
		strcpy(_descripcion, desc.c_str());
	
}

void Tarea::setPrioridad(int prioridad)
{
	if (prioridad < 1 && prioridad > 3)
		_prioridad = 1;
	else
		_prioridad = prioridad;
}

void Tarea::setFecha(Fecha fecha)
{
	_fechaLimte = fecha;
}

void Tarea::setEstado(int estado)
{
	if (estado < 1 && estado > 3)
		_estado = 1;
	else
		_estado = estado;
}

void Tarea::guardarArchivo(Tarea tarea)
{
	FILE* puntero;
	puntero = fopen("tareas.dat", "ab");
	if (puntero == nullptr)
	{
		std::cout << "ERROR ESCRITURA";
		return;
	}
	fwrite(&tarea, sizeof(Tarea), 1, puntero);
}

