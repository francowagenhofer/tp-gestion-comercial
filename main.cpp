#include "funciones.h"
#include <iostream>
#include <string>

using namespace std;

void SubmenuReportes(
    int codigoProductos[], string nombreProducto[], int stockDisponible[],
    int cantidadVendidaPorProducto[], float recaudacionPorProducto[],
    string codigoFormaPago[], string nombreFormaPago[], int ventasPorFormaPago[],
    int codigosMarca[], string nombresMarca[],
    int comprasPorCliente[],
    int cantidadProductos, int cantidadMarcas, int cantidadFormasPago,
    int ventasEf[], int ventasMp[], int ventasTr[], int ventasTc[], int ventasCt[], int cantidadCodigoClientes);

int main()
{
    // Lote de Marcas
    const int marcas_requeridas = 10;
    int codigos[marcas_requeridas];
    string nombres[marcas_requeridas];
    int cantidadMarcas = 0;

    // Lote de Productos
    const int cantidadProductos = 20;
    int codigoProductos[cantidadProductos];
    string nombreProducto[cantidadProductos];
    float precioVenta[cantidadProductos];
    float precioCompra[cantidadProductos];
    int stockDisponible[cantidadProductos];
    int codigosMarca[cantidadProductos];

    // Lote de Formas de pago
    const int cantidadFormasPago = 5;
    string codigo_FormaDePago[cantidadFormasPago];
    string nombre_FormaDePago[cantidadFormasPago];
    int porcentaje_FormaDePago[cantidadFormasPago];

    // Lote de Reportes
    int cantidadVendidaPorProducto[cantidadProductos] = {};
    float recaudacionPorProducto[cantidadProductos] = {};
    int ventasPorFormaPago[cantidadFormasPago] = {};
    int ventasEf[marcas_requeridas] = {};
    int ventasMp[marcas_requeridas] = {};
    int ventasTr[marcas_requeridas] = {};
    int ventasTc[marcas_requeridas] = {};
    int ventasCt[marcas_requeridas] = {};
    const int cantidadCodigoClientes = 50;
    int comprasPorCliente[cantidadCodigoClientes] = {};

    int opcion = 0;
    while (opcion != 6)
    {
        cout << endl << "--- MENU PRINCIPAL ---" << endl;
        cout << "1. Cargar lote de marcas" << endl;
        cout << "2. Cargar lote de productos" << endl;
        cout << "3. Cargar lote de formas de pago" << endl;
        cout << "4. Cargar lote de ventas" << endl;
        cout << "5. Mostrar reportes" << endl;
        cout << "6. Salir del programa" << endl;

        cout << endl << "Seleccione una opcion del menu (1 al 5, 6 para salir): ";
        cin >> opcion;

        switch (opcion)
        {

        case 1:
            cout << endl << "1. Cargar lote de marcas" << endl << endl;
            cantidadMarcas = CargarMarcas(codigos, nombres, marcas_requeridas);
            ListarMarcas(codigos, nombres, cantidadMarcas);
            break;
        case 2:
            cout << endl << "2. Cargar lote de productos" << endl << endl;
            if (!ValidarMarcasCargadas(cantidadMarcas, marcas_requeridas))
                cout << "# Primero debe cargar el lote de marcas." << endl;
            else
            {
                CargarProductos(codigoProductos, nombreProducto, precioVenta,
                                precioCompra, stockDisponible, codigosMarca,
                                codigos, cantidadMarcas, cantidadProductos);
                ListarProductos(codigoProductos, nombreProducto, precioVenta, precioCompra,
                                stockDisponible, codigosMarca, cantidadProductos);
            }
            break;
        case 3:
            cout << endl <<"3. Cargar lote de formas de pago" << endl << endl;

            /*if (!ValidarMarcasCargadas(cantidadMarcas, marcas_requeridas))
                cout << "# Primero debe cargar el lote de marcas." << endl;
            else if (!ValidarProductosCargados(nombreProducto))
                cout << "# Primero debe cargar el lote de productos." << endl;
            else
            {*/
                CargarFormasDePago(codigo_FormaDePago, nombre_FormaDePago, porcentaje_FormaDePago, cantidadFormasPago);
                ListarFormasDePago(codigo_FormaDePago, nombre_FormaDePago, porcentaje_FormaDePago, cantidadFormasPago);
            //}
            break;
        case 4:
            cout << endl <<"4. Cargar lote de ventas" << endl << endl;

            if (!ValidarMarcasCargadas(cantidadMarcas, marcas_requeridas))
                cout << "# Primero debe cargar el lote de marcas." << endl;
            else if (!ValidarProductosCargados(nombreProducto))
                cout << "# Primero debe cargar el lote de productos." << endl;
            else if (!ValidarFormasPagoCargadas(nombre_FormaDePago))
                cout << "# Primero debe cargar el lote de formas de pago." << endl;
            else
            {
                CargarVentas(codigoProductos, cantidadProductos, codigo_FormaDePago,
                             cantidadFormasPago, precioVenta, stockDisponible, codigos, codigosMarca, cantidadMarcas,
                             porcentaje_FormaDePago, cantidadVendidaPorProducto, recaudacionPorProducto, ventasPorFormaPago,
                             ventasEf, ventasMp, ventasTr, ventasTc, ventasCt,comprasPorCliente);
            }
            break;
        case 5:
            cout << endl << "5. Mostrar reportes" << endl << endl;

            if (!ValidarMarcasCargadas(cantidadMarcas, marcas_requeridas))
                cout << "# Primero debe cargar el lote de marcas." << endl;
            else if (!ValidarProductosCargados(nombreProducto))
                cout << "# Primero debe cargar el lote de productos." << endl;
            else if (!ValidarFormasPagoCargadas(nombre_FormaDePago))
                cout << "# Primero debe cargar el lote de formas de pago." << endl;
            else if (!HayVentasCargadas(cantidadVendidaPorProducto, cantidadProductos))
                cout << "# Primero debe cargar el lote de ventas." << endl;
            else
            {
                SubmenuReportes(codigoProductos, nombreProducto, stockDisponible,
                                cantidadVendidaPorProducto, recaudacionPorProducto,
                                codigo_FormaDePago, nombre_FormaDePago, ventasPorFormaPago,
                                codigos, nombres, comprasPorCliente,
                                cantidadProductos, cantidadMarcas, cantidadFormasPago,
                                ventasEf, ventasMp, ventasTr, ventasTc, ventasCt, cantidadCodigoClientes);
            }
            break;
        case 6:
            cout << endl << "Salir del programa." << endl;
            break;
        default:
            cout << endl << "Opcion invalida. Intente nuevamente." << endl;
        }
    }

    return 0;
}

