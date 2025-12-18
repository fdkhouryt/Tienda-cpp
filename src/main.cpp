#include <iostream>
#include <string>

#include "../include/interfaces/Fabrica.h"
#include "../include/interfaces/IControladorUsuario.h"
#include "../include/interfaces/IControladorCliente.h"
#include "../include/interfaces/IControladorVendedor.h"

#include "../include/controladores/FechaActual.h"
using namespace std;

/*******************************
        Archivos CSV
*******************************/
#include <sstream>
#include <fstream>

const string COMENTARIOS[25][6] = {
    {"CM1", "US4", "PR1", "01/06/2024", "¿La camiseta azul esta disponible en talla M?", ""},
    {"CM2", "US2", "PR1", "01/06/2024", "Si, tenemos la camiseta azul en talla M.", "CM1"},
    {"CM3", "US5", "PR1", "02/06/2024", "¿Es de buen material? Me preocupa la durabilidad.", "CM2"},
    {"CM4", "US4", "PR1", "02/06/2024", "He comprado antes y la calidad es buena.", "CM3"},
    {"CM5", "US7", "PR1", "02/06/2024", "¿Como es el ajuste? ¿Es ajustada o holgada?", ""},
    {"CM6", "US5", "PR2", "02/06/2024", "¿Cual es la resolucion del Televisor LED?", ""},
    {"CM7", "US1", "PR2", "02/06/2024", "El televisor LED tiene una resolucion de 4K UHD.", "CM6"},
    {"CM8", "US8", "PR2", "03/06/2024", "¿Tiene soporte para HDR10?", ""},
    {"CM9", "US1", "PR2", "03/06/2024", "Si, soporta HDR10.", "CM8"},
    {"CM10", "US7", "PR3", "03/06/2024", "¿La chaqueta de cuero es resistente al agua?", ""},
    {"CM11", "US2", "PR3", "03/06/2024", "No, la chaqueta de cuero no es resistente al agua.", "CM10"},
    {"CM12", "US5", "PR3", "04/06/2024", "¿Viene en otros colores?", "CM10"},
    {"CM13", "US2", "PR3", "04/06/2024", "Si, tambien esta disponible en marron.", "CM12"},
    {"CM14", "US9", "PR3", "04/06/2024", "¿Es adecuada para climas frios?", "CM10"},
    {"CM15", "US8", "PR4", "04/06/2024", "¿El microondas digital tiene funcion de descongelacion rapida?", ""},
    {"CM16", "US1", "PR4", "04/06/2024", "Si, el microondas digital incluye una funcion de descongelacion rapida.", "CM15"},
    {"CM17", "US7", "PR4", "05/06/2024", "¿Cuantos niveles de potencia tiene?", "CM15"},
    {"CM18", "US1", "PR4", "05/06/2024", "Tiene 10 niveles de potencia.", "CM17"},
    {"CM19", "US9", "PR4", "05/06/2024", "¿Es facil de limpiar?", "CM15"},
    {"CM20", "US9", "PR5", "05/06/2024", "¿La luz LED se puede controlar con una aplicacion movil?", ""},
    {"CM21", "US3", "PR5", "05/06/2024", "Si, la luz LED se puede controlar a traves de una aplicacion movil.", "CM20"},
    {"CM22", "US8", "PR5", "06/06/2024", "¿Es compatible con Alexa o Google Home?", "CM20"},
    {"CM23", "US3", "PR5", "06/06/2024", "Si, es compatible con ambos.", "CM22"},
    {"CM24", "US7", "PR5", "06/06/2024", "¿Cuanto dura la bateria?", "CM20"},
    {"CM25", "US8", "PR5", "07/06/2024", "¿La aplicacion movil es facil de usar?", "CM20"}
};

const string COMPRAPRODUCTO[14][5] = {
    {"CP1", "CO1", "PR2", "2", "Si"},
    {"CP2", "CO1", "PR4", "1", "No"},
    {"CP3", "CO1", "PR8", "1", "No"},
    {"CP4", "CO2", "PR5", "1", "Si"},
    {"CP5", "CO3", "PR14", "10", "Si"},
    {"CP6", "CO4", "PR11", "1", "Si"},
    {"CP7", "CO4", "PR12", "1", "Si"},
    {"CP8", "CO4", "PR13", "1", "Si"},
    {"CP8", "CO5", "PR3", "2", "No"},
    {"CP8", "CO5", "PR6", "3", "Si"},
    {"CP9", "CO6", "PR1", "2", "No"},
    {"CP10", "CO7", "PR1", "3", "Si"},
    {"CP11", "CO8", "PR1", "4", "No"},
    {"CP12", "CO9", "PR1", "5", "No"}
};

const string COMPRAS[9][5] = {
    {"CO1", "US4", "01/05/2024", "68389.293", "PM1"},
    {"CO2", "US4", "01/05/2024", "599.99", "-"},
    {"CO3", "US5", "15/05/2024", "150000", "-"},
    {"CO4", "US7", "25/04/2024", "11734", "-"},
    {"CO5", "US4", "20/05/2024", "1263.984", "PM2"},
    {"CO6", "US5", "12/05/2024", "2800", "-"},
    {"CO7", "US7", "13/05/2024", "4200", "-"},
    {"CO8", "US8", "14/05/2024", "5600", "-"},
    {"CO9", "US9", "15/05/2024", "7000", "-"}
};

