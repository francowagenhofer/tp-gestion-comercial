#include "funciones.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// -------------------------------------------------------------------------------------------------//
// LOTE 1 - MARCAS

int pedirCodigoMarca()
{
    int codigo;
    bool codigo_valido = false;

    while (!codigo_valido)
    {
        cout << "Ingrese el codigo de la marca (1 a 10): ";
        cin >> codigo;

        if (codigo > 0 && codigo < 11)
            codigo_valido = true;
        else
            cout << endl << "Error: El codigo debe ser un entero entre 1 y 10." << endl;
    }
    return codigo;
}

string pedirNombreMarca()
{
    string nombre_marca;

    cin.ignore();
    do
    {
        cout << "Ingrese el nombre de la marca: ";
        getline(cin, nombre_marca);
        cout << endl;

        if (nombre_marca.empty() || nombre_marca == " ")
            cout << endl <<"Error: El nombre no puede estar vacio." << endl << endl;

    }
    while (nombre_marca.empty() || nombre_marca == " ");

    return nombre_marca;
}

int CargarMarcas(int codigos[], string nombres[], int marcas_requeridas)
{
    int cantidadMarcas = 0;
    for (int i = 0; i < marcas_requeridas; i++)
    {
        codigos[i] = pedirCodigoMarca();
        nombres[i] = pedirNombreMarca();
        cantidadMarcas++;
    }
    return cantidadMarcas;
}

void ListarMarcas(int codigos[], string nombres[], int cantidadMarcas)
{
    cout << "- Lista de Marcas -" << endl;
    for (int i = 0; i < cantidadMarcas; i++)
    {
        cout << "Codigo: " << codigos[i] << " - Nombre: " << nombres[i] << endl;
    }
}

// -------------------------------------------------------------------------------------------------//
// LOTE 2 - PRODUCTOS

void CargarProductos(int codigoProductos[], string nombreProducto[], float precioVenta[], float precioCompra[],
                     int stockDisponible[], int codigoMarca[], int codigos[], int cantidadMarcas, int cantidadProductos)
{
    for (int i = 0; i < cantidadProductos; i++)
    {
        cout << "Producto nro. " << i + 1 << endl;

        // Codigo de producto
        int producto;
        do
        {
            cout << "Ingrese el codigo de producto (3 digitos): ";
            cin >> producto;

            if (producto < 100 || producto > 999)
                cout << endl << "Codigo invalido. Debe tener 3 digitos." << endl <<endl;
        }
        while (producto < 100 || producto > 999);

        // Nombre del producto
        cin.ignore();
        string nombre;
        do
        {
            cout << "Ingrese el nombre del producto: ";
            getline(cin, nombre);

            if (nombre.empty())
                cout << endl << "El nombre no puede estar vacio." << endl << endl;
        }
        while (nombre.empty());

        // Precio de venta
        float pVenta;
        do
        {
            cout << "Ingrese el precio de venta (mayor a 0): ";
            cin >> pVenta;

            if (pVenta <= 0)
                cout << endl << "Debe ser mayor a 0." << endl << endl;
        }
        while (pVenta <= 0);

        // Precio de compra
        float pCompra;
        do
        {
            cout << "Ingrese el precio de compra (mayor a 0): ";
            cin >> pCompra;

            if (pCompra <= 0)
                cout << endl << "Debe ser mayor a 0." << endl << endl;
        }
        while (pCompra <= 0);

        // Stock disponible
        int stock;
        do
        {
            cout << "Ingrese el stock disponible (mayor a 0): ";
            cin >> stock;

            if (stock <= 0)
                cout << endl << "Debe ser mayor a 0." << endl << endl;
        }
        while (stock <= 0);

        // Codigo de marca
        int marca;
        bool marcaValida;
        do
        {
            cout << "Ingrese el codigo de marca (1 al 10): ";
            cin >> marca;

            marcaValida = false;
            if (marca >= 1 && marca <= 10)
            {
                for (int i = 0; i < cantidadMarcas; i++)
                {
                    if (marca == codigos[i])
                        marcaValida = true;
                }
            }

            if (!marcaValida)
                cout << endl << "Codigo de marca invalido o no existe." << endl << endl;
        }
        while (!marcaValida);

        codigoProductos[i] = producto;
        nombreProducto[i] = nombre;
        precioVenta[i] = pVenta;
        precioCompra[i] = pCompra;
        stockDisponible[i] = stock;
        codigoMarca[i] = marca;
        cout << endl;
    }
}

