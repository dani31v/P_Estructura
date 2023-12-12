//
//  main.cpp
//  matriz_y_adyacencia
//
//  Created by Daniela Valencia on 15/11/23.
//

#include <iostream>
#include "matrizad.hpp"

int main()
{
    int maxNodos, opc, codigo, peso;
    char nuevo, origen, destino;
    cout <<"\n Cantidad máxima de nodos: ";
    cin >> maxNodos;
    MatrizAdy grafo(maxNodos);
    
    do {
        cout << "\n 1.- Insertar Nodo"<< endl;;
        cout << "\n 2.- Insertar Arco"<< endl;;
        cout << "\n 3.- Mostrar"<< endl;;
        cout << "\n 4.- Salir"<< endl;;
        cout << "\n Elija una opción: "<< endl;;
        
        cin >> opc;
        
        switch (opc) {
            case 1:
                cout << "Nombre del nodo (una letra): " << endl;
                cin >> nuevo;
                codigo = grafo.InsertarNodo(nuevo);
                if(codigo == 0)
                    cout << "Se insetó el nodo" << endl;
                if(codigo == -1)
                    cout << "El arreglo está lleno"<<endl;
                if(codigo ==- 2)
                    cout << " Ya existe el nodo" << endl;
                break;
                
            case 2:
                
                cout << "Nombre del origen: " << endl;
                cin >> origen;
                cout << "Nombre del destino: " << endl;
                cin >> destino;
                cout << "\tPeso del arco: " << endl;
                cin >> peso;
                codigo = grafo.InsertarArco(origen, destino, peso);
                break;
            case 3:
                grafo.Mostrar();
                break;
            case 4:
                cout << "Se salió de la aplicación..."<< endl;;
                break;
            default:
                cout << "ERROR. Opción no válida.." << endl;
                break;
        }
    } while (opc!=4);
}
