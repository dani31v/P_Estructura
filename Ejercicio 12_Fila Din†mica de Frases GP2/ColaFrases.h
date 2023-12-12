#pragma once
#include <iostream>
#include <string>
using namespace std;

struct Frase
{
	string dato;
	Frase* sig;
};
class ColaFrases
{
public:
	ColaFrases();
	string Consultar();
	string Extraer();
	void Insertar(string);
	void Mostrar();
private:
	Frase* inicio, * final, * nodo;
};