// Lista de productos
void ListarProductos(int codigoProductos[], string nombreProducto[], float precioVenta[],
                     float precioCompra[], int stockDisponible[], int codigoMarca[], int cantidadProductos)
{
    cout <<"- Lista de Productos -" << endl;
    for (int i = 0; i < cantidadProductos; i++)
    {
        cout << "Codigo: " << codigoProductos[i] << " - Nombre: " << nombreProducto[i] << " - Precio Venta: $" << precioVenta[i]
             << " - Precio Compra: $" << precioCompra[i] << " - Stock: " << stockDisponible[i] << " - Marca: " << codigoMarca[i]
             << endl;
    }
}

// -------------------------------------------------------------------------------------------------//
// LOTE 3 - FORMAS DE PAGO

bool CodigoValido(string codigo, string codigos_validos[], int cantidadFormasPago)
{
    for (int i = 0; i < cantidadFormasPago; i++)
    {
        if (codigo == codigos_validos[i])
            return true;
    }
    return false;
}

bool CodigoRepetido(string codigo, string codigo_FormaDePago[], int cantidadFormasPago_actual)
{
    for (int i = 0; i < cantidadFormasPago_actual; i++)
    {
        if (codigo == codigo_FormaDePago[i])
            return true;
    }
    return false;
}

bool NombreValido(string nombre, string nombres_validos[], int cantidadFormasPago)
{
    for (int i = 0; i < cantidadFormasPago; i++)
    {
        if (nombre == nombres_validos[i])
            return true;
    }
    return false;
}

bool NombreRepetido(string nombre, string nombre_FormaDePago[], int cantidadFormasPago_actual)
{
    for (int i = 0; i < cantidadFormasPago_actual; i++)
    {
        if (nombre == nombre_FormaDePago[i])
            return true;
    }
    return false;
}


void CargarFormasDePago(string codigo_FormaDePago[], string nombre_FormaDePago[], int porcentaje_FormaDePago[], int cantidadFormasPago)
{
    string codigos_validos[] = {"EF", "MP", "TR", "TC", "CT"};
    string nombres_validos[] = {"Efectivo", "Mercado Pago", "Transferencia", "Tarjeta de Credito", "Criptomoneda"};

    cout << "# Formas de pago disponibles:" << endl;
    for (int i = 0; i < cantidadFormasPago; i++)
        cout << "- " << codigos_validos[i] << " : " << nombres_validos[i] << endl;

    for (int i = 0; i < cantidadFormasPago; i++)
    {
        string codigo, nombre;
        bool codigoValido = false;
        bool nombreValido = false;

        while (!codigoValido)
        {
            cout << endl << "Ingrese el codigo de forma de pago (en mayuscula): ";
            cin >> codigo;

            if (!CodigoValido(codigo, codigos_validos, cantidadFormasPago))
                cout << endl <<"Codigo invalido. Intente nuevamente." << endl;
            else if (CodigoRepetido(codigo, codigo_FormaDePago, i))
                cout << endl <<"Codigo repetido. Intente con otro." << endl;
            else
                codigoValido = true;
        }

        while (!nombreValido)
        {
            cin.ignore();
            cout << "Ingrese nombre de forma de pago: ";
            getline(cin, nombre);

            if (!NombreValido(nombre, nombres_validos, cantidadFormasPago))
                cout << endl <<"Nombre invalido. Intente nuevamente." << endl;
            else if (NombreRepetido(nombre, nombre_FormaDePago, i))
                cout << endl <<"Nombre repetido. Intente con otro." << endl;
            else
                nombreValido = true;
        }

        codigo_FormaDePago[i] = codigo;
        nombre_FormaDePago[i] = nombre;

        cout << "Ingrese porcentaje (negativo = descuento, positivo = interes): ";
        cin >> porcentaje_FormaDePago[i];
    }
}

