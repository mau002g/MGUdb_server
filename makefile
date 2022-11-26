#Conatrucción del MGUdb_server para Windows

#Compilador y parámetros
cpp = g++
cppflags = -std=c++11 -Wall -m32
linkflags = -s -m32 -std=c++11
#Carpetas de direcciones de includes, lib y otras cosas
inc = include
src = src
lib = lib
bin = bin
obj = obj
target = mgudb_server.exe

#lista de objetos a compilar
objetos = $(obj)/main.o $(obj)/AppMain.o

#Definciones de los objetivos
all: $(bin)/$(target)

#Enlazamos el programa principal
$(bin)/$(target): $(objetos)
	@echo Enlazando $@
	@$(cpp) -o $@ $(objetos) $(linkflags)
	@echo Todo bien.

#Compilamos los archivos fuente
$(obj)/main.o: main.cpp $(src)/AppMain.hpp $(src)/AppMain.cpp
	@echo G++ $@
	@$(cpp) -c main.cpp -o $@ $(cppflags)

$(obj)/AppMain.o: $(src)/AppMain.hpp $(src)/AppMain.cpp
	@echo G++ $@
	@$(cpp) -c $(src)/AppMain.cpp -o $@ $(cppflags) -I$(inc)


.PHONY: clean
clean:
	rm -f $(bin)/$(target) $(objetos)