const string PRODUCTOS[15][8] = {
    {"PR1", "1", "Camiseta Azul", "Camiseta de poliester, color azul", "50", "1400", "R", "US2"},
    {"PR2", "2", "Televisor LED", "Televisor LED 55 pulgadas", "30", "40500", "E", "US1"},
    {"PR3", "3", "Chaqueta de Cuero", "Chaqueta de cuero, color negro", "20", "699.99", "R", "US2"},
    {"PR4", "4", "Microondas Digital", "Microondas digital, 30L", "15", "1199.99", "E", "US1"},
    {"PR5", "5", "Luz LED", "Luz Bluetooth LED", "40", "599.99", "O", "US3"},
    {"PR6", "6", "Pantalones Vaqueros", "Pantalones vaqueros, talla 32", "25", "60", "R", "US2"},
    {"PR7", "7", "Auriculares Bluetooth", "Auriculares bluethooth para celular", "35", "199.99", "O", "US3"},
    {"PR8", "8", "Refrigerador", "Refrigerador de doble puerta", "10", "15499", "E", "US1"},
    {"PR9", "9", "Cafetera", "Cafetera de goteo programable", "50", "23000", "E", "US1"},
    {"PR10", "10", "Zapatillas Deportivas", "Zapatillas para correr, talla 42", "20", "5500", "R", "US2"},
    {"PR11", "11", "Mochila", "Mochila de viaje, 40L", "30", "9000", "O", "US2"},
    {"PR12", "12", "Plancha de Ropa", "Plancha a vapor, 1500W", "25", "2534", "E", "US3"},
    {"PR13", "13", "Gorra", "Gorra para deportes, color rojo", "50", "200", "R", "US10"},
    {"PR14", "14", "Tablet", "Tablet Android de 10 pulgadas", "15", "15000", "E", "US3"},
    {"PR15", "15", "Reloj de Pared", "Reloj de pared vintage", "20", "150.50", "O", "US10"}
};

const string PROMOCIONPRODUCTO[7][4] = {
    {"PP1", "PM1", "PR2", "1"},
    {"PP2", "PM1", "PR4", "1"},
    {"PP3", "PM1", "PR8", "1"},
    {"PP4", "PM2", "PR3", "2"},
    {"PP5", "PM2", "PR6", "3"},
    {"PP6", "PM3", "PR5", "2"},
    {"PP7", "PM4", "PR14", "1"}
};

const string PROMOCIONES[4][6] = {
    {"PM1", "Casa nueva", "Para que puedas ahorrar en la casa nueva", "30", "25/10/2024", "US1"},
    {"PM2", "Fiesta", "Para que no te quedes sin ropa para las fiestas", "20", "26/10/2024", "US2"},
    {"PM3", "Domotica", "Para modernizar tu casa", "10", "26/10/2024", "US3"},
    {"PM4", "Liquidacion", "Hasta agotar stock", "10", "26/03/2024", "US3"}
};

const string CLIENTES[5][4] = {
    {"US4", "Av. 18 de Julio", "456", "Melo"},
    {"US5", "Rondeau", "1617", "Montevideo"},
    {"US7", "Paysandú", "2021", "Salto"},
    {"US8", "Av. Rivera", "1819", "Mercedes"},
    {"US9", "Av. Brasil", "1011", "Montevideo"}
};

const string VENDEDORES[5][2] = {
    {"US1", "212345678001"},
    {"US2", "356789012345"},
    {"US3", "190123456789"},
    {"US6", "321098765432"},
    {"US10", "445678901234"}
};

const string USUARIOS[10][5] = {
    {"US1", "V", "ana23", "qwer1234", "15/05/1988"},
    {"US2", "V", "carlos78", "asdfghj", "18/06/1986"},
    {"US3", "V", "diegom", "zxcvbn", "28/07/1993"},
    {"US4", "C", "juan87", "1qaz2wsx", "20/10/1992"},
    {"US5", "C", "laura", "3edc4rfv", "22/09/1979"},
    {"US6", "V", "maria01", "5tgb6yhn", "25/03/1985"},
    {"US7", "C", "natalia", "poiuyt", "14/04/1982"},
    {"US8", "C", "pablo10", "lkjhgv", "30/11/1995"},
    {"US9", "C", "roberto", "mnbvcx", "12/08/1990"},
    {"US10", "V", "sofia25", "1234asdf", "07/12/1983"}
};



Fabrica * fabrica = Fabrica::getInstancia();

IControladorUsuario * cUsuario = fabrica->getControladorUsuario();
IControladorCliente * cCliente = fabrica->getControladorCliente();
IControladorVendedor * cVendedor = fabrica->getControladorVendedor();

FechaActual* fActual = FechaActual::getInstancia();

map<string, string> usuariosID;
map<string, string> productosID;
map<string, string> promocionesID;
map<string, string> comprasID;
map<string, string> comentariosID;

/*********************
    VALIDACIONES
**********************/

