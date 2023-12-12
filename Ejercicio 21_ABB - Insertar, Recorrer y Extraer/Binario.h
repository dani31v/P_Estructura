#pragma once
#include <iostream>
#include <string>
using namespace std;

struct Numero
{
	int valor;
	Numero* Izq;
	Numero* Der;
};
class Binario
{
public:
	Binario();
	~Binario();
	Numero* Iniciar();
	void CrearNodo(int);
	void Insertar(Numero*);
	void Mostrar(Numero*, int);
	void RecorrerINorden(Numero*);
	void RecorrerPREorden(Numero*);
	void RecorrerPOSorden(Numero*);
	void Extraer(Numero* padre, Numero* inicio, int valor, string subArbol);
	void Intercambiar(Numero* encontrado, Numero* actual, Numero* siguiente, string subArbol);
private:
	Numero* nodo, * raiz, * aux;
	string padreEnlace;
};


