#pragma once
#include <iostream>
using namespace std;

struct Numero
{
	Numero* Izq;
	int num;
	Numero* Der;
};

class Binario
{
public:
	Binario();
	Numero* ConsultarRaiz();
	void CrearNodo(int);
	void Insertar(Numero*);
	void Recorrer_INorden(Numero*);
	void Recorrer_PREorden(Numero*);
	void Recorrer_POSorden(Numero*);
private:
	Numero* raiz, * nodo;
};