bool noRulesString(string text){return true;}
bool noRulesInt(int text){return true;}

bool rulesPassword(string password){
    return password.length() >= 6;
}
bool rulesRUT(string RUT){
    return RUT.length() == 12;
}
bool rulesDay(int day, int month, int year){
    int daysInMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (year % 4 && !(year % 100))
        daysInMonth[1] = 29;
    
    return day > 0 && day <= daysInMonth[month-1];
}
bool rulesMonth(int month){
    return month > 0 && month <= 12;
}
bool rulesPercentage(int percentage){
    return percentage > 0 && percentage <= 99;
}
bool rulesCategoria(int categoria){
    return categoria > 0 && categoria <= 3;
}
bool rulesGT0(int number){return number>0;} 

bool pedirBoolean(string nombre) {
    int in = -1;
    string aux = "";
    try{
        cout << nombre << endl;
        getline(cin,aux);
        in = stoi(aux);
    }catch(const exception& e){
        in = -1;
    }
    
    while (in != 1 && in != 0){
        cout << "Opción no válida" << endl;
        try{
            getline(cin,aux);
            in = stoi(aux);
        }catch(const exception& e){
            in = -1;
        }
    } ;
    return in == 1;
}

int pedirInt(string nombre, bool(*rules)(int)){
    int in = -1;
    string aux = "";
    bool valid = true;
    
    cout << "Ingrese un/una " << nombre << endl;
    try{
        getline(cin,aux);
        in = stoi(aux);
    }catch(const exception& e){
        in = -1;
    }
    valid = in >= 0 && rules(in);
    
    while (!valid){
        cout << nombre << " no válido" << endl;
        try{
            cout << "Ingrese un/una " << nombre << endl;
            getline(cin,aux);
            in = stoi(aux);
        }catch(const exception& e){
            in = -1;
        }
        valid = in >= 0 && rules(in);
    } ;
    return in;
}
string pedirString(string nombre, bool(*rules)(string)){
    string in = "";
    cout << "Ingrese un/una " << nombre << endl;
    try{
        getline(cin,in);
    }catch(const exception& e){
        in = -1;
    }    
    while (in == "" || !rules(in)){
        cout << nombre << " no válido" << endl;
        try{
            getline(cin,in);
        }catch(const exception& e){
            in = -1;
        }
    } ;
    return in;
}
Categoria pedirCategoria() {
    cout << "Seleccione una categoria" << endl;
    cout << "1-Electrodomesticos" << endl;
    cout << "2-Ropa" << endl;
    cout << "3-Otro" << endl;
    while(true){
    int in = pedirInt("Categoria", rulesCategoria);
    switch(in) {
        case 1:
            return Electrodomesticos;
        case 2:
            return Ropa;
        case 3:
            return Otro;
        default:
            cout << "Opción no válida" << endl;
        }    
    }
}

string pedirDeSetString(string nombre, set<string> cosas){
    if (cosas.size() == 0){
        cout << "No hay " << nombre << endl;
        return "";
    }
    string in = pedirString(nombre,noRulesString);
    while (cosas.find(in) == cosas.end()){
        cout << nombre << " no encontrado" << endl;
        in = pedirString(nombre,noRulesString);  
    }
    return in;
}
int pedirDeSetInt(string nombre, set<int> cosas){
    if (cosas.size() == 0){
        cout << "No hay " << nombre << endl;
        return 0;
    }
    int in = pedirInt(nombre,noRulesInt);
    while (cosas.find(in) == cosas.end()){
        cout << nombre << " no encontrado" << endl;
        in = pedirInt(nombre,noRulesInt);  
    }
    return in;
}



/*********************
    AUXILIARES
**********************/

bool pedirYSeleccionarUsuario(){
    set<string> nicknames = cUsuario->listarUsuarios();
    if (nicknames.size() == 0){
        cout << "No hay usuarios en el sistema" << endl;
        return false;
    }
    
    cout << "Lista de usuarios:" << endl;
    for (string nickname:nicknames){
       cout << nickname << endl;
    }
    cout << "Seleccione uno de los usuarios" << endl;
    string nickname = pedirDeSetString("Nickname", nicknames);
    cUsuario->seleccionarUsuario(nickname);
    return true;
}
bool pedirYSeleccionarVendedor(){
    set<string> vendedores = cVendedor->listarVendedores();
    if (vendedores.size() == 0){
        cout << "No hay vendedores en el sistema" << endl;
        return false;
    }
    cout << "Lista de vendedores:" << endl;
    for (string nickname:vendedores){
       cout << nickname << endl;
    }
    cout << "Seleccione uno de los vendedores" << endl;
    string nickname = pedirDeSetString("Nickname", vendedores);
    cVendedor->seleccionarVendedor(nickname);
    return true;
}
bool pedirYSeleccionarCliente(){
    set<string> clientes = cCliente->listarNicknameClientes();
    if (clientes.size() == 0){
        cout << "No hay clientes en el sistema" << endl;
        return false;
    }
    cout << "Lista de clientes:" << endl;
    for (string nickname:clientes){
       cout << nickname << endl;
    }
    cout << "Seleccione uno de los clientes" << endl;
    string nickname = pedirDeSetString("Nickname", clientes);
    cCliente->seleccionarCliente(nickname);
    return true;
}
int listarYPedirIdComentarios(set<DTComentario> comentarios){
    if (comentarios.size() == 0){
        cout << "No hay comentarios" << endl;
        return 0;
    }
    
    set<int> idsComentarios;
    cout << "--Comentarios--" << endl;
    for (DTComentario c:comentarios){
        cout << c.toString() << endl;
        idsComentarios.insert(c.getId());
    }
    
    cout << "Seleccione uno de los id comentario" << endl;
    int idComentario = pedirDeSetInt("Id comentario ",idsComentarios);
    return idComentario;
}
int listarYPedirIdProducto(set<DTProducto> productos){
    if (productos.size() == 0){
        cout << "No hay productos" << endl;
        return 0;
    }
    set<int> idsProductos;
    cout << "--Productos--" << endl;
    for (DTProducto p:productos){
        cout << p.toString() << endl;
        idsProductos.insert(p.getCodigo());
    }
    
    cout << "Seleccione uno de los codigo producto" << endl;
    int idsProducto = pedirDeSetInt("Codigo producto ",idsProductos);
    return idsProducto;
}

