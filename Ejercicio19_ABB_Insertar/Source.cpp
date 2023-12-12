#include "Binario.h"

void main()
{
	setlocale(LC_ALL, "");
	Binario arbolBB;
	int opc, valor;
	Numero* nodoRaiz;

	do
	{
		cout << "\n1. Insertar \n2. Salir \n\tOpción: ";
		cin >> opc;

		switch (opc)
		{
		case 1:
			cout << "\tEntero que insertarás: ";
			cin >> valor;
			arbolBB.CrearNodo(valor);
			nodoRaiz = arbolBB.ConsultarRaiz();
			arbolBB.Insertar(nodoRaiz);
			break;
		case 2:
			cout << "\n\n\t\t --- FINAL DE LA APLICACIÓN ---\n" << endl;
			break;
		default:
			cout << "\n\tERROR, opción inválida" << endl;
			break;
		}
	} while (opc != 2);
}