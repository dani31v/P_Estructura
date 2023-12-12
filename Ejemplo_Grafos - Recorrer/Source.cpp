#include "ListaAdy.h" 

void cargaInicial(ListaAdy&);
void cargaInicial_2(ListaAdy&);

void main()
{
	int opc, peso, resulta;
	char nodo, orig, dest;

	ListaAdy grafo;

	cargaInicial(grafo);
//	cargaInicial_2(grafo);

	do
	{
		cout << "\n1 Insertar Nodo  2 Insertar Arco  3 Mostrar" << endl;
		cout << "                   4 Recorrer Profundidad  5 Recorrer Ancho  6 Salir: ";
		cin >> opc;
		switch (opc)
		{
		case 1:
			cout << "Que nodo quieres insertar (una letra): ";
			cin >> nodo;
			resulta = grafo.InsertarNodo(nodo);
			if (resulta == 0)
				cout << "\tOK. Se agrego nodo" << endl << endl;
			if (resulta == -1)
				cout << "\t%*YA EXISTE EL NODO. NO se inserto el nodo" << endl << endl;
			break;
		case 2:
			cout << "\tNodo origen (una letra): ";
			cin >> orig;
			cout << "\tNodo destino (una letra): ";
			cin >> dest;
			cout << "\tPeso del Arco: ";
			cin >> peso;

			resulta = grafo.InsertarArco(orig, dest, peso);		// Inserta ARCO Orig - Dest
			if (resulta == 0)
				cout << "\tOK. Se agrego el Arco " << orig << dest << endl << endl;
			if (resulta == -1)
				cout << "\t%*ERROR, NO existe el Nodo de origen o el Nodo de destino" << endl;
			if (resulta == -2)
				cout << "\t%*ERROR, YA existe el Arco. NO se inserto" << endl;

			resulta = grafo.InsertarArco(dest, orig, peso);		// Inserta ARCO Dest - Orig
			if (resulta == 0)
				cout << "\tOK. Se agrego el Arco " << dest << orig << endl << endl;
			if (resulta == -1)
				cout << "\t%*ERROR, NO existe el Nodo de origen o el Nodo de destino" << endl;
			if (resulta == -2)
				cout << "\t%*ERROR, YA existe el Arco. NO se inserto" << endl;
			break;
		case 3:
			grafo.Mostrar();
			break;
		case 4:
			grafo.RecorrerProfundidad();
			break;
		case 5:
			grafo.RecorrerAncho();
			break;
		default:
			break;
		}
	} while (opc < 6);


	cout << endl;
}
void cargaInicial(ListaAdy& grafo)
{
	grafo.InsertarNodo('H');
	grafo.InsertarNodo('A');
	grafo.InsertarNodo('D');
	grafo.InsertarNodo('B');
	grafo.InsertarNodo('C');
	grafo.InsertarNodo('G');
	grafo.InsertarNodo('F');
	grafo.InsertarNodo('E');

	grafo.InsertarArco('H', 'A', 10);
	grafo.InsertarArco('H', 'F', 9);
	grafo.InsertarArco('H', 'B', 6);
	grafo.InsertarArco('H', 'G', 3);
	grafo.InsertarArco('H', 'D', 14);
	grafo.InsertarArco('A', 'C', 5);
	grafo.InsertarArco('A', 'B', 3);
	grafo.InsertarArco('A', 'D', 2);
	grafo.InsertarArco('A', 'H', 10);
	grafo.InsertarArco('D', 'H', 14);
	grafo.InsertarArco('D', 'A', 2);
	grafo.InsertarArco('D', 'B', 8);
	grafo.InsertarArco('D', 'E', 12);
	grafo.InsertarArco('B', 'D', 8);
	grafo.InsertarArco('B', 'H', 6);
	grafo.InsertarArco('B', 'A', 3);
	grafo.InsertarArco('B', 'C', 5);
	grafo.InsertarArco('B', 'E', 4);
	grafo.InsertarArco('B', 'G', 6);
	grafo.InsertarArco('C', 'A', 5);
	grafo.InsertarArco('C', 'B', 5);
	grafo.InsertarArco('C', 'G', 9);
	grafo.InsertarArco('C', 'E', 1);
	grafo.InsertarArco('C', 'F', 7);
	grafo.InsertarArco('G', 'H', 3);
	grafo.InsertarArco('G', 'B', 6);
	grafo.InsertarArco('G', 'C', 9);
	grafo.InsertarArco('G', 'E', 15);
	grafo.InsertarArco('E', 'G', 15);
	grafo.InsertarArco('E', 'D', 12);
	grafo.InsertarArco('E', 'B', 4);
	grafo.InsertarArco('E', 'C', 1);
	grafo.InsertarArco('F', 'H', 9);
	grafo.InsertarArco('F', 'C', 7);
}
void cargaInicial_2(ListaAdy& grafo)
{
	grafo.InsertarNodo('G');
	grafo.InsertarNodo('E');
	grafo.InsertarNodo('J');
	grafo.InsertarNodo('B');
	grafo.InsertarNodo('A');
	grafo.InsertarNodo('C');
	grafo.InsertarNodo('H');
	grafo.InsertarNodo('F');
	grafo.InsertarNodo('I');
	grafo.InsertarNodo('D');

	grafo.InsertarArco('G', 'E', 1);
	grafo.InsertarArco('G', 'J', 1);
	grafo.InsertarArco('E', 'G', 1);
	grafo.InsertarArco('E', 'B', 1);
	grafo.InsertarArco('E', 'A', 1);
	grafo.InsertarArco('E', 'C', 1);
	grafo.InsertarArco('E', 'H', 1);
	grafo.InsertarArco('J', 'G', 1);
	grafo.InsertarArco('J', 'H', 1);
	grafo.InsertarArco('J', 'F', 1);
	grafo.InsertarArco('B', 'E', 1);
	grafo.InsertarArco('B', 'A', 1);
	grafo.InsertarArco('B', 'C', 1);
	grafo.InsertarArco('A', 'E', 1);
	grafo.InsertarArco('A', 'B', 1);
	grafo.InsertarArco('A', 'H', 1);
	grafo.InsertarArco('C', 'E', 1);
	grafo.InsertarArco('C', 'B', 1);
	grafo.InsertarArco('C', 'D', 1);
	grafo.InsertarArco('C', 'F', 1);
	grafo.InsertarArco('H', 'E', 1);
	grafo.InsertarArco('H', 'J', 1);
	grafo.InsertarArco('H', 'I', 1);
	grafo.InsertarArco('H', 'A', 1);
	grafo.InsertarArco('F', 'J', 1);
	grafo.InsertarArco('F', 'C', 1);
	grafo.InsertarArco('I', 'H', 1);
	grafo.InsertarArco('D', 'C', 1);
}