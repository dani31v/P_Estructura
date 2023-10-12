

#include "extraerlists.hpp"

int main(int argc, char const *argv[])
{
    ListaEnlazada Palabras;
    int opcion, retorno;
    string nuevaPalabra, palabra_anterior, extraida;

    do
    {
        cout << "\n1. Insertar Inicio 2. Insertar Final."
             << " 3. Insertar Intermedio 4.ExtraerInicio"
             << "    5. Extraer Final 6.Extraer Intermedio"
             << " 7.Mostrar 8. Salir\nOpción: ";
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
                extraida =Palabras.ExtraerInicio();
                if(extraida == "")
                    cout << "\tLista Vacía, No se extrajo nada";
                else
                    cout << "Se Extrajo: " << extraida << "del inicio" << endl;
                break;
            case 5:
                extraida=Palabras.ExtraerFinal();
                if(extraida == "")
                    cout << "\tLista Vacía, No se extrajo nada";
                else
                    cout << "Se extrajo " <<extraida << " correctamente" << endl;
                break;
            case 6:
                break;
                
        case 7:
                Palabras.Mostrar();
            break;
        case 8:
            cout << "\nSALIENDO..." << endl;
            break;
        default:
            cout << "\nOPCIÓN INVÁLIDA" << endl;
            break;
        }
    } while (opcion != 8);

    return 0;
}


