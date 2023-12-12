#pragma once
#include <iostream>
using namespace std;

struct Num
{
    Num* izquierdo;
    int num;
    Num* derecho;
};

class Binario
{
public:
    Binario();
    Num* ConsultarRaiz();
    void CrearNodo(int);
    void Insertar(Num*);
private:
    Num* raiz, * nodo;
};