DTFecha pedirFecha(){
    int anio = pedirInt("Anio", noRulesInt);
    int mes = pedirInt("Mes",rulesMonth);
    int dia = pedirInt("Dia",noRulesInt);
    while (!rulesMonth(mes)){
        cout << "Mes no válido" << endl;
        mes = pedirInt("Mes", rulesMonth);
    }
    while (!rulesDay(dia,mes,anio)){
        cout << "Dia no válido para ese mes y anio" << endl;
        dia = pedirInt("Dia",noRulesInt);
    }
    return *new DTFecha(dia,mes,anio);
}

bool pedirConfirmacion(string mensaje){
    mensaje = mensaje == "" ? "Seguir" : mensaje; 
    cout << "1-" << mensaje << endl << "0-Terminar" << endl;
    return pedirBoolean("Confirmar?");
}

/*********************
    CASOS DE USO
**********************/
// Usuarios
void altaUsuario(){
    // Pedir datos de usuario
    cout << "Ingrese el nombre de usuario" << endl;
    string nickname = pedirString("Nickname",noRulesString);
    if (cUsuario->isNicknameUsado(nickname)){
        cout << "El nickname ya está en uso" << endl;
        return;
    }
    
    cout << "Ingrese la contrasenia del cliente" << endl;
    string password = pedirString("Contrasenia",rulesPassword);
    cout << "Ingrese la fecha de nacimiento" << endl;
    cUsuario->ingresarUsuario(nickname,password,pedirFecha());

    // Pedir si es cliente
    cout << "Tipos de Usuario:" << endl
         << "0- Cliente" << endl
         << "1- Vendedor" << endl;   

    int esCliente = pedirBoolean("");
    if (esCliente == 0){
        cout << "Ingrese la calle del cliente" << endl;
        string calle = pedirString("Calle",noRulesString);
        cout << "Ingrese la ciudad del cliente" << endl;
        string ciudad = pedirString("Ciudad",noRulesString);
        cout << "Ingrese el numero del cliente" << endl;
        int numero = pedirInt("Numero",noRulesInt);

        cUsuario->ingresarUbicacion(DTDireccion(calle,ciudad,numero));
    }else{
        cout << "Ingrese el RUT del vendedor" << endl;
        string RUT = pedirString("RUT",rulesRUT);
        cUsuario->ingresarDatosVendedor(RUT);
    }
    
    cUsuario->darDeAlta();
}
void listadoUsuarios(){
    set<DTUsuario*> usuarios = cUsuario->listarDatosUsuarios();
    for(DTUsuario* usuario:usuarios){
        cout << usuario->toString() << endl;
        cout << endl;
    }
    cout << endl;
}

void expedienteUsuario(){
    cout << "Seleccione el usuario para ver el expediente" << endl;
    bool wasUsuarioSeleccionado = pedirYSeleccionarUsuario();
    if (!wasUsuarioSeleccionado)
        return;
    
    cout << cUsuario->infoUsuario()->toString() << endl;
}

