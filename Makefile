#NOME = g++
#$(NOME)

compile: main.cpp
	g++ -c main.cpp

link: main.o
	g++ -o meuPrograma main.o
	
run:
	./meuPrograma
	
clear:
	rm -f meuPrograma *.o
