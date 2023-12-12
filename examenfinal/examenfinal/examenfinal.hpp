#pragma once
#include <iostream>

using namespace std;

struct Numero
{
    Numero* izq;
    Numero* derecho;
    int numero;
    string producto;
};

class Almacen
{
public:
    Almacen();
    Numero* get_root();
    Numero* buscar(Numero*, int, int);
    void crear(int, string);
    void insertar(Numero*);
    void pre_orden(Numero*);
    void mostrar(Numero*, int);
private:
    Numero* raiz, * nodo;
};
