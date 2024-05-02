#pragma once
#include <iostream>
#include <cstdlib>
#include <string>

class Fecha
{
private:
	//Atributos
	int _dia;
	int _mes;
	int _anio;

	int _meses30[4] = { 4,6,9,11 };
	int _meses31[7] = { 1,3,5,7,8,10,12 };
	int _febrero = 2;

	//Validaciones
	bool validarDia(int, int, int);
	bool validarMes(int);
	bool validarAnio(int);
	bool validarBisiesto(int);

	//Auxiliares
	bool saberDiasMes(int);
	void aumentoMes();
	void decrementoMes();

	//Comportamiento
	void AgregarDia();
	void RestarDia();

public:
	//Constructor
	Fecha(int, int, int);
	Fecha();

	//M?todos
	void AgregarDias(int);
	std::string toString();
	//Getters
	int getDia();
	int getMes();
	int getAnio();

};