// Productos
void altaProducto(){
    bool wasUsuarioSeleccionado = pedirYSeleccionarVendedor();
    if (!wasUsuarioSeleccionado)
        return;
    
    cout << "Ingrese el nombre del producto" << endl;
    string nombre = pedirString("Nombre", noRulesString);
    cout << "Ingrese el precio del producto" << endl;
    int precio = pedirInt("Precio ", rulesGT0);
    cout << "Ingrese la descripcion del producto" << endl;
    string descripcion = pedirString("Descripcion ",noRulesString);
    cout << "Ingrese la categoria del producto" << endl;
    Categoria categoria = pedirCategoria();
    cout << "Ingrese el stock del producto" << endl;
    int stock = pedirInt("Stock ", noRulesInt);

    cVendedor->nuevoProducto(nombre,precio,descripcion,categoria,stock);
}
void consultarProducto(){
    set<DTProducto> productos = cVendedor->listarProductos();
    int idProducto = listarYPedirIdProducto(productos);
    if(idProducto == 0)
        return;
    DTProductoExt info = cVendedor->obtenerInformacionProducto(idProducto);
    cout << info.toString() << endl;
}
void enviarProducto(){
    bool wasUsuarioSeleccionado = pedirYSeleccionarVendedor();
    if (!wasUsuarioSeleccionado)
        return;

    set<DTProducto> productos = cVendedor->listarProductosEnviosPend();
    int idProducto = listarYPedirIdProducto(productos);
    if(idProducto == 0)
        return;
    cVendedor->seleccionarProducto(idProducto);
    set<DTCompraNoEnviada> compraProductos = cVendedor->listarComprasProductoPend();
    if (compraProductos.size() == 0){
        cout << "No hay compras con envío pendiente para ese producto" << endl;
        return;
    }
    int* ids = new int[compraProductos.size()+1];
    set<int> indicesCompras;
    int i = 1;
    cout << "--Compras--" << endl;
    for (DTCompraNoEnviada cp:compraProductos){
        cout << i << "- " << cp.toString() << endl;
        indicesCompras.insert(i);
        ids[i] = cp.getId();
        i++;
    }
    
    cout << "Seleccione la compra deseada con el indice" << endl;
    int indice = pedirDeSetInt("Codigo compra ",indicesCompras);
    cout << "Id de compra: " << ids[indice] <<endl;
    cVendedor->enviarCompra(ids[indice]);
    delete [] ids;
}

//  Promociones
void crearPromocion(){
    // pedir datos promo
    cout << "Ingrese el nombre de la promocion" << endl;
    string nombre = pedirString("Nombre", noRulesString);
    cout << "Ingrese la descripcion de la promocion" << endl;
    string descripcion = pedirString("Descripcion", noRulesString);
    DTFecha fechaDeVencimiento = pedirFecha();
    cout << "Ingrese el descuento de la promocion" << endl;
    double descuento = static_cast<double>(pedirInt("Descuento", rulesPercentage))/100.0;
    bool wasUsuarioSeleccionado = pedirYSeleccionarVendedor();
    if (!wasUsuarioSeleccionado)
        return;
    set<DTProductoExt> res = cVendedor->listarProductosVendedor();
    if(res.empty()){
        cout << "No hay productos asociados al Vendedor" << endl;
        return;
    }
    cVendedor->nuevaPromocionDatos(nombre,descripcion,fechaDeVencimiento,descuento);
    set<DTProductoExt> productosVendedor = cVendedor->listarProductosVendedor();
    set<int> idProductos;
    cout << "--Productos del vendedor--" << endl;
    for (DTProductoExt pe:productosVendedor){
        idProductos.insert(pe.getCodigo());
        cout << pe.getCodigo() << "- " << pe.getNombre() << endl;
    }
    int idProducto = 0;
    int cantMin = 0;
    bool pedirOtro = false;
    do{
        cout << "Ingrese una id de producto" << endl;
        idProducto = pedirDeSetInt("Codigo producto",idProductos);
        cout << "Ingrese la cantida minima para el producto" << endl;
        cantMin = pedirInt("Cantidad minima",rulesGT0);
        cVendedor->agregarProductos(idProducto,cantMin);

        pedirOtro = pedirBoolean("Agregar otro producto?\n1-Si\n0-no");
    }while (pedirOtro);
    
    cVendedor->altaPromocion();
}
void consultarPromocion(){
    set<DTPromocion> promos = cVendedor->listarPromocionesVigentes(FechaActual::getInstancia()->get());
    if (promos.empty()){
        cout << "No hay promociones vigentes" << endl;
        return;
    }
    set<string> nombresPromos;
    cout << "--Promociones--" << endl;
    for (DTPromocion p:promos){
        cout << p.getNombre() << endl;
        nombresPromos.insert(p.getNombre());
    }
    
    // preguntar si queire seleccionar una promo
    cout << "Quiere seleccionar una Promocion?:" << endl
         << "0- No" << endl
         << "1- Si" << endl;   

    int verPromo = pedirBoolean("");
    if (verPromo == 1){
        cout << "Ingrese el nombre de la promocion" << endl;
        string nombre = pedirDeSetString("Nombre promocion",nombresPromos);
        if (nombre == "")
            return;
        
        DTPromocion promo = cVendedor->seleccionarPromocion(nombre);
        cout << promo.toString();
    }
    
}

