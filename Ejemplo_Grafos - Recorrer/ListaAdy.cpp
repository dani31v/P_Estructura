#include "ListaAdy.h" 

ListaAdy::ListaAdy()
{
	inicio = NULL;
	totalNodos = 0;
	topePila = -1;
	inicioCola = -1;
	finCola = -1;
}

ListaAdy::~ListaAdy()
{
}

int ListaAdy::InsertarNodo(char nom)
{
	Nod* posic = NULL;
	int existe;

	nodo = new Nod;				// Crea nuevo nodo e inicia sus campos
	nodo->nombre = nom;
	nodo->nodSig = NULL;
	nodo->adySig = NULL;

	if (!inicio)				// Inserta nodo, si la lista de nodos está vacía
	{
		inicio = nodo;
		totalNodos++;
		return 0;
	}

	existe = LocalizarNod(nom, posic);	// Localiza dirección del nodo "nom", o bien, si no existe "nom", el nodo final de la lista

	if (existe == 0)				// No existe el nodo "nom" y lo inserta al final de la lista de nodos
	{
		posic->nodSig = nodo;
		totalNodos++;
		return 0;
	}
	else						// YA existe el nodo "nom" y NO lo inserta
	{
		delete nodo;
		return -1;
	}
}
int ListaAdy::InsertarArco(char ori, char des, int peso)
{
	Nod* posicOri = NULL, * posicDes = NULL;
	Ady* posicAdy = NULL;
	int existeOri, existeDes, existeArco;

	adyad = new Ady;			// Crea nuevo arco e inicia sus campos
	adyad->nombre = des;
	adyad->peso = peso;
	adyad->adySig = NULL;

	if (!inicio)
		return -1;				// Lista Vacía, NO se insertó el arco

	existeOri = LocalizarNod(ori, posicOri);	// Revisa si existe nodo "ori" y su dirección
	existeDes = LocalizarNod(des, posicDes);	// Revisa si existe nodo "des"

	if (existeOri == 0 || existeDes == 0)
	{
		delete adyad;
		return -1;				// No existe nodo origen o nodo destino, NO se inserta arco
	}

	if (!posicOri->adySig)		// Inserta arco, si la lista de adyacencias desde "ori" está vacía
	{
		posicOri->adySig = adyad;
		adyad->dirNodo = posicDes;
		return 0;
	}

	existeArco = LocalizarAdy(posicOri, des, posicAdy);	// Desde nodo "ori" localiza dirección de adyacencia "des" o adyacencia final de la lista
	if (existeArco == -1)
	{
		delete adyad;
		return -2;				// YA existe el arco, NO se insertó
	}
	posicAdy->adySig = adyad;	// No existe el arco y lo inserta al final de la lista de adyacencias desde "ori"
	adyad->dirNodo = posicDes;

	return 0;
}
int ListaAdy::LocalizarNod(char nom, Nod*& posic)
{
	auxNod = inicio;
	do
	{
		posic = auxNod;
		if (auxNod->nombre == nom)
			return -1;			// YA existe el nodo "nom"
		auxNod = auxNod->nodSig;
	} while (auxNod);

	return 0;					// NO existe el nodo "nom"
}
int ListaAdy::LocalizarAdy(Nod* orig, char des, Ady*& posicAdy)
{
	auxAdy = orig->adySig;
	do
	{
		posicAdy = auxAdy;
		if (auxAdy->nombre == des)
			return -1;			// YA existe el arco
		auxAdy = auxAdy->adySig;
	} while (auxAdy);

	return 0;					// NO existe el arco
}
void ListaAdy::Mostrar()
{
	if (!inicio)
	{
		cout << "\tGrafo VACIO" << endl << endl;
		return;
	}

	cout << "\nLISTA DE NODOS:" << endl;
	cout << "\t";

	auxNod = inicio;
	do
	{
		cout << auxNod->nombre;
		auxNod = auxNod->nodSig;
		cout << " -> ";
	} while (auxNod);
	cout << "null" << endl;

	cout << "\nLISTA DE ADYACENCIAS:" << endl;

	auxNod = inicio;
	do
	{
		cout << "\t" << auxNod->nombre << " => ";
		auxAdy = auxNod->adySig;
		while (auxAdy)
		{
			cout << auxAdy->nombre << "-" << auxAdy->peso << " -> ";
			auxAdy = auxAdy->adySig;
		}
		cout << "null" << endl;
		auxNod = auxNod->nodSig;
	} while (auxNod);
	cout << endl;
}
void ListaAdy::RecorrerProfundidad()
{
	pila = new Nod * [totalNodos];	/* Arreglo para Pila de apuntadores a Nod (nodos del grafo) */
	visitados = new Nod * [totalNodos];	/* Arreglo de apuntadores a Nod para los nodos visitados */
	Nod* extraido;
	Ady* arco;
	int contaVisitados = -1;	/* Indice para el arreglo de nodos visitados */ 
	int yaVisitado = 0, yaEnPila = 0;	/* Banderas que indican si el nodo ya está entre
										   los visitados o ya está en la Pila */

	if (!inicio)	/* Si el grafo está vacío, no se hace ningún recorrido */
	{
		cout << "\tGrafo VACIO" << endl << endl;
		return;
	}
	InsertarPila(inicio);	/* Se inserta el primer nodo del grafo en la Pila */
	extraido = ExtraerPila();	/* Se extrae de la Pila el primer nodo */
	do   /* Ciclo para ir extrayendo cada nodo de la Pila, hasta que esté vacía */
	{
		cout << "\t" << extraido->nombre << endl;	/* Se muestra el nodo extraido de la Pila */
		contaVisitados++;
		visitados[contaVisitados] = extraido;	/* Se incluye en el arreglo de Nodos Visitados
												   el nodo extraido de la Pila */
		arco = extraido->adySig;
		while (arco)	/* Ciclo para revisar, una por una, todas las adyacencias del nodo
						   agregado a Nodos Visitados. Las que aún no se han visitado, 
						   y tampoco están en la Pila, se insertan en la pila */
		{
			yaVisitado = 0;
			for (int i = 0; i <= contaVisitados; i++)	/* revisa si ya está en arreglo de Visitados */
			{
				if (arco->dirNodo == visitados[i])
					yaVisitado = 1;
			}
			yaEnPila = 0;
			for (int i = 0; i <= topePila; i++)		/* Revisa si ya está en la Pila */
			{
				if (arco->dirNodo == pila[i])
					yaEnPila = 1;
			}
			if (yaVisitado == 0 && yaEnPila == 0)	/* Si el nodo adyacente no está en la pila
													   ni en visitados, se inserta en la Pila */
				InsertarPila(arco->dirNodo);
			arco = arco->adySig;		/* Se toma para revisión la siguiente adyacencia */
		} /* Fin de ciclo while (arco) */
		extraido = ExtraerPila();	/* Se extrae el siguiente nodo de la pila */
	} while (extraido);
}
void ListaAdy::RecorrerAncho()
{
	cola = new Nod * [totalNodos];   /* Arreglo para Cola de apuntadores a Nod (nodos del grafo) */
	visitados = new Nod * [totalNodos];   /* Arreglo de apuntadores a Nod para los nodos visitados */
	Nod* extraido;
	Ady* arco;
	int contaVisitados = -1;   /* Indice para el arreglo de nodos visitados */
	int yaVisitado = 0, yaEnCola = 0;   /* Banderas que indican si el nodo ya está entre
										   los visitados o ya está en la Pila */

	if (!inicio)   /* Si el grafo está vacío, no se hace ningún recorrido */
	{
		cout << "\tGrafo VACIO" << endl << endl;
		return;
	}
	InsertarCola(inicio);   /* Se inserta el primer nodo del grafo en la Cola */
	extraido = ExtraerCola();   /* Se extrae de la Cola el primer nodo */
	do    /* Ciclo para ir extrayendo cada nodo de la Cola, hasta que esté vacía */
	{
		cout << "\t" << extraido->nombre << endl;   /* Se muestra el nodo extraido de la Cola */
		contaVisitados++;
		visitados[contaVisitados] = extraido;   /* Se incluye en el arreglo de Nodos Visitados
												   el nodo extraido de la Cola */
		arco = extraido->adySig;
		while (arco)    /* Ciclo para revisar, una por una, todas las adyacencias del nodo
						   agregado a Nodos Visitados. Las que aún no se han visitado, 
						   y tampoco están en la Cola, se insertan en la cola */
		{
			yaVisitado = 0;
			for (int i = 0; i <= contaVisitados; i++)   /* revisa si ya está en arreglo de Visitados */
			{
				if (arco->dirNodo == visitados[i])
					yaVisitado = 1;
			}
			yaEnCola = 0;
			for (int i = inicioCola; i <= finCola; i++)   /* Revisa si ya está en la Cola */
			{
				if (arco->dirNodo == cola[i])
					yaEnCola = 1;
			}
			if (yaVisitado == 0 && yaEnCola == 0)   /* Si el nodo adyacente no está en la cola
													   ni en visitados, se inserta en la Cola */
				InsertarCola(arco->dirNodo);
			arco = arco->adySig;      /* Se toma para revisión la siguiente adyacencia */
		} /* Fin de ciclo while (arco) */
		extraido = ExtraerCola();   /* Se extrae el siguiente nodo de la cola */
	} while (extraido);
}
void ListaAdy::InsertarPila(Nod* noddo)
{
	topePila++;
	pila[topePila] = noddo;
}
Nod* ListaAdy::ExtraerPila()
{
	if (topePila == -1)
		return NULL;
	topePila--;
	return pila[topePila + 1];
}
void ListaAdy::InsertarCola(Nod* noddo)
{
	if (inicioCola == -1)
		inicioCola++;
	finCola++;
	cola[finCola] = noddo;
}
Nod* ListaAdy::ExtraerCola()
{
	if (inicioCola == -1)
		return NULL;
	if (inicioCola > finCola)
		return NULL;
	inicioCola++;
	return cola[inicioCola - 1];
}