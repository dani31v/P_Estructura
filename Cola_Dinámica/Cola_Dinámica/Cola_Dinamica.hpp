#include <iostream>
#pragma once
#include <string>
using namespace std;

struct Trailer
{
    int placa;
    string producto;
    Trailer* sig;
    
};
class Cola_Trailer
{
public:
    Cola_Trailer();
    string Consultar();
    string Extraer();
    int Insertar(string,int);
    void Mostrar();
private:
    Trailer* inicio, * final, * nodo;
};
