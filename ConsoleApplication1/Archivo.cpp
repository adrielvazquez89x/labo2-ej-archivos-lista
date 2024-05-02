#define _CRT_SECURE_NO_WARNINGS 1
#include "Archivo.h"

Archivo::Archivo() : _prioridad{ "Baja","Media","Alta" }, _estado{ "Pendiente", "En curso", "Hecho"}{}

void Archivo::guardarArchivo(Tarea tarea)
{
	FILE* puntero;
	puntero = fopen("tareas.dat", "ab");
	if (puntero == nullptr)
	{
		std::cout << "ERROR ESCRITURA";
		return;
	}
	fwrite(&tarea, sizeof(Tarea), 1, puntero);
	fclose(puntero);
}

Tarea Archivo::leerArchivo(int id)
{
	Tarea aux;
	FILE* puntero = fopen("tareas.dat", "rb");
	if (puntero == nullptr)
	{
		std::cout << "ERROR LECTURA";
		return aux;
	}

	while (fread(&aux, sizeof(Tarea), 1, puntero))
	{
		if (aux.getID() == id)
			break;
	}
	fclose(puntero);
	
	return aux;
}

Tarea Archivo::leerArchivoIndice(int indice)
{
	Tarea aux;
	FILE* puntero = fopen("tareas.dat", "rb");
	if (puntero == nullptr)
	{
		return aux;
	}
	fseek(puntero, indice * sizeof(Tarea), SEEK_SET);

	fread(&aux, sizeof(Tarea), 1, puntero);
	fclose(puntero);
	return aux;
}

void Archivo::mostrarTarea(Tarea tarea)
{
	std::cout << "ID: " << tarea.getID() << std::endl;
	std::cout << "Descripcion : " << tarea.getDescripcion() << std::endl;
	std::cout << "Prioridad: " << getPrioridad(tarea.getPrioridad()) << std::endl;
	std::cout << "Fecha limite: " << tarea.getFecha().toString() << std::endl;
	std::cout << "Estado: " << getEstado(tarea.getEstado()) << std::endl;
}

void Archivo::listarArchivo()
{
	for (int x = 0; x < getCantidadArchivos(); x++)
	{
		mostrarTarea(leerArchivoIndice(x));
		std::cout << std::endl;
	}
}

int Archivo::getCantidadArchivos()
{
	int tamanio;
	FILE* puntero = fopen("tareas.dat", "rb");
	if (puntero == nullptr)
	{
		return 0;
	}
	fseek(puntero, 0, SEEK_END);
	tamanio = ftell(puntero);

	return tamanio /sizeof(Tarea) ;
}

int Archivo::generarID()
{
	int id = 0;
	FILE* puntero = fopen("contadorID", "rb+");
	if (puntero == nullptr)
	{
		puntero = fopen("contadorID", "wb");
		if (puntero == nullptr)
			return 0;
	
		id = 1;
		fwrite(&id, sizeof(int), 1, puntero);
		return id;
	}
	fread(&id, sizeof(int), 1, puntero);
	id++;
	fseek(puntero, 0, SEEK_SET);
	fwrite(&id, sizeof(int), 1, puntero);
	fclose(puntero);
	return id;

}

void Archivo::cargarArchivo()
{
	std::string desc;
	int p, e, dia, mes, anio;
	

	std::cout << "INGRESE DESCRIPCION: ";
	std::getline(std::cin, desc);
	std::cout << "INGRESE PRIRIDAD: (1  = BAJA, 2 = MEDIA, 3 = ALTA): ";
	std::cin >> p;
	std::cout << "INGRESE ESTADO: (1 = PENDIENTE, 2 = EN CURSO, 3 = HECHO): ";
	std::cin >> e;
	std::cout << "INGRESO FECHA " << std::endl;
	std::cout << "DIA: ";
	std::cin >> dia;
	std::cout << "MES: ";
	std::cin >> mes;
	std::cout << "ANIO: ";
	std::cin >> anio;

	Tarea aux(generarID(), desc, p, Fecha(dia, mes, anio), e);
	guardarArchivo(aux);
}

void Archivo::generarReporte()
{
	Tarea aux;
	int h = 0, eC = 0, p = 0;
	FILE* puntero = fopen("tareas.dat", "rb");
	if (puntero == nullptr)
	{
		std::cout << "ERROR LECTURA";
		return;
	}
	while (fread(&aux, sizeof(Tarea), 1, puntero)) {

		if (aux.getEstado() == 3)
			h++;
		if (aux.getEstado() == 2)
			eC++;
		if (aux.getEstado() == 1)
			p++;
	}
	fclose(puntero);
	std::cout << "REPORTE TAREAS: " << std::endl;
	std::cout << "PENDIENTE: " << p << std::endl;
	std::cout << "EN CURSO : " << eC << std::endl;
	std::cout << "HECHO: " << h << std::endl;


}

std::string Archivo::getPrioridad(int prioridad)
{
	return _prioridad[prioridad-1];
}

std::string Archivo::getEstado(int estado)
{
	return _estado[estado-1];
}
