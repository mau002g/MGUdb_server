#Construcción del MGUdb_server para Windows

#Compilador y parámetros
cpp = g++
cppflags = -std=c++14 -Wall -m32
linkflags = -s -m32 -std=c++14 -lws2_32 -lmgudb
#Carpetas de direcciones de includes, lib y otras cosas
inc = include
src = src
lib = lib
bin = bin
obj = obj
target = mgudb_server.exe

#lista de objetos a compilar
objetos = $(obj)/main.o $(obj)/AppMain.o $(obj)/com_elements.o $(obj)/database_control.o

#Definciones de los objetivos
all: $(bin)/$(target)

#Enlazamos el programa principal
$(bin)/$(target): $(objetos)
	@echo Enlazando $@
	@$(cpp) -o $@ $(objetos) $(linkflags) -L$(lib) -I$(inc)
	@echo Todo bien.

#Compilamos los archivos fuente
$(obj)/main.o: main.cpp $(src)/AppMain.hpp $(src)/AppMain.cpp
	@echo G++ $@
	@$(cpp) -c main.cpp -o $@ $(cppflags)

$(obj)/AppMain.o: $(src)/AppMain.hpp $(src)/AppMain.cpp
	@echo G++ $@
	@$(cpp) -c $(src)/AppMain.cpp -o $@ $(cppflags) -I$(inc)

$(obj)/com_elements.o: $(inc)/com_elements.hpp $(src)/com_elements.cpp
	@echo G++ $@
	@$(cpp) -c $(src)/com_elements.cpp -o $@ $(cppflags) -I$(inc)

$(obj)/database_control.o: $(inc)/database_control.hpp $(src)/database_control.cpp
	@echo G++ $@
	@$(cpp) -c $(src)/database_control.cpp -o $@ $(cppflags) -I$(inc)

.PHONY: clean exe
clean:
	rm -f $(bin)/$(target) $(objetos)

exe:
	@./$(bin)/$(target)

