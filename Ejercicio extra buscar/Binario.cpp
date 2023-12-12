#include "Binario.h"

Binario::Binario()
{
	raiz = nodo = NULL;
}

Numero* Binario::consultar_raiz()
{
	return raiz;
}

Numero* Binario::Buscar(Numero* inicio, int buscado)
{
	Numero* encontrado;
	if (buscado == inicio->num)		//Se encontró, está en la raíz
	{
		cout << "OK. Se encontró el " << buscado << endl;
		return inicio;
	}
	if (buscado < inicio->num)		//Menor. Se busca por la izquierda
	{
		if (inicio->izq != NULL)
		{
			encontrado = Buscar(inicio->izq, buscado);
			return encontrado;
		}
		else
		{
			cout << "\tNo existe " << buscado << endl;
			return NULL;
		}
	}
	if (buscado > inicio->num)		//Mayor. Se buesca por la derecha
	{
		if (inicio->der != NULL)
		{
			encontrado = Buscar(inicio->der, buscado);
			return encontrado;
		}
		else
		{
			cout << "\tNo existe " << buscado << endl;
			return NULL;
		}
	}
	
}

void Binario::crear_nodo(int valor)
{
	nodo = new Numero;
	nodo->num = valor;
	nodo->izq = NULL;
	nodo->der = NULL;
}

void Binario::insertar(Numero* inicio)
{
	if (!raiz) { //arbol vacio
		raiz = nodo;
		cout << "Se inserto en la raiz" << endl;
		return;
	}
	if (nodo->num < inicio->num) { //insertar izquierda
		if (inicio->izq == NULL) {
			inicio->izq = nodo;
			cout << "Se inserto a la izquierda de " << inicio->num << endl;
			return;
		}
		else {
			insertar(inicio->izq);
			return;
		}
	}
	if (nodo->num > inicio->num) { //insertar derecha
		if (inicio->der == NULL) {
			inicio->der = nodo;
			cout << "Se inserto a la derecha de " << inicio->num << endl;
			return;
		}
		else {
			insertar(inicio->der);
			return;
		}
	}
	//si es igual, no se inserta
	cout << "Ya existe el numero " << nodo->num << endl;
	delete nodo;
}

void Binario::recorrer_inorden(Numero* inicio)
{
	if (inicio->izq != NULL) recorrer_inorden(inicio->izq);
	cout << "\t" << inicio->num;
	if (inicio->der != NULL) recorrer_inorden(inicio->der);
}

void Binario::recorrer_preorden(Numero* inicio)
{
	cout << "\t" << inicio->num;
	if (inicio->izq != NULL) recorrer_preorden(inicio->izq);
	if (inicio->der != NULL) recorrer_preorden(inicio->der);
}

void Binario::recorrer_posorden(Numero* inicio)
{
	if (inicio->izq != NULL) recorrer_posorden(inicio->izq);
	if (inicio->der != NULL) recorrer_posorden(inicio->der);
	cout << "\t" << inicio->num;
}

void Binario::mostrar(Numero* inicio, int contador)
{
	if (inicio == NULL) return;
	mostrar(inicio->der, contador + 1);
	for (int i = 0; i < contador; i++) {
		cout << "\t";
	}
	cout << inicio->num << endl;
	mostrar(inicio->izq, contador + 1);
}