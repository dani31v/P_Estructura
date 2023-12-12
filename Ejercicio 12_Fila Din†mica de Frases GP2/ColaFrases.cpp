#include "ColaFrases.h"

ColaFrases::ColaFrases()
{
	inicio = final = nodo = NULL;
}

string ColaFrases::Consultar()
{
	string sale;

	if (inicio == NULL)	/* Fila VACIA */
		return "";
	nodo = inicio;		/* Nodo apunta al nodo de inicio */
	sale = nodo->dato;	/* Se toman los datos de inicio */

	return sale;
}

string ColaFrases::Extraer()
{
	string sale;

	if (inicio == NULL)	/* Fila VACIA */
		return "";
	nodo = inicio;		/* Nodo apunta al nodo de inicio */
	sale = nodo->dato;	/* Se toman los datos de inicio */
	inicio = nodo->sig;	/* 'inicio´apunta al siguiente en la fila */
	if (inicio == NULL)	/* Si se extrajo el último nodo */
		final = NULL;	
	delete nodo;		/* Se libera el nodo extraído */
	return sale;

}

void ColaFrases::Insertar(string entra)
{
	nodo = new Frase;	/* Nodo nuevo */
	nodo->dato = entra;	/* Datos en nuevo nodo */
	nodo->sig = NULL;	/* Ultimo nodo a punta a NULL */
	if (inicio == NULL)
		inicio = nodo;	/* Solo con la primera inserción */
	if (final != NULL)
		final->sig = nodo; /* Excepto en la primera inserción */
	final = nodo;		/* ´final´apunta al nuevo nodo */
}

void ColaFrases::Mostrar()
{
	cout << "\nFILA de Frases:" << endl;
	if (inicio == NULL)
	{
		cout << "\n\tCola VACIA" << endl;
		return;
	}

	nodo = inicio;
	do
	{
		cout << "\t" << nodo->dato;
		if (nodo == inicio) cout << "\t<== inicio";
		if (nodo == final) cout << "\t<== final";
		cout << endl;

		nodo = nodo->sig;
	} while (nodo != NULL);
}
