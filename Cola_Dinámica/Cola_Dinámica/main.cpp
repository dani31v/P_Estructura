#include "Cola_Dinamica.hpp"

int main()
{
    string nvaFrase, fraseExtraida;
    int opc, resultado;
    Cola_Trailer objeto1;
    Trailer objeto2;
    

    do
    {
        cout << "\n1 Insertar   2 Extraer   3 Consultar  4 Mostrar   5 Salir: ";
        cin >> opc;
        switch (opc)
        {
        case 1:
            cout << "\tInserte la placa del trailer: ";
            cin >> objeto2.placa;
            cout << "Inserte el producto: ";
            cin >> objeto2.producto;
            resultado = objeto1.Insertar(objeto2.producto, objeto2.placa);
                break;
        case 2:
                fraseExtraida = objeto1.Extraer();
                if (fraseExtraida == "")
                    cout << "\n\tCola VACIA. No se extrajo nada" << endl;
                else
                    cout << "\n\tSe EXTRAJO la frase: " << fraseExtraida << endl;
                break;
        case 3:
                fraseExtraida = objeto1.Consultar();
                if (fraseExtraida == "")
                    cout << "\n\tCola VACIA." << endl;
                else
                    cout << "\n\tPróxima a extraer: " << fraseExtraida << endl;
                break;
        case 4:
            objeto1.Mostrar();
            break;
        case 5:
            break;
        default:
            cout << "\n\tERROR, opciÛn inv·lida" << endl;
            break;
        }
    } while (opc != 5);
}

