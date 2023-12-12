#include "Almacen.h"

void main() {
	setlocale(LC_ALL, "");
	Almacen arbol;
	int opcion, codigo, aBuscar;
	string producto;
	bool loop = true;
	Numero* n_raiz = NULL, * encontrado = NULL;

	while (loop==true) {
		cout << "\n\t\t\tBIENVEIDO A ALMACENES MODERNOS, S.A." << endl;
		cout << "------------------------------------------------------------------------------------------" << endl;
		cout << "1. Insertar\t2. Preorden\t3. Mostrar\t4. Buscar\t5. Salir: ";
		cin >> opcion;
		if (opcion < 7)
			n_raiz = arbol.consultar_raiz();
		switch (opcion) {
		case 1:
			cout << "Nombre del producto: ";
			cin >> producto;			
			cout << "Código del producto: ";
			cin >> codigo;
			arbol.crear_nodo(codigo,producto);
			n_raiz = arbol.consultar_raiz();
			arbol.insertar(n_raiz);
			break;
		case 2:
			if (n_raiz == NULL) cout << "El árbol esta vacío" << endl;
			else
			{
				cout << endl;
				arbol.recorrer_preorden(n_raiz);
			}
			cout << endl << endl;
			break;
		case 3:
			if (n_raiz == NULL) cout << "El árbol esta vacío" << endl;
			else
			{
				cout << endl;
				arbol.mostrar(n_raiz, 0);
			}
			break;
		case 4:
			if (n_raiz == NULL)
				cout << "\tÁrbol vacío" << endl;
			else
			{
				cout << endl;
				cout << "\tCódigo del producto que buscas: ";
				cin >> aBuscar;
				encontrado = arbol.Buscar(n_raiz, aBuscar,0);
			}
			break;
		case 5:
			cout << "\n\t\t\tFIN DE LA APLICACIÓN" << endl;
			loop = false;
			break;
		default:
			cout << "\n\t\t\tOPCIÓN INVÁLIDA, VUELVA A INTENTAR" << endl;
			break;
		}
	}
}