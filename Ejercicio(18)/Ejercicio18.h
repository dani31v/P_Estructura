#pragma once
#include <iostream>
#include <string>
using namespace std;

struct Palabra
{
    Palabra* prev;
    string dato;
    Palabra * sig;
};

class ListaDobleEnlace
{
public:
    ListaDobleEnlace();
    string ExtraerInicio();
    string ExtraerFinal();
    string ExtraerMedio();
    void InsertarFinal(string);
    void InsertarInicio(string);
    bool InsertarMedio(string, string);
    void MostrarIF();
    void MostrarFI();
private:
    Palabra* cabecera, * final, * nodo;
};