// Compra
void realizarCompra(){
    bool wasUsuarioSeleccionado = pedirYSeleccionarCliente();
    if (!wasUsuarioSeleccionado)
        return;

    set<DTProductoExt> productos = cVendedor->listarProductosExt();
    if (productos.size() == 0){
        cout << "No hay productos en el sistema" << endl;
        return;
    }
    
    set<int> idProductos;
    map<int,int> idAStockProductos;
    cout << "--Productos--" << endl;
    for (DTProductoExt pe:productos){
        idProductos.insert(pe.getCodigo());
        idAStockProductos[pe.getCodigo()] = pe.getStock();
        cout << pe.getCodigo() <<"- Nombre:"<<pe.getNombre() <<"; Stock:"<<pe.getStock()<<";"<< endl;
    }
    int idProducto = 0;
    int cantidad = 0;
    bool pedirOtro = false;
    do{
        cout << "Ingrese una id del producto a comprar" << endl;
        idProducto = pedirDeSetInt("Codigo producto",idProductos);
        cout << "Ingrese la cantida de productos a comprar" << endl;
        cantidad = pedirInt("Cantidad",rulesGT0);
        if (idAStockProductos[idProducto] >= cantidad)
            cCliente->comprarProducto(idProducto,cantidad);
        else
            cout << "No hay suficiente stock" << endl;
        
        pedirOtro = pedirBoolean("Agregar otro producto?\n1-Si\n0-no");
    }while (pedirOtro);

    DTCompra compra = cCliente->listarCompra();
    cout << compra.toString();
    cCliente->confirmarCompra();
}

// Comentarios
void dejarComentario(){
    cout << "Seleccione el usuario que va a comentar" << endl;
    bool wasUsuarioSeleccionado = pedirYSeleccionarUsuario();
    if (!wasUsuarioSeleccionado)
        return;   

    set<DTProducto> productos = cVendedor->listarProductos();
    int idProducto = listarYPedirIdProducto(productos);
    if(idProducto == 0)
        return;
    cVendedor->seleccionarProducto(idProducto);

    // preguntar si se quiere responder
    cout << "1-Nuevo comentario" << endl << "0-Responder" << endl;
    bool responder = !pedirBoolean("");
    if(responder){
        set<DTComentario> comentariosProducto = cVendedor->listarComentariosProducto();
        int idComentario = listarYPedirIdComentarios(comentariosProducto);
        if (idComentario == 0)
         return;
        
        cUsuario->seleccionarComentario(idComentario);
        cout << "Ingresar texto de comentario: " << endl;
        string texto = pedirString("Texto", noRulesString);
        cUsuario->responderComentario(texto);
    }else{
        cout << "Ingresar texto de comentario: " << endl;
        string texto = pedirString("Texto", noRulesString);
        cUsuario->agregarComentario(texto);
    }
}
void eliminarComentario(){
    cout << "Seleccione el usuario del que va a eliminar un comentario" << endl;
    bool wasUsuarioSeleccionado = pedirYSeleccionarUsuario();
    if (!wasUsuarioSeleccionado)
        return;
    set<DTComentario> comentarios = cUsuario->listarComentariosUsuario();
    int idComentario = listarYPedirIdComentarios(comentarios);
    if (idComentario == 0)
         return;
    cUsuario->eliminarComentario(idComentario);
}

// Suscripciones
void suscribirseANotificaciones(){
    bool wasUsuarioSeleccionado = pedirYSeleccionarCliente();
    if (!wasUsuarioSeleccionado)
        return;
    set<string> noSuscripciones = cCliente->listarVendedoresNoCliente();
    if (noSuscripciones.size() == 0){
        cout << "No hay vendedores para suscribirse" << endl;
        return;
    }
    cout << "--Vendedores--" << endl;
    for (string nick:noSuscripciones)
        cout << nick << endl;
    
    
    bool agregarOtro = false;
    do{
        string vendedor = pedirDeSetString("Vendedor", noSuscripciones);
        if (vendedor == "")
            return;
        cCliente->agregarVendedor(vendedor);
        agregarOtro = pedirConfirmacion("Quiere agregar otra suscripcion?");
    }while (agregarOtro);     

    cCliente->suscribirAVendedores();
}
void consultaNotificaciones(){
    bool wasUsuarioSeleccionado = pedirYSeleccionarCliente();
    if (!wasUsuarioSeleccionado)
        return;
    set<DTNotificacion> notif = cCliente->consultaNotificacionesCliente();
    if (notif.size() == 0){
        cout << "El cliente no tiene notificaciones" << endl;
        return;
    }
    
    for (DTNotificacion n:notif)
        cout << n.toString() << endl;
}
void eliminarSuscriptores(){
    bool wasUsuarioSeleccionado = pedirYSeleccionarCliente();
    if (!wasUsuarioSeleccionado)
        return;
    set<string> noSuscripciones = cCliente->listarSuscripciones();
    if (noSuscripciones.size() == 0){
        cout << "Cliente no suscrito a ningún vendedor" << endl;
        return;
    }
    cout << "--Suscripciones--" << endl;
    for (string nick:noSuscripciones)
        cout << nick << endl;
    bool agregarOtro = false;
    do{
        string vendedor = pedirDeSetString("Vendedor", noSuscripciones);
        if (vendedor == "")
            return;
        cCliente->agregarVendedor(vendedor);
        agregarOtro = pedirConfirmacion("Quiere eliminar otra suscripcion?");
    }while (agregarOtro);    

    cCliente->eliminarSuscripciones();
}

/*******************************
        Auxiliares CSV
*******************************/
//Para cambiar fechas de strings a ints
void cambioFecha(const string& dateStr, int& day, int& month, int& year) {
    // Crear un stringstream a partir del string de entrada
    stringstream dateStream(dateStr);
    string token;
    
    // Extraer el día
    if (getline(dateStream, token, '/')) {
        day = stoi(token);
    }
    
    // Extraer el mes
    if (getline(dateStream, token, '/')) {
        month = stoi(token);
    }
    
    // Extraer el año
    if (getline(dateStream, token)) {
        year = stoi(token);
    }
}

