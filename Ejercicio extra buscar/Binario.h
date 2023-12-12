#pragma once
#include <iostream>
using namespace std;

struct Numero {
	Numero* izq;
	Numero* der;
	int num;
};

class Binario
{
public:
	Binario();
	Numero* consultar_raiz();
	Numero* Buscar(Numero*, int);
	void crear_nodo(int);
	void insertar(Numero*);
	void recorrer_inorden(Numero*);
	void recorrer_preorden(Numero*);
	void recorrer_posorden(Numero*);
	void mostrar(Numero*, int);

private:
	Numero* raiz, * nodo;
};