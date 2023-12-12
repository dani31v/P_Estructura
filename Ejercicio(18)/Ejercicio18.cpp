#include "Ejercicio18.h"

ListaDobleEnlace::ListaDobleEnlace()
{
	cabecera = final = nodo = NULL;
}

string ListaDobleEnlace::ExtraerInicio()
{
	string extraida;

    if (!cabecera)
        return ""; // Caso: Lista vacía. NO se extrae
    
    nodo = cabecera;
    extraida = nodo->dato;
    
    cabecera = cabecera->sig; // Paso 1

    if (cabecera == NULL)
        final = NULL; // Caso: 'Cabecera igual a final'
    else    
        cabecera->prev = NULL; // Paso 2
    
    delete nodo;

    return extraida;
}

string ListaDobleEnlace::ExtraerFinal()
{
	string extraida;

    if (!final)
        return ""; // Caso: Lista vacía. NO se extrae

    nodo = final;
    extraida = nodo->dato;

    final = final->prev; // Paso 1

    if (final == NULL)
        cabecera = NULL; // Caso: 'Final igual a cabecera'
    else
        final->sig = NULL; // Paso 2

    delete nodo;

    return extraida;
}

string ListaDobleEnlace::ExtraerMedio()
{
	string extraida;
    string eliminarDespuesDe;

    cout << "Ingresa la palabra después de la cual deseas eliminar un nodo: ";
    cin >> eliminarDespuesDe;

    if (!cabecera)
        return ""; // Caso: Lista vacía. NO se extrae

    nodo = cabecera;

    while (nodo != NULL)
    {
        if (nodo->dato == eliminarDespuesDe)
        {
            extraida = nodo->dato;
            if (nodo == cabecera)
            {
                cabecera = nodo->sig;
                cabecera->prev = NULL;
            }
            else if (nodo == final)
            {
                final = nodo->prev;
                final->sig = NULL;
            }
            else
            {
                nodo->prev->sig = nodo->sig;
                nodo->sig->prev = nodo->prev;
            }
            delete nodo;
            return extraida;
        }
        nodo = nodo->sig;
    }

    return ""; // No se encontró la palabra después de la cual eliminar un nodo

}

void ListaDobleEnlace::InsertarFinal(string nueva)
{
	if (cabecera == NULL)
    {
        InsertarInicio(nueva);
        return;
    }

    nodo = new Palabra; // Paso 1
	nodo->dato = nueva; // Paso 2
    nodo->sig = NULL; // Paso 3
    nodo->prev = final; // Paso 4
    final->sig = nodo; // Paso 5
    final = nodo; // Paso 6
}

void ListaDobleEnlace::InsertarInicio(string nueva)
{
	nodo = new Palabra; // Paso 1
	nodo->dato = nueva; // Paso 2
    nodo->sig = cabecera; // Paso 3
    nodo->prev = NULL; // Paso 4
    if (cabecera)
        cabecera->prev = nodo; // Paso 5
    else
        final = nodo;
    cabecera = nodo; // Paso 6

}

bool ListaDobleEnlace::InsertarMedio(string nueva, string despuesDe)
{
	Palabra* anterior;
    bool encontrada = false; // false = NO encontrada

    if (!cabecera)
        return false; // Caso: Lista vacía. No inserta
    
    anterior = cabecera;
    
    do // Paso 1: Localizar la posición
    {
        if (anterior->dato == despuesDe)
        {
            encontrada = true;
            break;
        }
        anterior = anterior->sig;
    } while (anterior != NULL);
    if (encontrada == false)
        return false; // Caso: NO encontró 'despuesDe', NO inserta
    
    if (anterior == false) // Caso: La encontró en el último nodo
    {
        InsertarFinal(nueva);
        return true;
    }

    nodo = new Palabra; // Paso 2
    nodo->dato = nueva; // Paso 3
    nodo->sig = anterior->sig; // Paso 4 
    nodo->prev = anterior; // Paso 5
    anterior->sig = nodo; // Paso 6
    nodo->sig->prev = nodo; // Paso 7

    return true; 
}

void ListaDobleEnlace::MostrarIF()
{
	if (!cabecera)
    {
        cout << "\n\tLista Vacía" << endl;
        return;
    }

    nodo = cabecera;
    cout << "\nLISTA DE PALABRAS" << endl;

    while (nodo != NULL)
    {
        cout << "\t" << nodo->dato;
        if (nodo == cabecera)
        {
            cout << "\nCabecera" << endl;
        }
        if (nodo == final)
        {
            cout << "\nFinal" << endl;
        }
        nodo = nodo->sig;
    }
}

void ListaDobleEnlace::MostrarFI()
{
    if (!final)
    {
        cout << "\n\tLista Vacía" << endl;
        return;
    }

    nodo = final;
    cout << "\nLISTA DE PALABRAS" << endl;

    while (nodo != NULL)
    {
        cout << "\t" << nodo->dato;
        if (nodo == final)
        {
            cout << "\nFinal" << endl;
        }
        if (nodo == cabecera)
        {
            cout << "\nCabecera" << endl;
        }
        nodo = nodo->prev;
    }
}
