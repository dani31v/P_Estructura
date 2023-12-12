#include "Ejercicio19.hpp"

Binario::Binario()
{
    raiz = nodo = NULL;
}

Num* Binario::ConsultarRaiz()
{
    return raiz;
}

void Binario::CrearNodo(int valor)
{
    nodo = new Num;
    nodo->num = valor;
    nodo->izquierdo = NULL;
    nodo->derecho = NULL;
}

void Binario::Insertar(Num* inicio)
{
    if (!raiz) /* ¡rbol vacÌo. Se inserta en la raÌz */
    {
        raiz = nodo;
        cout << "\tSe insertó en la raíz" << endl;
        return;
    }
    if (nodo->num < inicio->num) /* Menor, se insertar· a la izquierda */
    {
        if (inicio->izquierdo == NULL)
        {
            inicio->izquierdo = nodo;
            cout << "\tSe insertó a la izquierda de " << inicio->num << endl;
            return;
        }
        else
        {
            Insertar(inicio->izquierdo);
            return;
        }
    }
    if (nodo->num > inicio->num) /* Mayor, se insertar· a la derecha */
    {
        if (inicio->derecho == NULL)
        {
            inicio->derecho = nodo;
            cout << "\tSe insertó a la derecha de " << inicio->num << endl;
            return;
        }
        else
        {
            Insertar(inicio->derecho);
            return;
        }
    }
    /* Si es igual, 0 se insertar· */
    cout << "\tYa existe " << nodo->num << " en el árbol. NO se insertar·" << endl;
    delete nodo;
}
