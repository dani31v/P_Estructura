/* Aplicación que implemente la operación INSERTAR en una LISTA ENLAZADA de palabras.
Debe de existir la posibilidad de insertar al principio, al final o intermedio.
También se pude la opción de mostrar la lista completa.
*/

#include "listas.hpp"

int main(int argc, char const *argv[])
{
    ListaEnlazada Palabras;
    int opcion, retorno;
    string nuevaPalabra, palabra_anterior;

    do
    {
        cout << "\n1. Insertar Inicio 2. Insertar Final. 3. Insertar Intermedio 4. Mostrar 5. Salir\nOpción: ";
        cin >> opcion;

        if(opcion < 4 && opcion > 0)
        {
            cout << "\tPalabra que insertarás: ";
            cin >> nuevaPalabra;
        }

        switch (opcion)
        {
        case 1:
            Palabras.InsertarInicio(nuevaPalabra);
            cout << "\tInserción CORRECTA" << endl;
            break;
        case 2:
                retorno = Palabras.InsertarFinal(nuevaPalabra);
                if(retorno==-1)
                
                    cout << "\t Lista Vacía.Se insertó al inicio" << endl;
                else
                    cout << "Se insertó correctamente al inicio" << endl;
                
            break;
        case 3:
                cout << "Despues de que palabra: " << endl;
                cin >> palabra_anterior;
               retorno= Palabras.InsertarInter(nuevaPalabra, palabra_anterior);
                if(retorno==-1)
                
                    cout << "\t Lista Vacía.Se insertó al inicio" << endl;
                else if (retorno == -2)
                    cout << "\tPalabra anterior no encontrada. Se insertó al final"<< endl;
                
                else
                    cout << "Se insertó correctamente al inicio" << endl;
                
            break;
        case 4:
                Palabras.Mostrar();
            break;
        case 5:
            cout << "\nSALIENDO..." << endl;
            break;
        default:
            cout << "\nOPCIÓN INVÁLIDA" << endl;
            break;
        }
    } while (opcion != 5);

    return 0;
}

