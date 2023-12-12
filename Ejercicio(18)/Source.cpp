#include "Ejercicio18.h"

int main() 
{
    string nueva, despuesDe, extraida;
    bool retorno;
    int opc;

    ListaDobleEnlace Palabras;

    do
    {
        cout << "\n 1 Insertar Inicio   2 Insertar Final   3 Insertar en Medio   4 Extraer Inicio   5 Extraer Final   6 Extraer en medio   7 Mostrar Inicio a Fin   8 Mostrar Fin a Inicio   9 Salir: ";
        cin >> opc;

        switch (opc)
        {
        case 1:
            cout << "Ingresa la palabra que deseas insertar al inicio: ";
            cin >> nueva;
            Palabras.InsertarInicio(nueva);
            cout << "\tOK. Se insertó al inicio.";
            break;
        case 2:
            cout << "Ingresa la palabra que deseas insertar al final: ";
            cin >> nueva;
            Palabras.InsertarFinal(nueva);
            cout << "\tOK. Se insertó al FINAL.";
            break;
        case 3:
            cout << "Ingresa la palabra que deseas insertar: ";
            cin >> nueva;
            cout << "Después de qué palabra deseas insertarla: ";
            cin >> despuesDe;
            retorno = Palabras.InsertarMedio(nueva, despuesDe);
            if (retorno == false)
                cout << "\tNO se encontró " << despuesDe << " NO se insertó" << endl;
            else
                cout << "\tOK. Se insertó después de '" << despuesDe << "'" << endl;
            break;
        case 4:
            extraida = Palabras.ExtraerInicio();
            if (extraida == "")
                cout << "\tLista VACÍA. No se extrajo nada" << endl;
            else
                cout << "\tSe extrajo " << extraida << " del INICIO" << endl;
            break;
        case 5:
            extraida = Palabras.ExtraerFinal();
            if (extraida == "")
                cout << "\tLista VACÍA. No se extrajo nada" << endl;
            else
                cout << "\tSe extrajo " << extraida << " del FINAL" << endl;
            break;
        case 6:
            extraida = Palabras.ExtraerMedio();
            if (extraida == "")
                cout << "\tNO se encontró la palabra después de la cual eliminar un nodo" << endl;
            else
                cout << "\tSe extrajo " << extraida << " después de la palabra especificada" << endl;
            break;
        case 7:
            Palabras.MostrarIF();
            break;
        case 8:
            Palabras.MostrarFI();
            break;
        case 9:
            return 0;
        default:
            cout << "\n \tERROR, opción inválida";
            break;
        }
    } while (opc != 9);

    return 0;
}