int findIDCompra(set<DTCompraNoEnviada> compras, DTFecha fecha, string nombre){
    set<DTCompraNoEnviada>::iterator it = compras.begin();
    while(it != compras.end()){
        if((it->getFecha() == fecha) && (it->getNickname() == nombre)) return it->getId();
        it++;
    }
    return -1;
}

/*******************************
        cargar datos CSV
*******************************/
//alta de usuarios
void leerDatosUsuarios() {
    string nombre, password, calle, ciudad, tipo, id, fecha, numeroS, RUT;
    int anio, mes, dia, numero;
    int cli = 0;
    int vend = 0;
    for(int i = 0; i < 10; i++){
        id = USUARIOS[i][0];
        tipo = USUARIOS[i][1];
        nombre = USUARIOS[i][2];
        password = USUARIOS[i][3];
        fecha = USUARIOS[i][4];
        cambioFecha(fecha, dia, mes, anio);

        cUsuario->ingresarUsuario(nombre, password, DTFecha(dia, mes, anio));

        if (tipo == "C") {
            id = CLIENTES[cli][0];

            calle = CLIENTES[cli][1];
            numero = stoi(CLIENTES[cli][2]);
            ciudad = CLIENTES[cli][3];
            cUsuario->ingresarUbicacion(DTDireccion(calle, ciudad, numero));
            cli++;
        } else if (tipo == "V") {
            id = VENDEDORES[vend][0];
            RUT = VENDEDORES[vend][1];
            vend++;
            cUsuario->ingresarDatosVendedor(RUT);
        }
        cUsuario->darDeAlta();
        usuariosID[id] = nombre;
        cout << "Usuario " << id << " cargado" << endl;
    }
}

//alta de Productos
void leerDatosProductos(){
    for(int i = 0; i < 15; i++){ //cambiar a 15
        string id = PRODUCTOS[i][0];
        //falta código
        string nombre = PRODUCTOS[i][2];
        float precio = stof(PRODUCTOS[i][5]);
        string descripcion = PRODUCTOS[i][3];
        string cat = PRODUCTOS[i][6];
        Categoria categoria;
        if (cat == "R") categoria = Ropa;
        else if (cat == "E") categoria = Electrodomesticos;
        else categoria = Otro;
        cVendedor->seleccionarVendedor(usuariosID[PRODUCTOS[i][7]]);
        int stock = stoi(PRODUCTOS[i][4]);
        productosID[id] = nombre;
        cVendedor->nuevoProducto(nombre,precio,descripcion,categoria,stock);
        cout << "Producto " << id << " cargado" << endl;
    }
}

//alta de promociones
//falta terminar

void leerDatosPromociones(){
    int j = 0;

    // pedir datos promo
    for(int i = 0; i < 4; i++){
        string id = PROMOCIONES[i][0];
        string nombre = PROMOCIONES[i][1];
        string descripcion = PROMOCIONES[i][2];
        double descuento = stod(PROMOCIONES[i][3])/100;
        string fecha = PROMOCIONES[i][4];
        int dia, mes, anio;
        cambioFecha(fecha, dia, mes, anio);
        cVendedor->nuevaPromocionDatos(nombre,descripcion,DTFecha(dia, mes, anio),descuento);
        cVendedor->seleccionarVendedor(usuariosID[PROMOCIONES[i][5]]);
        promocionesID[id] = nombre;

        while((j < 7) && (PROMOCIONPRODUCTO[j][1] == id)){
            string nombreP = productosID[PROMOCIONPRODUCTO[j][2]];
            int cantidad = stoi(PROMOCIONPRODUCTO[j][3]);
            int codigoP = cVendedor->findProductoByNombre(nombreP)->getCodigo();
            cVendedor->agregarProductos(codigoP, cantidad);
            j++;
        }
        cVendedor->altaPromocion();
        cout << "Promoción " << id << " cargado" << endl;
    }
}

void leerDatosCompras(){
    int j = 0;
    int compraProducto[8];
    DTFecha compraFecha[8];
    string compraNombreCliente[8];
    string compraProductoID[8];
    int k = 0;

    for (int i = 0; i < 9; i++){
        string id = COMPRAS[i][0];
        string nombreC = usuariosID[COMPRAS[i][1]];
        cCliente->seleccionarCliente(nombreC);
        string fecha = COMPRAS[i][2];
        int dia, mes, anio;
        cambioFecha(fecha, dia, mes, anio);
        DTFecha fechaDT = DTFecha(dia, mes, anio);
        fActual->set(fechaDT);
        

        while((j < 14) && (COMPRAPRODUCTO[j][1] == id)){
            string nombreP = productosID[COMPRAPRODUCTO[j][2]];
            int cantidad = stoi(COMPRAPRODUCTO[j][3]);
            int codigoP = cVendedor->findProductoByNombre(nombreP)->getCodigo();
            cCliente->comprarProducto(codigoP, cantidad);
            if(COMPRAPRODUCTO[j][4] == "Si"){
                compraProducto[k] = codigoP;
                compraFecha[k] = fechaDT;
                compraNombreCliente[k] = nombreC;
                compraProductoID[k] = COMPRAPRODUCTO[j][2];
                k++;
            }
            j++;
        }
        cCliente->listarCompra();
        cCliente->confirmarCompra();
        cout << "Compra " << id << " cargado" << endl;
    }
    
    for(int t = 0; t < 8; t++){
        int idCompra = cCliente->findIDCompra(compraFecha[t], compraNombreCliente[t]);
        cCliente->enviarCompra(idCompra, compraProducto[t]);
        cout << "Producto " << compraProductoID[t] << " enviado" << endl;
    }
    
}