void ListarFormasDePago(string codigo_FormaDePago[], string nombre_FormaDePago[], int porcentaje_FormaDePago[], int cantidadFormasPago)
{
    cout << endl <<"- Lista de Formas de Pago -" << endl;
    for (int i = 0; i < cantidadFormasPago; i++)
    {
        cout << nombre_FormaDePago[i] << " (" << codigo_FormaDePago[i] << ") - Porcentaje: " << porcentaje_FormaDePago[i] << "%"
             << endl;
    }
}

// -------------------------------------------------------------------------------------------------//
// LOTE 4 - VENTAS

int PedirCodigoProducto(int codigoProductos[], int cantidadProductos)
{
    int codigo, posicion = -1;
    do
    {
        cout << "Ingresar codigo de producto (3 digitos): ";
        cin >> codigo;
        if (codigo < 100 || codigo > 999)
            cout << endl << "Codigo de producto invalido, debe tener 3 digitos. Intente nuevamente." << endl << endl;
        else
        {
            for (int i = 0; i < cantidadProductos; i++)
            {
                if (codigo == codigoProductos[i])
                {
                    posicion = i;
                    break;
                }
            }
            if (posicion == -1)
                cout << endl << "Codigo de producto invalido. Intente nuevamente." << endl << endl;
        }
    }
    while (posicion == -1);

    return posicion;
}

int PedirFormaDePago(string codigoFormaPago[], int cantidadFormasPago)
{
    string forma;
    int posicion = -1;
    do
    {
        cout << "Ingresar forma de pago (EF, MP, TR, TC, CT): ";
        cin >> forma;

        for (int i = 0; i < cantidadFormasPago; i++)
        {
            if (forma == codigoFormaPago[i])
            {
                posicion = i;
                break;
            }
        }
        if (posicion == -1)
            cout << "Forma de pago invalida. Intente nuevamente." << endl << endl;
    }
    while (posicion == -1);

    return posicion;
}

int PedirCantidadVendida()
{
    int cantidad;
    do
    {
        cout << "Ingresar cantidad vendida (> 0): ";
        cin >> cantidad;

        if (cantidad <= 0)
            cout << "Cantidad invalida. Debe ser mayor a 0." << endl << endl;
    }
    while (cantidad <= 0);

    return cantidad;
}

int PedirCodigoCliente()
{
    int cliente;
    do
    {
        cout << "Ingresar codigo de cliente (1 a 50): ";
        cin >> cliente;

        if (cliente < 1 || cliente > 50)
            cout << "Codigo de cliente invalido." << endl << endl;
    }
    while (cliente < 1 || cliente > 50);

    return cliente;
}

int PedirDiaVenta()
{
    int dia;
    do
    {
        cout << "Ingresar dia de la venta (1 a 30): ";
        cin >> dia;

        if (dia < 1 || dia > 30)
            cout << "Dia invalido. Debe ser entre 1 y 30." << endl << endl;
    }
    while (dia < 1 || dia > 30);

    return dia;
}

