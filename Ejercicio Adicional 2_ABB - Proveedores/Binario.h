#pragma once
#include <iostream>
#include <string>
using namespace std;

struct Proveedor
{
	Proveedor* izq;
	int id;
	string nombre;
	Proveedor* der;
};

class Binario
{
public:
	Binario();
	~Binario();
	void CrearNodo(int,string);
	Proveedor* getRaiz();
	void Insertar(Proveedor*);
	void Recorrer_inorden(Proveedor*);

	Proveedor* Consultar(Proveedor*, int);

private:
	Proveedor* raiz, * nodo;
};


