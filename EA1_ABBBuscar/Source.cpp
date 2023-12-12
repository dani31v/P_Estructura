/* Aplicación que, en un Árbol Binario de Búsqueda de números enteros, busque un número
dado y muestre in-orden el subárbol que tiene como raíz el número buscado.
*/

#include "Binario_EA1.h"

int main(int argc, char const *argv[])
{
    Binario arbolBB;
    int opc, valor, aBuscar;
    Numero* encontrado, * nodoRaiz = NULL;

    do
    {
        cout << "\n1. Insertar   2. In-orden   3. Pre-orden   4. Pos-orden   5. Mostrar";
        cout << "\n6. Buscar     7. Salir\nOpción: ";
        cin >> opc;
        
        if(opc < 7 && opc > 0)
            nodoRaiz = arbolBB.ConsultarRaiz();

        switch (opc)
        {
        case 1:
            cout << "\tEntero que insertarás: ";
            cin >> valor;
            arbolBB.CrearNodo(valor);
            arbolBB.Insertar(nodoRaiz);
            break;
        case 2:
            if(nodoRaiz == NULL)
                cout << "\tÁrbol VACÍO" << endl;
            else
                arbolBB.Recorrer_INorden(nodoRaiz);
            break;
        case 3:
            if(nodoRaiz == NULL)
                cout << "\tÁrbol VACÍO" << endl;
            else
                arbolBB.Recorrer_PREorden(nodoRaiz);
            break;
        case 4:
            if(nodoRaiz == NULL)
                cout << "\tÁrbol VACÍO" << endl;
            else
                arbolBB.Recorrer_POSorden(nodoRaiz);
            break;
        case 5:
            if(nodoRaiz == NULL)
                cout << "\tÁrbol VACÍO" << endl;
            else
                arbolBB.Mostrar(nodoRaiz, 0);
            break;
        case 6:
            if(nodoRaiz == NULL)
                cout << "\tÁrbol VACÍO" << endl;
            else
            {
                cout << "\tNúmero que buscas: ";
                cin >> aBuscar;
                encontrado = arbolBB.Buscar(nodoRaiz, aBuscar);
                if (encontrado != NULL)
                {
                    cout << "\tRecorrido IN-orden:" << endl;
                    arbolBB.Recorrer_INorden(encontrado);
                }
            }
            break;
        case 7:
            cout << "\n\t--- FINAL DE LA APLICACIÓN ---" << endl;
            break;
        default:
            cout << "\n\tOpción INVÁLIDA" << endl;
            break;
        }
    } while (opc != 7);
    
    return 0;
}