void CargarVentas(
    int codigoProductos[], int cantidadProductos,  string codigoFormaPago[], int cantidadFormasPago,
    float precioVenta[], int stockDisponible[], int codigos[], int codigosMarcaProducto[], int cantidadMarcas,
    int porcentaje_FormaDePago[],

    int cantidadVendidaPorProducto[], float recaudacionPorProducto[], int ventasPorFormaPago[],
    int ventasEf[], int ventasMp[], int ventasTr[], int ventasTc[], int ventasCt[],
    int comprasPorCliente[])
{
    int nro_compra;

    cout << "Ingresar nro de compra (0 para finalizar): ";
    cin >> nro_compra;

    while (nro_compra != 0)
    {
        // Ingreso de valores
        int posicion_producto = PedirCodigoProducto(codigoProductos, cantidadProductos);
        int posicion_fdp = PedirFormaDePago(codigoFormaPago, cantidadFormasPago);
        int cantidad_vendida = PedirCantidadVendida();
        int codigo_cliente = PedirCodigoCliente();
        int dia_venta = PedirDiaVenta();

        // Reporte 1 - Recaudacion y cantidad vendida por producto
        cantidadVendidaPorProducto[posicion_producto] += cantidad_vendida;

        float precioFinal = precioVenta[posicion_producto] * (1 + porcentaje_FormaDePago[posicion_fdp] / 100.0f);
        recaudacionPorProducto[posicion_producto] += cantidad_vendida * precioFinal;

        // Reporte 2 - Porcentaje de ventas por forma de pago
        ventasPorFormaPago[posicion_fdp]++;

        // Reporte 3 - Ventas por marca y forma de pago
        int marcaProducto = codigosMarcaProducto[posicion_producto];
        int indiceMarca = -1;
        for (int i = 0; i < cantidadMarcas; i++)
        {
            if (marcaProducto == codigos[i])
            {
                indiceMarca = i;
                break;
            }
        }

        if (indiceMarca != -1)
        {
            if (codigoFormaPago[posicion_fdp] == "EF")
                ventasEf[indiceMarca] += cantidad_vendida;
            else if (codigoFormaPago[posicion_fdp] == "MP")
                ventasMp[indiceMarca] += cantidad_vendida;
            else if (codigoFormaPago[posicion_fdp] == "TR")
                ventasTr[indiceMarca] += cantidad_vendida;
            else if (codigoFormaPago[posicion_fdp] == "TC")
                ventasTc[indiceMarca] += cantidad_vendida;
            else if (codigoFormaPago[posicion_fdp] == "CT")
                ventasCt[indiceMarca] += cantidad_vendida;
        }

        // Reporte 5 - top 10 clientes con mas ventas
        comprasPorCliente[codigo_cliente - 1]++;

        stockDisponible[posicion_producto] -= cantidad_vendida;

        cout << endl << "Venta registrada correctamente." << endl;
        cout << endl << "Ingresar nro de compra (0 para finalizar): ";
        cin >> nro_compra;
    }
}

// -------------------------------------------------------------------------------------------------//
// 5 - REPORTES

// Reportes 1
void Reporte_RecaudacionPorProducto(int codigoProductos[], string nombreProducto[], float recaudacionPorProducto[],
                                    int cantidadVendidaPorProducto[], int stockDisponible[], int cantidadProductos)
{
    int indices[cantidadProductos];
    for (int i = 0; i < cantidadProductos; i++)
        indices[i] = i;

    for (int i = 0; i < cantidadProductos - 1; i++)
    {
        for (int j = 0; j < cantidadProductos - i - 1; j++)
        {
            if (cantidadVendidaPorProducto[indices[j]] < cantidadVendidaPorProducto[indices[j + 1]])
            {
                int temp = indices[j];
                indices[j] = indices[j + 1];
                indices[j + 1] = temp;
            }
        }
    }

    cout << endl << "- Recaudacion por producto -" << endl;
    for (int i = 0; i < cantidadProductos; i++)
    {
        int idx = indices[i];
      //  if (cantidadVendidaPorProducto[idx] > 0)
        //{
            cout << i + 1 << ". Codigo del producto: " << codigoProductos[idx] << " - Nombre: " << nombreProducto[idx]
                 << " - Vendidos: " << cantidadVendidaPorProducto[idx]
                 << " - Recaudado: $" << recaudacionPorProducto[idx] << " - Stock restante: " << stockDisponible[idx] << endl;
        //}
    }
    cout << endl;
}

// Reporte 2
void Reporte_PorcentajePorFormaDePago(string nombreFormaPago[], int ventasPorFormaPago[], int cantidadFormasPago)
{
    int totalVentas = 0;
    for (int i = 0; i < cantidadFormasPago; i++)
    {
        totalVentas += ventasPorFormaPago[i];
    }

    if (totalVentas > 0)
    {
        cout << endl << "- Porcentaje de ventas por forma de pago -" << endl;
        for (int i = 0; i < cantidadFormasPago; i++)
        {
            float porcentaje = (float)ventasPorFormaPago[i] * 100 / totalVentas;
            cout << nombreFormaPago[i] << ": " << porcentaje << "%" << endl;
        }
        cout << endl;
    }
    else
        cout << "No se registraron ventas." << endl;
}

