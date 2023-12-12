#pragma once
#include <iostream>
using namespace std;

struct Numero {
	Numero* izq;
	Numero* der;
	int num;
	string prod;
};

class Almacen
{
public:
	Almacen();
	Numero* consultar_raiz();
	Numero* Buscar(Numero*, int,int);
	void crear_nodo(int, string);
	void insertar(Numero*);
	void recorrer_preorden(Numero*);
	void mostrar(Numero*, int);

private:
	Numero* raiz, * nodo;
};