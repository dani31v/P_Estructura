#pragma once
#include <iostream>
using namespace std;

class MatrizAdy
{
public:
	MatrizAdy(int);
	int InsertarNodo(char);
	int InsertarArco(char, char, int);
	void Mostrar();
private:
	int BuscarNodo(char);
	char* nodos;
	int** arcos;
	int maxNodos, ocupados, posiOri, posiDes;
};

 