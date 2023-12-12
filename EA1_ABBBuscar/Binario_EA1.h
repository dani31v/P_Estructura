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
    Binario(/* args */);
    Numero* ConsultarRaiz();
    void CrearNodo(int);
    void Insertar(Numero *);
    void Recorrer_INorden(Numero *);
    void Recorrer_PREorden(Numero *);
    void Recorrer_POSorden(Numero *);
    void Mostrar(Numero*, int);
    Numero* Buscar(Numero*, int);
private:
    Numero* raiz, * nodo;
};