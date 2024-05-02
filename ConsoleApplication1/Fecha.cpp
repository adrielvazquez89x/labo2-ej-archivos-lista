#include "Fecha.h"

bool Fecha::validarDia(int dia, int mes, int anio)
{
	//Dia 0 o negativos
	if (dia < 1)
		return false;

	//Dias para los meses de 30
	for (int m : _meses30)
	{
		if (mes == m)
		{
			if (dia > 30)
				return false;
			else
				return true;
		}
	}

	//Dias para los meses e 31
	for (int m : _meses31)
	{
		if (m == mes)
		{
			if (dia > 31)
				return false;
			else
				return true;
		}
	}

	//Para febrero
	if (mes == _febrero)
	{
		if (validarBisiesto(anio))
		{
			if (dia > 29)
				return false;
			else
				return true;
		}
		else
		{
			if (dia > 28)
				return false;
			else
				return true;
		}
	}

	return false;
}

bool Fecha::validarMes(int mes)
{
	if (mes >= 1 && mes <= 12)
		return true;

	return false;
}

bool Fecha::validarAnio(int anio)
{
	if (anio >= 1900)
		return true;

	return false;
}

bool Fecha::validarBisiesto(int anio)
{
	if (anio % 400 == 0)
		return true;
	if (anio % 4 == 0 && anio % 100 != 0)
		return true;

	return false;
}

bool Fecha::saberDiasMes(int mes)
{
	for (int m : _meses30)
	{
		if (mes == m)
			return true;
	}

	return false;
}

void Fecha::aumentoMes()
{
	_dia = 1;
	_mes++;
}

void Fecha::decrementoMes()
{

}

void Fecha::RestarDia()
{
	_dia--;
	//Verificamos si cambio el mes:
	if (_dia == 0)
	{
		_mes--;

		if (_mes == _febrero)
		{
			if (validarBisiesto(_anio))
				_dia = 29;
			else
				_dia = 28;
		}
		if (saberDiasMes(_mes))
			_dia = 30;
		else
			_dia = 31;
	}
	if (_mes == 0)
	{
		_anio--;
		_mes = 12;
		_dia = 31;
	}

}

void Fecha::AgregarDia()
{
	//Aumenta el dia.
	_dia++;

	//Verificamos febrero.
	if (_mes == _febrero)
	{	//Verificamos bisiesto.
		if (validarBisiesto(_anio))
		{
			if (_dia == 30)
				aumentoMes();
		}
		else
		{
			if (_dia == 29)
				aumentoMes();

		}
	}

	if (saberDiasMes(_mes))
	{
		if (_dia == 31)
			aumentoMes();

	}
	else
	{
		if (_dia == 32)
			aumentoMes();
	}

	if (_mes == 13)
	{
		_anio++;
		_mes = 1;
		_dia = 1;
	}

}

Fecha::Fecha(int dia, int mes, int anio)
{
	int contador = 0;
	contador += (validarDia(dia, mes, anio) ? 1 : 0);
	contador += (validarMes(mes) ? 1 : 0);
	contador += (validarAnio(anio) ? 1 : 0);

	if (contador == 3) {
		_dia = dia;
		_mes = mes;
		_anio = anio;
	}
	else
	{
		_dia = 1;
		_mes = 1;
		_anio = 2023;
	}
}

Fecha::Fecha()
{
	_dia = 1;
	_mes = 1;
	_anio = 2023;
}

void Fecha::AgregarDias(int cantidad)
{
	if (cantidad == 0)
		return;
	if (cantidad > 0)
	{
		for (int x = 0; x < cantidad; x++)
		{
			AgregarDia();
		}
	}
	if (cantidad < 0)
	{
		for (int x = 0; x > cantidad; x--)
		{
			RestarDia();
		}
	}
}

std::string Fecha::toString()
{
	std::string dia = (getDia() < 10 ? "0" : "") + std::to_string(getDia());
	std::string mes = (getMes() < 10 ? "0" : "") + std::to_string(getMes());
	std::string anio = std::to_string(getAnio());
	return dia + "/" + mes + "/" + anio;
}


int Fecha::getDia()
{
	return _dia;
}

int Fecha::getMes()
{
	return _mes;
}

int Fecha::getAnio()
{
	return _anio;
}
