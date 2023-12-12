#pragma once
#include <iostream>
using namespace std;

struct Nod;

struct Ady
{
	char nombre;
	int peso;
	Ady* adySig;
	Nod* dirNodo;
};
struct Nod
{
	char nombre;
	Nod* nodSig;
	Ady* adySig;
};


class ListaAdy
{
public:
	ListaAdy();
	~ListaAdy();
	int InsertarNodo(char nom);
	int InsertarArco(char ori, char des, int peso);
	int LocalizarNod(char nom, Nod*& posic);
	int LocalizarAdy(Nod* orig, char des, Ady*& posicAdy);
	void Mostrar();
	void RecorrerProfundidad();
	void RecorrerAncho();
	void InsertarPila(Nod* noddo);
	Nod* ExtraerPila();
	void InsertarCola(Nod* noddo);
	Nod* ExtraerCola();
private:
	Nod* nodo, * inicio, * auxNod;
	Ady* adyad, * auxAdy;
	int totalNodos, topePila, inicioCola, finCola;	/* Parámetros de la Pila y la Cola */
	Nod** pila, ** cola, ** visitados;	/* Apuntadores para 3 areglos de apuntadores,
										   uno para la Pila, otro para la Cola y otro
										   para los nodos visitados durante el recorrido */
};

