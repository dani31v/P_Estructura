
#include "Cola_Dinamica.hpp"
Cola_Trailer::Cola_Trailer()
{
    inicio=final=nodo =NULL;
}
string Cola_Trailer::Consultar()
{
    string sale;

    if (inicio == NULL)    /* Fila VACIA */
        return "";
    nodo = inicio;        /* Nodo apunta al nodo de inicio */
    sale = nodo->producto;    /* Se toman los datos de inicio */

    return sale;
}

string Cola_Trailer::Extraer()
{
    string sale;

    if (inicio == NULL)    /* Fila VACIA */
        return "";
    nodo = inicio;        /* Nodo apunta al nodo de inicio */
    sale = nodo->producto;    /* Se toman los datos de inicio */
    inicio = nodo->sig;    /* 'inicio¥apunta al siguiente en la fila */
    if (inicio == NULL)    /* Si se extrajo el ˙ltimo nodo */
        final = NULL;
    delete nodo;        /* Se libera el nodo extraÌdo */
    return sale;

}



int Cola_Trailer::Insertar(string producto, int placa)
{
    nodo = new Trailer;    /* Nodo nuevo */
    nodo->producto = producto;    /* Datos en nuevo nodo */
    nodo->placa=placa;
    nodo->sig = NULL;    /* Ultimo nodo a punta a NULL */
    if (inicio == NULL)
        inicio = nodo;    /* Solo con la primera inserciÛn */
    if (final != NULL)
        final->sig = nodo; /* Excepto en la primera inserciÛn */
    final = nodo;        /* ¥final¥apunta al nuevo nodo */
    
    return -1;
}


void Cola_Trailer::Mostrar()
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
        cout << "\tPlaca: " << nodo->producto << "// Producto: " << nodo ->placa;
        if (nodo == inicio) cout << "\t<== inicio";
        if (nodo == final) cout << "\t<== final";
        cout << endl;

        nodo = nodo->sig;
    } while (nodo != NULL);
}
