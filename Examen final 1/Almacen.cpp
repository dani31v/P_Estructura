#include "Almacen.h"

Almacen::Almacen()
{
	raiz = nodo = NULL;
}

Numero* Almacen::consultar_raiz()
{
	return raiz;
}

Numero* Almacen::Buscar(Numero* inicio, int buscado, int nivel)
{
	Numero* encontrado;
	if (buscado == inicio->num)
	{
		cout << "OK. Se encontró el producto con código " << buscado << " y es " << inicio->prod << " en el nivel " << nivel << endl;
		return inicio;
	}
	if (buscado < inicio->num)
    
	{
		if (inicio->izq != NULL)
		{
			encontrado = Buscar(inicio->izq, buscado, nivel + 1);
			return encontrado;
		}
		else
		{
			cout << "\tNo existe el producto con código " << buscado << " en el nivel " << nivel << endl;
			return NULL;
		}
	}
	if (buscado > inicio->num)
	{
		if (inicio->der != NULL)
		{
			encontrado = Buscar(inicio->der, buscado, nivel + 1);
			return encontrado;
		}
		else
		{
			cout << "\tNo existe el producto con código " << buscado << " en el nivel " << nivel << endl;
			return NULL;
		}
	}
}


void Almacen::crear_nodo(int codigo,string producto)
{
	nodo = new Numero;
	nodo->num = codigo;
	nodo->prod = producto;
	nodo->izq = NULL;
	nodo->der = NULL;
}

void Almacen::insertar(Numero* inicio)
{
	if (!raiz) {
		raiz = nodo;
		cout << "Se inserto en la raiz" << endl;
		return;
	}
	if (nodo->num < inicio->num) {
		if (inicio->izq == NULL) {
			inicio->izq = nodo;
			cout << "Se inserto a la izquierda del producto " << inicio->prod << endl;
			return;
		}
		else {
			insertar(inicio->izq);
			return;
		}
	}
	if (nodo->num > inicio->num) {
		if (inicio->der == NULL) {
			inicio->der = nodo;
			cout << "Se inserto a la derecha del producto " << inicio->prod << endl;
			return;
		}
		else {
			insertar(inicio->der);
			return;
		}
	}
	cout << "Ya existe el producto con código " << nodo->num << endl;
	delete nodo;
}

void Almacen::recorrer_preorden(Numero* inicio)
{
	cout << "\t" << inicio->num<<"	"<<inicio->prod;
	if (inicio->izq != NULL) recorrer_preorden(inicio->izq);
	if (inicio->der != NULL) recorrer_preorden(inicio->der);
}

void Almacen::mostrar(Numero* inicio, int contador)
{
	if (inicio == NULL) return;
	mostrar(inicio->der, contador + 1);
	for (int i = 0; i < contador; i++) {
		cout << "\t";
	}
	cout << inicio->num << "	"<< inicio->prod << endl;
	mostrar(inicio->izq, contador + 1);
}
