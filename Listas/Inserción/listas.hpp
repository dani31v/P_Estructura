#pragma once
#include <iostream>
using namespace std;

struct Palabra
{
    string dato;
    Palabra* siguiente;
};

class ListaEnlazada
{
public:
    ListaEnlazada(/* args */);
    void InsertarInicio(string);
    int InsertarInter(string, string);
    int InsertarFinal(string);
    void Mostrar();
private:
    Palabra* cabecera, *final, *nodo;
};