void leerDatosComentarios(){
    for( int i = 0; i < 25; i++){
        string id = COMENTARIOS[i][0];
        string usuarioID = COMENTARIOS[i][1];
        string productoID = COMENTARIOS[i][2];
        string nombreP = productosID[productoID];
        int codP = cVendedor->findProductoByNombre(nombreP)->getCodigo();
        string fecha = COMENTARIOS[i][3];
        int dia, mes, anio;
        cambioFecha(fecha, dia, mes, anio);
        string texto = COMENTARIOS[i][4];
        string respuestaA = COMENTARIOS[i][5];
        comentariosID[id] = texto;
        cUsuario->seleccionarUsuario(usuariosID[usuarioID]);
        cVendedor->seleccionarProducto(codP);
        if (respuestaA != ""){
            int comentarioID = cUsuario->findComentarioByTexto(comentariosID[respuestaA])->getId();
            cUsuario->seleccionarComentario(comentarioID);
            cUsuario->responderComentario(texto);
        }else{
            cUsuario->agregarComentario(texto);
        }
        cout << "Comentario " << id << " cargado" << endl;
    }
}


void leerDatos(){
    leerDatosUsuarios();
    cout << endl;
    leerDatosProductos();
    cout << endl;
    leerDatosPromociones();
    cout << endl;
    leerDatosCompras();
    cout << endl;
    leerDatosComentarios();
    cout << endl;


    cout << "Datos cargados con exito" << endl;
}


/* //////////////////////////////////////////
            MAIN
*////////////////////////////////////////////
int main(){
    int opcion = -1;
    string aux = "";
    int inicio = 1;
    cout << "Fecha inicializada: 26/06/2024" << endl << endl;
    fActual->set(DTFecha(26,6,2024));
    while (opcion != 0){
        if(inicio == 1) {
            cout << "Bienvenido a una denuncia de MercadoLibre" << endl << endl;
            inicio = 0;
        }

        cout << "Seleccione una de las opciones disponibles :D" << endl << endl
         << "0- Salir" << endl
         << "1- Alta de usuario" << endl
         << "2- Listado de usuarios" << endl
         << "3- Expediente usuario" << endl
         << "4- Alta de producto" << endl
         << "5- Consultar producto" << endl
         << "6- Enviar producto" << endl
         << "7- Crear promocion" << endl
         << "8- Consultar promocion" << endl
         << "9- Realizar compra" << endl
         << "10- Dejar comentario" << endl
         << "11- Eliminar comentario" << endl
         << "12- Suscribirse a notificaciones" << endl
         << "13- Consulta de notificaciones" << endl
         << "14- Eliminar suscripciones" << endl
         
         << "15- Cargar Datos" << endl
         << "16- Cambiar Fecha" << endl;

        try{
            getline(cin,aux);
            opcion = stoi(aux);
        }catch(const exception& e){
            opcion = -1;
        }

        switch (opcion){
            case 1:
                altaUsuario();
                cout << endl;
                break;
            case 2:
                listadoUsuarios();
                cout << endl;
                break;
            case 3:
                expedienteUsuario();
                cout << endl;
                break;
            case 4:
                altaProducto();
                cout << endl;
                break;
            case 5:
                consultarProducto();
                cout << endl;
                break;
            case 6:
                enviarProducto();
                cout << endl;
                break;
            case 7:
                crearPromocion();
                cout << endl;
                break;
            case 8:
                consultarPromocion();
                cout << endl;
                break;
            case 9:
                realizarCompra();
                cout << endl;
                break;
            case 10:
                dejarComentario();
                cout << endl;
                break;
            case 11:
                eliminarComentario();
                cout << endl;
                break;
            case 12:
                suscribirseANotificaciones();
                cout << endl;
                break;
            case 13:
                consultaNotificaciones();
                cout << endl;
                break;
            case 14:
                eliminarSuscriptores();
                cout << endl;
                break;
            case 15:
                leerDatos();
                cout << endl;
                break;
            case 16:
                fActual->set(pedirFecha());
                cout << endl;
                break;
            case 0:
                cout << "Ha sido un placer servirle estimado, hasta la pròxima" << endl;
                break;        
            default:
                cout << "Opcion no vàlida :c" << endl;
                break;
        }
        if (opcion != 0){
            cout << "Presione enter para seguir" << endl;
            getline(cin,aux);
        }
    }
}