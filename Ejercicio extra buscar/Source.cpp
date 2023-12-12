#include "Binario.h"

void main() {
	Binario arbol;
	int opcion, valor, aBuscar;
	bool corre = true;
	Numero* n_raiz = NULL, *encontrado=NULL;

	while (corre) {
		cout << "1. Insertar\t2. Inorden\t3. Preorden\t4. Posorden\t5. Mostrar\t6. Buscar\t7. Salir: ";
		cin >> opcion;
		if (opcion < 7)
			n_raiz = arbol.consultar_raiz();
		switch (opcion) {
		case 1:
			cout << "Valor a insertar: ";
			cin >> valor;
			arbol.crear_nodo(valor);
			n_raiz = arbol.consultar_raiz();
			arbol.insertar(n_raiz);
			break;
		case 2:
			if (n_raiz == NULL) cout << "El arbol esta vacio" << endl;
			else arbol.recorrer_inorden(n_raiz);
			cout << endl<<endl;
			break;
		case 3:
			if (n_raiz == NULL) cout << "El arbol esta vacio" << endl;
			else arbol.recorrer_preorden(n_raiz);
			cout << endl<<endl;
			break;
		case 4:
			if (n_raiz == NULL) cout << "El arbol esta vacio" << endl;
			else arbol.recorrer_posorden(n_raiz);
			cout << endl<<endl;
			break;
		case 5:
			if (n_raiz == NULL) cout << "El arbol esta vacio" << endl;
			else arbol.mostrar(n_raiz, 0);
			break;
		case 6:
			if (n_raiz == NULL)
				cout << "\tÁrbol vacío" << endl;
			else
			{
				cout << "\tNúmero que buscas: ";
				cin >> aBuscar;
				encontrado = arbol.Buscar(n_raiz, aBuscar);
				if (encontrado != NULL)
				{
					cout << "\tSub-arbol IN-orden: " << endl;
					arbol.recorrer_inorden(encontrado);
					cout << endl << endl;
				}
			}
			break;
		case 7:
			cout << "-- Fin --" << endl;
			corre = false;
			break;
		default:
			cout << "Opcion invalida" << endl;
			break;
		}
	}
}