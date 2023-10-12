
#include "extraerlists.hpp"


ListaEnlazada::ListaEnlazada(/* args */)
{
    cabecera = final = nodo = NULL;
}

void ListaEnlazada::InsertarInicio(string nueva)
{
    // Paso 1: Crear nodo nuevo
    nodo = new Palabra;
    // Paso 2: Llenar el campo de información
    nodo->dato = nueva;
    // Paso 3: LLenar el campo de enlace
    nodo->siguiente = cabecera;
    // Paso 4: Apuntar cabecera al nuevo nodo
    cabecera = nodo;

    // Extra: considerando nuestro parámetro 'Final'
    if (final == NULL) final = nodo;
}

int ListaEnlazada::InsertarInter(string nueva, string anterior)
{
    bool encontrado =false;
    Palabra* nodoAnterior;
    if(!cabecera)
    {
        InsertarInicio(nueva);
        return -1;
    }
    /*Paso 1. Localizar la posición para insertar*/
    nodoAnterior=cabecera;
    
    while (nodoAnterior!=final) {
        if(nodoAnterior->dato ==anterior)
        {

            encontrado = true;
            nodo =new Palabra;
            nodo->dato=nueva;
            nodo->siguiente=nodoAnterior->siguiente;
            nodoAnterior->siguiente= nodo;
            if(nodoAnterior==final)
                final =nodo;
            return 0;
        }
        nodoAnterior=nodoAnterior->siguiente;
    }
    if(encontrado==false)
    {
        InsertarFinal(nueva);
        return -2;
    }
    return 0;
}
    
int ListaEnlazada::InsertarFinal(string nueva)
{
    
    if(!cabecera)
    {
        InsertarInicio(nueva);
        return -1; //lista vacía
    }
    //Paso 1: Crear nuevo nodo
    nodo = new Palabra;
    /*Llenar el campo de información*/
    nodo->dato = nueva;
    /*Apuntar a NULL el campo de enlace*/
    nodo->siguiente = NULL;
    /*Paso 4. Apunta campo de enlace final a nuevo nodo*/
    final->siguiente = nodo;
    final=nodo;
    return 0;//se ingresó bien
}
string ListaEnlazada::ExtraerInicio()
{
    string extraida;
    if(cabecera==NULL)
        return "";
    /*Paso 1: Localizar nodo señalado por la cabecera*/
    nodo = cabecera;
    /*Paso 2: Tomar información del nodo a extraer*/
    extraida = nodo->dato;
    /*Paso 3: Apuntar al siguiente nodo*/
    cabecera = nodo->siguiente;
    /*Paso 4: Liberar nodo extraido*/
    delete nodo;
    
    return extraida;
}
string ListaEnlazada::ExtraerFinal()
{
    string extraida;
    Palabra *nodoAnterior;
    if(cabecera==NULL)
        return "";
    if(cabecera==final)
    {
        extraida = ExtraerInicio();
        return extraida;
    }
    nodoAnterior= NULL;
    nodo = cabecera;
    while(nodo!=final)
    {
        nodoAnterior = nodo;
        nodo = nodo->siguiente;
        
    }
    extraida = nodo->dato;
    /*Paso 3:Apuntar a NULL el enlace del nodo anterior*/
    nodoAnterior->siguiente=NULL;
    /*Paso 4: Apuntar la variable final a nodoAnterior*/
    final= nodoAnterior;
    /*Paso 5: Eliminar nodo extraído*/
    delete nodo;
    
    
    return extraida;
}
void ListaEnlazada::Mostrar()
{
    cout << "\nLISTA DE PALABRAS:" << endl;
    if (!cabecera) //cabecera == NULL
    {
        cout << "\n\tLista VACÍA" << endl;
        return;
    }
    nodo = cabecera;
    while (nodo) //while(nodo != NULL)
    {
        cout << "\t" << nodo->dato;
        if (nodo == cabecera) cout << "\t<= Cabecera";
        if (nodo == final) cout << "\t<= Final";
        cout << endl;

        nodo = nodo->siguiente;
    }
}
