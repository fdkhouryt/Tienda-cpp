TARGET = $(BIN_DIR)/main
BIN_DIR = ./bin
OBJ_DIR = ./obj
SRC_DIR = ./src
INC_DIR = ./include
SRC_CONCEP = $(SRC_DIR)/conceptos
SRC_CONTROL = $(SRC_DIR)/controladores
SRC_DT = $(SRC_DIR)/datatype
INC_CONCEP = $(INC_DIR)/conceptos
INC_CONTROL = $(INC_DIR)/controladores
INC_DT = $(INC_DIR)/datatype
INC_INTER = $(INC_DIR)/interfaces
NRO_EQUIPO = 82
NRO_LAB = 4

OBJS = $(OBJ_DIR)/main.o \
       $(OBJ_DIR)/Cliente.o \
       $(OBJ_DIR)/Comentario.o \
       $(OBJ_DIR)/Compra-Producto.o \
       $(OBJ_DIR)/Compra.o \
       $(OBJ_DIR)/Promocion-Producto.o \
       $(OBJ_DIR)/Producto.o \
       $(OBJ_DIR)/Promocion.o \
       $(OBJ_DIR)/Usuario.o \
       $(OBJ_DIR)/Vendedor.o \
       $(OBJ_DIR)/ControladorCliente.o \
       $(OBJ_DIR)/ControladorUsuario.o \
       $(OBJ_DIR)/ControladorVendedor.o \
       $(OBJ_DIR)/FechaActual.o \
       $(OBJ_DIR)/DTCliente.o \
       $(OBJ_DIR)/DTClienteExt.o \
       $(OBJ_DIR)/DTComentario.o \
       $(OBJ_DIR)/DTCompra.o \
       $(OBJ_DIR)/DTCompraProducto.o \
       $(OBJ_DIR)/DTCompraNoEnviada.o \
       $(OBJ_DIR)/DTDireccion.o \
       $(OBJ_DIR)/DTFecha.o \
       $(OBJ_DIR)/DTNotificacion.o \
       $(OBJ_DIR)/DTProducto.o \
       $(OBJ_DIR)/DTProductoCantidad.o \
       $(OBJ_DIR)/DTProductoExt.o \
       $(OBJ_DIR)/DTProductoExtVend.o \
       $(OBJ_DIR)/DTPromocion.o \
       $(OBJ_DIR)/DTUsuario.o \
       $(OBJ_DIR)/DTVendedor.o \
       $(OBJ_DIR)/DTVendedorExt.o \
       $(OBJ_DIR)/Fabrica.o

CFLAGS = -Wall -I$(INC_CONCEP) -I$(INC_CONTROL) -I$(INC_INTER) -I$(INC_DT)

# Regla para el target final
$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	g++ $(CFLAGS) $(OBJS) -o $(TARGET)

# Reglas para compilar archivos en SRC_CONCEP
$(OBJ_DIR)/%.o: $(SRC_CONCEP)/%.cpp $(INC_CONCEP)/%.h
	@mkdir -p $(OBJ_DIR)
	g++ -c $(CFLAGS) $< -o $@

# Reglas para compilar archivos en SRC_CONTROL
$(OBJ_DIR)/%.o: $(SRC_CONTROL)/%.cpp $(INC_CONTROL)/%.h
	@mkdir -p $(OBJ_DIR)
	g++ -c $(CFLAGS) $< -o $@

# Reglas para compilar archivos en SRC_DT
$(OBJ_DIR)/%.o: $(SRC_DT)/%.cpp $(INC_DT)/%.h
	@mkdir -p $(OBJ_DIR)
	g++ -c $(CFLAGS) $< -o $@

# Regla para compilar el main
$(OBJ_DIR)/Fabrica.o: $(SRC_CONTROL)/Fabrica.cpp
	@mkdir -p $(OBJ_DIR)
	g++ -c $(CFLAGS) $< -o $@

# Regla para compilar el main
$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp
	@mkdir -p $(OBJ_DIR)
	g++ -c $(CFLAGS) $< -o $@

.PHONY: clean entrega run runVAL

clean:
	@rm -f -r $(OBJ_DIR) $(BIN_DIR)
	@rm -f ${NRO_EQUIPO}_lab${NRO_LAB}.tar.gz

entrega: clean
	tar -czvf ${NRO_EQUIPO}_lab${NRO_LAB}.tar.gz *

run:
	$(BIN_DIR)/main

runVAL:
	valgrind $(BIN_DIR)/main

