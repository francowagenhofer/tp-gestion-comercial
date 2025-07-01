#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <string>

using namespace std;

// -------------------------------------------------------------------------------------------------//
// LOTE 1 - MARCAS

int pedirCodigoMarca();

string pedirNombreMarca();

int CargarMarcas(int codigos[], string nombres[], int marcas_requeridas);

void ListarMarcas(int codigos[], string nombres[], int cantidadMarcas);

// -------------------------------------------------------------------------------------------------//
// LOTE 2 - PRODUCTOS

void CargarProductos(int codigoProductos[], string nombreProducto[], float precioVenta[],
                     float precioCompra[], int stockDisponible[], int codigoMarca[],
                     int codigos[], int cantidadMarcas, int cantidadProductos);

void ListarProductos(int codigoProductos[], string nombreProducto[], float precioVenta[],
                     float precioCompra[], int stockDisponible[], int codigoMarca[], int cantidadProductos);

// -------------------------------------------------------------------------------------------------//
// LOTE 3 - FORMAS DE PAGO

bool CodigoValido(string codigo, string codigos_validos[], int cantidadFormasPago);

bool CodigoRepetido(string codigo, string codigo_FormaDePago[], int cantidadFormasPago_actual);

bool NombreValido(string nombre, string nombres_validos[], int cantidadFormasPago);

bool NombreRepetido(string nombre, string nombre_FormaDePago[], int cantidadFormasPago_actual);

void CargarFormasDePago(string codigo_FormaDePago[], string nombre_FormaDePago[],
                        int porcentaje_FormaDePago[], int cantidadFormasPago);

void ListarFormasDePago(string codigo_FormaDePago[], string nombre_FormaDePago[],
                        int porcentaje_FormaDePago[], int cantidadFormasPago);

// -------------------------------------------------------------------------------------------------//
// LOTE 4 - VENTAS

int PedirCodigoProducto(int codigoProductos[], int cantidadProductos);

int PedirFormaDePago(string codigoFormaPago[], int cantidadFormasPago);

int PedirCantidadVendida();

int PedirCodigoCliente();

int PedirDiaVenta();

void CargarVentas(
    int codigoProductos[], int cantidadProductos,  string codigoFormaPago[],
    int cantidadFormasPago, float precioVenta[], int stockDisponible[], int codigos[],
    int codigosMarcaProducto[], int cantidadMarcas, int porcentaje_FormaDePago[],

    int cantidadVendidaPorProducto[], float recaudacionPorProducto[], int ventasPorFormaPago[],
    int ventasEf[], int ventasMp[], int ventasTr[], int ventasTc[], int ventasCt[],
    int comprasPorCliente[]);

// -------------------------------------------------------------------------------------------------//
// 5 - REPORTES

// Reportes 1
void Reporte_RecaudacionPorProducto(int codigoProductos[], string nombreProducto[], float recaudacionPorProducto[],
                                    int cantidadVendidaPorProducto[], int stockDisponible[], int cantidadProductos);

// Reporte 2
void Reporte_PorcentajePorFormaDePago(string nombreFormaPago[], int ventasPorFormaPago[], int cantidadFormasPago);

// Reporte 3
void Reporte_VentasPorMarcaYFormaPago(string nombresMarca[], int cantidadMarcas, int ventasEf[],
                                      int ventasMp[], int ventasTr[], int ventasTc[], int ventasCt[]);

// Reporte 4
void Reporte_ProductosSinVentas(int codigoProductos[], string nombreProducto[],
                                int cantidadVendidaPorProducto[], int cantidadProductos);

// Reporte 5
void Reporte_Top10ClientesYCupones(int comprasPorCliente[], int cantidadCodigoClientes);


// -------------------------------------------------------------------------------------------------//
// VALIDACIONES DEL MENU

bool ValidarMarcasCargadas(int cantidadMarcas, int marcas_requeridas);

bool ValidarProductosCargados(string nombreProducto[]);

bool ValidarFormasPagoCargadas(string nombre_FormaDePago[]);

bool HayVentasCargadas(int cantidadVendidaPorProducto[], int cantProductos);


#endif // FUNCIONES_H_INCLUDED
