#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <iostream>
using namespace std;

// Funcion para Lote 1 - carga de MARCAS

// Braian
int Lote1()
{
    int CodigoMarcas[10];

    string NombreMarca[100];

    for(int x=0; x<10; x++)
    {
        cout<<"Ingrese el codigo de Marca: "<<endl;
        cin>>CodigoMarcas[x];

        if(CodigoMarcas[x]>=1 && CodigoMarcas[x]<=10)
        {
            cout<<"------------------------------"<<endl;
            cout<<"Ingrese el nombre de la Marca:"<<endl;
            cin>>NombreMarca[x];
        }
        else
            cout<<"El numero ingresado no es Valido. Favor de seleccionar entre el 1 y 10"<<endl;
    }
}

// Jose
int pedirCodigoMarca() {
    int codigo;
    bool codigo_valido = false;

    while (!codigo_valido) {
        cout << "## Ingrese el código de la marca (1 a 10): ";
        cin >> codigo;
        if (codigo > 0 && codigo < 11) {
            codigo_valido = true;
        } else {
            cout << "--- Error: El código debe ser un entero entre 1 y 10 ---" << endl;
        }
    }
    return codigo;
}

string pedirNombreMarca() {
    string nombre_marca;

    cin.ignore();  // Solo una vez antes del getline, no dentro del bucle
    do {
        cout << "Ingrese el nombre de la marca: ";
        getline(cin, nombre_marca);
        if (nombre_marca.empty() || nombre_marca == " ") {
            cout << "--- Error: El nombre no puede estar vacío ---" << endl;
        }
    } while (nombre_marca.empty() || nombre_marca == " ");

    return nombre_marca;
}

int CargaLote1(int codigos[], string nombres[]) {
    int cantidad = 0;
    for (int i = 0; i < 10; i++) {
        codigos[i] = pedirCodigoMarca();
        nombres[i] = pedirNombreMarca();
        cantidad++;
    }
    return cantidad;
}


// Funcion para Lote 2 - carga de PRODUCTOS.

// Braian
int Lote2()
{
    int producto[20];
    int StockDisponible[100], Cod,CodigoProducto[100];
    string NombreProducto[10];
    float PrecioVenta[100],PrecioCompra[100];

    for(int x=0;x<20;x++)
    {
        cout<<"ingrese el producto: "<<endl;
        cin>>producto[20];

    //for(int x=0;x<20;x++){
        cout<<"ingrese el codigo de producto: "<<endl;
        cin>>CodigoProducto[x];
        cout<<"------------------------------"<<endl;
        cout<<"ingrese el nombre del producto: "<<endl;
        cin>>NombreProducto[x];
        cout<<"------------------------------"<<endl;
        cout<<"ingrese el precio de venta: "<<endl;
        cin>>PrecioVenta[x];
        cout<<"------------------------------"<<endl;
        cout<<"ingrese el precio de compra: "<<endl;
        cin>>PrecioCompra[x];
        cout<<"------------------------------"<<endl;
        cout<<"ingrese el Stock Disponible: "<<endl;
        cin>>StockDisponible[x];
        cout<<"------------------------------"<<endl;
        cout<<"ingrese el codigo de marca: "<<endl;
        Cod=Lote1();
        cout<<"------------------------------"<<endl;
    //}
    }
}


#endif // FUNCIONES_H_INCLUDED
