#include "examenfinal.hpp"
Almacen::Almacen()
{
    raiz = nodo = NULL;
}

Numero* Almacen:: get_root()
{
    return raiz;
    
}

Numero* Almacen:: buscar(Numero* inicio, int buscado, int nivel)
{
    Numero* encontrado;
    if(buscado == inicio->numero)
    {
        cout << "Se encontró el producto" << buscado << " y es " << inicio->producto << "en el nivel" << nivel << endl;
    }
}
