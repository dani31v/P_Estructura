#include "Binario.h"

void main()
{
  
    Binario arbolBB;
    int opc, valor;
    Numero* nodoRaiz = NULL;

    do
    {
        cout << "\n1. Insertar \n2. In-orden \n3. Pre-orden \n4. Pos-orden \n5. Salir \n\tOpciÛn: ";
        cin >> opc;

        if (opc < 5)
            nodoRaiz = arbolBB.ConsultarRaiz();

        switch (opc)
        {
        case 1:
            cout << "\tEntero que insertar·s: ";
            cin >> valor;
            arbolBB.CrearNodo(valor);
            arbolBB.Insertar(nodoRaiz);
            break;
        case 2:
            if (nodoRaiz == NULL)
                cout << "\tEl ·rbol est· vacÌo" << endl;
            else
                arbolBB.Recorrer_INorden(nodoRaiz);
            break;
        case 3:
            if (nodoRaiz == NULL)
                cout << "\tEl ·rbol est· vacÌo" << endl;
            else
                arbolBB.Recorrer_PREorden(nodoRaiz);
            break;
        case 4:
            if (nodoRaiz == NULL)
                cout << "\tEl ·rbol est· vacÌo" << endl;
            else
                arbolBB.Recorrer_POSorden(nodoRaiz);
            break;
        case 5:
            cout << "\n\n\t\t --- FINAL DE LA APLICACI”N ---\n" << endl;
            break;
        default:
            cout << "\n\tERROR, opciÛn inv·lida" << endl;
            break;
        }
    } while (opc != 5);
}

