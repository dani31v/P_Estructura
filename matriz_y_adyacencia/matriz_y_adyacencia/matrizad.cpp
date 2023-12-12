
#include "matrizad.hpp"
MatrizAdy::MatrizAdy(int tam)
{
    maxNodos = tam;
    ocupados = 0;
    posiOri = -1;
    posiDes = -1;
    nodos = new char[tam]; //arreglo de nodos
    arcos = new int* [tam]; //renglones del arreglo arcos
    for (int i=0; i< tam; i++)
        arcos[i] =  new int [tam]; //columnas de cada renglon
    for (int i= 0; i < tam; i++)
        nodos[i] = '=';
    for (int i = 0; i < tam; i++)
    {
        for (int j= 0; j < tam; j++)
            arcos[i][j] = -1;  //inicializa las adyacencias vacías
    }
    
}
void MatrizAdy::Mostrar()
{
    cout << "Matriz de adyacencias " << endl;
    cout << "\n\t";
    for ( int i = 0; i < maxNodos; i++)
    {
        cout << "\t" << nodos[i];
    }
    cout << endl;
    for(int i = 0; i< maxNodos; i++)
    {
        cout << "\t" << nodos[i];
    
        for(int j= 0; j < maxNodos; j++)
        {
            if(arcos[i][j] != -1)
                
                cout << "\t" << arcos[i][j];
            else
                cout << "\t" << "-";
        }
        cout << endl;
    }
    
    
}
int MatrizAdy::BuscarNodo(char buscado)
{

    for (int i = 0; i < ocupados; i++)
    {
        if(nodos[i] == buscado)
            return i;
    }
    return -1;
}

int MatrizAdy::InsertarNodo(char nuevo)
{
    if(ocupados == maxNodos)
    {
        return -1;
    }

    if(ocupados== 0) //grafo vacío. inserta nuevo
    {
        nodos[ocupados] = nuevo;
        ocupados++;
        return 0;
    }

    if(BuscarNodo(nuevo) != -1) // ya existe el nodo no se inserta
    {
        return -1;
    }
    nodos[ocupados] = nuevo; // se insertó el nodo
    ocupados++;
    return 0;
}
int MatrizAdy::InsertarArco(char ori, char des, int peso)
{
    if (ocupados == 0)
    {
        return -1;
    }
    
    posiOri = BuscarNodo(ori);
    posiDes = BuscarNodo(des);
    if(posiOri == -1 || posiDes == -1)
        return -2;
    if(arcos[posiOri][posiDes] != -1)
    {
        arcos[posiOri][posiDes] = peso;
        arcos[posiDes][posiOri] = peso;
        return -3;
    }
    else{
        arcos[posiOri][posiDes] = peso;
        arcos[posiDes][posiOri] = peso;
        return -3;
        
    }
    return 0;
}
