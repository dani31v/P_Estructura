#include "Binario.h"

void main()
{
	setlocale(LC_ALL, "");
	Binario arbolBB;
	int opc, valor;
	Numero* nodoRaiz;

	do
	{
		cout << "\n1. Insertar \n2. Salir \n\tOpci�n: ";
		cin >> opc;

		switch (opc)
		{
		case 1:
			cout << "\tEntero que insertar�s: ";
			cin >> valor;
			arbolBB.CrearNodo(valor);
			nodoRaiz = arbolBB.ConsultarRaiz();
			arbolBB.Insertar(nodoRaiz);
			break;
		case 2:
			cout << "\n\n\t\t --- FINAL DE LA APLICACI�N ---\n" << endl;
			break;
		default:
			cout << "\n\tERROR, opci�n inv�lida" << endl;
			break;
		}
	} while (opc != 2);
}