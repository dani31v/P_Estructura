#pragma once
#include <iostream>
#include <string>
using namespace std;

struct Turnos
{
	string turno;
	Turnos* siguiente;
};

class Cajas
{
public:
	Cajas(string);
	~Cajas();
	void Insertar(string turnoNuevo);
	string Extraer();
	void Mostrar();
private:
	Turnos* principio, * fin, * nodo;
	string nomCaja;
};
