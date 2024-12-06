#Makefile del proyecto
CC = gcc #variables
CFLAGS = -Wall -g
LIBRARY = libinventario.a #libreria estatica
EXEC = exe #nombre del ejecutable

# Archivos principales a ejecutar
SRCS = main.c inventario.c

# objeto
OBJS = $(SRCS:.c=.o)

# Target por defecto: compilar y vincular el programa principal con la biblioteca estatica
all: $(EXEC)

# Target para generar la biblioteca estatica
lib: $(LIBRARY)

# Generacion de la biblioteca estatica
$(LIBRARY): inventario.o
	ar rcs $(LIBRARY) inventario.o

# Compilacion del programa principal
$(EXEC): $(OBJS) $(LIBRARY)
	$(CC) $(OBJS) -L. -linventario -o $(EXEC)

# Compilacion de los archivos fuente a objetos
%.o: %.c inventario.h
	$(CC) $(CFLAGS) -c $< -o $@

# Target para limpiar archivos temporales y ejecutables
clean:
	rm -f $(OBJS) $(EXEC) $(LIBRARY)

# Target para ejecutar el programa compilado
run: $(EXEC)
	./$(EXEC)