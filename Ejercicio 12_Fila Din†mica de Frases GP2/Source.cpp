#include "ColaFrases.h"

void main()
{
	string nvaFrase, fraseExtraida;
	int opc, resultado;

	setlocale(LC_ALL, "");

	ColaFrases misFrases;

	do
	{
		cout << "\n1 Insertar   2 Extraer   3 Consultar  4 Mostrar   5 Salir: ";
		cin >> opc;
		switch (opc)
		{
		case 1:
			cout << "\t¿Qué frase insertas?: ";
			cin.ignore();
			getline(cin,nvaFrase);
			misFrases.Insertar(nvaFrase);
			cout << "\n\tOK. Se insertó la frase" << endl;
			break;
		case 2:
			fraseExtraida = misFrases.Extraer();
			if (fraseExtraida == "")
				cout << "\n\tCola VACIA. No se extrajo nada" << endl;
			else
				cout << "\n\tSe EXTRAJO la frase: " << fraseExtraida << endl;
			break;
		case 3:
			fraseExtraida = misFrases.Consultar();
			if (fraseExtraida == "")
				cout << "\n\tCola VACIA." << endl;
			else
				cout << "\n\tPróxima a extraer: " << fraseExtraida << endl;
			break;
		case 4:
			misFrases.Mostrar();
			break;
		case 5:
			break;
		default:
			cout << "\n\tERROR, opción inválida" << endl;
			break;
		}
	} while (opc != 5);
}