// Reporte 3
void Reporte_VentasPorMarcaYFormaPago(string nombresMarca[], int cantidadMarcas, int ventasEf[],
                                      int ventasMp[], int ventasTr[], int ventasTc[], int ventasCt[])
{
    cout << endl << "- Ventas por Marca y Forma de Pago -" << endl << endl;

    for (int i = 0; i < cantidadMarcas; i++)
    {
        int totalUnidadesVendidas = ventasEf[i] + ventasMp[i] + ventasTr[i] + ventasTc[i] + ventasCt[i];

        cout << "Marca: " << nombresMarca[i] << " - Total unidades vendidas: " << totalUnidadesVendidas << endl;
        cout << "  - Efectivo: " << ventasEf[i] << " unidades" << endl;
        cout << "  - Mercado Pago: " << ventasMp[i] << " unidades" << endl;
        cout << "  - Transferencia: " << ventasTr[i] << " unidades" << endl;
        cout << "  - Tarjeta de Credito: " << ventasTc[i] << " unidades" << endl;
        cout << "  - Criptomoneda: " << ventasCt[i] << " unidades" << endl;
        cout << "----------------------------------------" << endl;
    }

    cout << endl;
}

// Reporte 4
void Reporte_ProductosSinVentas(int codigoProductos[], string nombreProducto[], int cantidadVendidaPorProducto[], int cantidadProductos)
{
    int posicion = 1;
    bool haySinVentas = false;

    cout << endl << "- Productos sin ventas -" << endl;
    for (int i = 0; i < cantidadProductos; i++)
    {
        if (cantidadVendidaPorProducto[i] == 0)
        {
            cout << posicion << ". Codigo del producto: " << codigoProductos[i] << " - Nombre: " << nombreProducto[i] << endl;
            posicion++;
            haySinVentas = true;
        }
    }
    cout << endl;

    if (!haySinVentas)
        cout << "Todos los productos registraron ventas." << endl << endl;
}

// Reporte 5
void Reporte_Top10ClientesYCupones(int comprasPorCliente[], int cantidadCodigoClientes)
{
    int indices[cantidadCodigoClientes];
    for (int i = 0; i < cantidadCodigoClientes; i++)
        indices[i] = i;

    for (int i = 0; i < cantidadCodigoClientes - 1; i++) // pasadas
    {
        for (int j = 0; j < cantidadCodigoClientes - 1 - i; j++) // comparaciones
        {
            if (comprasPorCliente[indices[j]] < comprasPorCliente[indices[j + 1]]) // De mayor a menor
            {
                int temp = indices[j];
                indices[j] = indices[j + 1];
                indices[j + 1] = temp;
            }
        }
    }

    cout << endl << "- Top 10 clientes con mas compras -" << endl;
    const int top10 = 10;
    for (int i = 0; i < top10; i++)
    {
        int codigoCliente = indices[i] + 1;
        cout << i + 1 <<". Codigo de cliente: " << codigoCliente << " - Compras: " << comprasPorCliente[codigoCliente - 1] << endl;
    }

    // ------------------------------------------------------------//

    cout << endl << "- Sorteo de cupones (3 ganadores) -" << endl;
    srand(time(NULL));

    bool yaSorteado[top10] = {}; // vector bool iniciado en false, para validar si ya fue sorteada la posicion x
    int ganadores = 0;

    while (ganadores < 3)
    {
        int posicion = rand() % top10;

        if (!yaSorteado[posicion])
        {
            yaSorteado[posicion] = true;

            int codigoClienteGanador = indices[posicion] + 1;
            cout << "# Ganador - Codigo de cliente: " << codigoClienteGanador << " - Compras: " << comprasPorCliente[codigoClienteGanador - 1] << endl;
            ganadores++;
        }
    }
    cout << endl;
}

// -------------------------------------------------------------------------------------------------//
// VALIDACIONES DEL MENU

bool ValidarMarcasCargadas(int cantidadMarcas, int marcas_requeridas)
{
    return cantidadMarcas == marcas_requeridas;
}

bool ValidarProductosCargados(string nombreProducto[])
{
    return !nombreProducto[0].empty(); // valida que haya un nombre de producto cargado
}

bool ValidarFormasPagoCargadas(string nombre_FormaDePago[])
{
    return !nombre_FormaDePago[0].empty();
}

bool HayVentasCargadas(int cantidadVendidaPorProducto[], int cantProductos)
{
    for (int i = 0; i < cantProductos; i++)
    {
        if (cantidadVendidaPorProducto[i] > 0)
            return true;
    }
    return false;
}