void SubmenuReportes(
    int codigoProductos[], string nombreProducto[], int stockDisponible[],
    int cantidadVendidaPorProducto[], float recaudacionPorProducto[],
    string codigoFormaPago[], string nombreFormaPago[], int ventasPorFormaPago[],
    int codigosMarca[], string nombresMarca[],
    int comprasPorCliente[],
    int cantidadProductos, int cantidadMarcas, int cantidadFormasPago,
    int ventasEf[], int ventasMp[], int ventasTr[], int ventasTc[], int ventasCt[], int cantidadCodigoClientes)
{
    int subopcion = 0;
    while (subopcion != 6)
    {
        cout << "--- SUBMENU DE REPORTES ---" << endl;
        cout << "1. Reporte de recaudacion por producto" << endl;
        cout << "2. Reporte de porcentaje de ventas por forma de pago" << endl;
        cout << "3. Reporte de ventas por marca y forma de pago" << endl;
        cout << "4. Reporte de productos sin ventas" << endl;
        cout << "5. Reporte de Top 10 clientes + sorteo de cupones" << endl;
        cout << "6. Salir del submenu reportes" << endl;

        cout << endl << "Seleccione una opcion del submenu (1 al 5, 6 para volver): ";
        cin >> subopcion;

        switch (subopcion)
        {
        case 1:
            cout << endl << "1. Reporte de recaudacion por producto" << endl;
            Reporte_RecaudacionPorProducto(codigoProductos, nombreProducto, recaudacionPorProducto,
                                           cantidadVendidaPorProducto, stockDisponible, cantidadProductos);
            break;
        case 2:
            cout << endl << "2. Reporte de porcentaje de ventas por forma de pago" << endl;
            Reporte_PorcentajePorFormaDePago(nombreFormaPago, ventasPorFormaPago);
            break;
        case 3:
            cout << endl << "3. Reporte de ventas por marca y forma de pago" << endl;
            Reporte_VentasPorMarcaYFormaPago(nombresMarca, cantidadMarcas,ventasEf, ventasMp, ventasTr, ventasTc, ventasCt);
            break;
        case 4:
            cout << endl << "4. Reporte de productos sin ventas" << endl;
            Reporte_ProductosSinVentas(codigoProductos, nombreProducto, cantidadVendidaPorProducto, cantidadProductos);
            break;
        case 5:
            cout << endl << "5. Reporte de Top 10 clientes + sorteo de cupones" << endl;
            Reporte_Top10ClientesYCupones(comprasPorCliente, cantidadCodigoClientes);
            break;
        case 6:
            cout << endl << "Salir del submenu reportes" << endl;
            break;
        default:
            cout << endl << "Opcion invalida. Intente nuevamente." << endl << endl;
        }
    }
}
