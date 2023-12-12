#include "Ejercicio19.hpp"

int main()
{
  
    Binario arbolBB;
    int opc, valor;
    Num* nodoRaiz;

    do
    {
        cout << "\n1. Insertar \n2. Salir \n\tOpción: ";
        cin >> opc;

        switch (opc)
        {
        case 1:
            cout << "\tInserta un número: ";
            cin >> valor;
            arbolBB.CrearNodo(valor);
            nodoRaiz = arbolBB.ConsultarRaiz();
            arbolBB.Insertar(nodoRaiz);
            break;
        case 2:
            cout << "\n\n\t\t --- fin de la aplicación ---\n" << endl;
            break;
        default:
            cout << "\n\tERROR, opción incorrecta" << endl;
            break;
        }
    } while (opc != 2);
}

