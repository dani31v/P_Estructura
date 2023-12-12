
#include "arboles.hpp"

Binario::Binario()
{
    raiz = nodo = NULL;
}

Numero* Binario::ConsultarRaiz()
{
    return raiz;
}

void Binario::CrearNodo(int valor)
{
    nodo = new Numero;
    nodo->num = valor;
    nodo->Izq = NULL;
    nodo->Der = NULL;
}

void Binario::Insertar(Numero* inicio)
{
    if (!raiz) /* ¡rbol vacÌo. Se inserta en la raÌz */
    {
        raiz = nodo;
        cout << "\tSe insertÛ en la raÌz" << endl;
        return;
    }
    if (nodo->num < inicio->num) /* Menor, se insertar· a la izquierda */
    {
        if (inicio->Izq == NULL)
        {
            inicio->Izq = nodo;
            cout << "\tSe insertÛ a la izquierda de " << inicio->num << endl;
            return;
        }
        else
        {
            Insertar(inicio->Izq);
            return;
        }
    }
    if (nodo->num > inicio->num) /* Mayor, se insertar· a la derecha */
    {
        if (inicio->Der == NULL)
        {
            inicio->Der = nodo;
            cout << "\tSe insertÛ a la derecha de " << inicio->num << endl;
            return;
        }
        else
        {
            Insertar(inicio->Der);
            return;
        }
    }
    /* Si es igual, 0 se insertar· */
    cout << "\tYA existe " << nodo->num << " en el ·rbol. NO se insertar·" << endl;
    delete nodo;
}

void Binario::Recorrer_INorden(Numero* inicio)
{
    if (inicio->Izq != NULL) Recorrer_INorden(inicio->Izq);
    cout << "\t" << inicio->num;
    if (inicio->Der != NULL) Recorrer_INorden(inicio->Der);
}

void Binario::Recorrer_PREorden(Numero* inicio)
{
    cout << "\t" << inicio->num;
    if (inicio->Izq != NULL) Recorrer_PREorden(inicio->Izq);
    if (inicio->Der != NULL) Recorrer_PREorden(inicio->Der);
}

void Binario::Recorrer_POSorden(Numero* inicio)
{
    if (inicio->Izq != NULL) Recorrer_POSorden(inicio->Izq);
    if (inicio->Der != NULL) Recorrer_POSorden(inicio->Der);
    cout << "\t" << inicio->num;
}
