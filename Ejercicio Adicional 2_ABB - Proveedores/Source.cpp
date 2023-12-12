#include "Binario.h"

int main()
{
	setlocale(LC_ALL, "");

	Proveedor* nodoRaiz=NULL;
	Proveedor* encontrado;
	int id, opc, aConsultar;
	string nom;

	Binario ABB_prov;

	cout << "\n\t\t\tCATÁLOGO DE PROVEEDORES" << endl;

	do
	{
		cout << "\n\n1 Insertar  2 Consultar  " <<
			"3 Mostrar (in-orden)  4 Salir: ";
		cin >> opc;

		if(opc<4)
			nodoRaiz = ABB_prov.getRaiz();

		switch (opc)
		{
		case 1:
			cout << "\nInsertar proveedor: ";
			cout << "\tID (numérico): ";
			cin >> id;
			cout << "\tNombre: ";
			cin.ignore();
			getline(cin, nom);

			ABB_prov.CrearNodo(id,nom);

			ABB_prov.Insertar(nodoRaiz);
			break;
		case 2:
			if (!nodoRaiz)
				cout << "\n\tÁrbol Vacío" << endl;
			else
			{
				cout << "\tID del proveedor que consultas: ";
				cin >> aConsultar;

				encontrado = ABB_prov.Consultar(nodoRaiz, aConsultar);
				if (encontrado != NULL)
				{
					cout << "\nProveedor consultado:" << endl;
					cout << "\tID:\t" << encontrado->id << endl;
					cout << "\tNombre:\t" << encontrado->nombre << endl << endl;
				}
				else
					cout << "\n\t** NO existe el proveedor " << aConsultar << endl;
			}
			break;
		case 3:
			if (!nodoRaiz)
				cout << "\n\tÁrbol Vacío" << endl;
			else
			{
				cout << "\nCatálogo de Proveedores:" << endl;
				ABB_prov.Recorrer_inorden(nodoRaiz);
			}
			break;
		case 4:
			break;
		default:
			cout << "\n\t**ERROR, opción inválida" << endl << endl;
			break;
		}
	} while (opc != 4);
}