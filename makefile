all: expresiones_main

expresiones_main: expresiones_main.o expresiones_func.o variable.o bucle.o main.o comentario.o return.o
	g++ -o expresiones_main expresiones_main.o expresiones_func.o variable.o bucle.o main.o comentario.o return.o -std=c++2a

expresiones_func.o: expresiones_func.cc
	g++ -c -o expresiones_func.o expresiones_func.cc -std=c++2a

expresiones_main.o: expresiones_main.cc
	g++ -c -o expresiones_main.o expresiones_main.cc -std=c++2a

variable.o: variable.cc
	g++ -c -o variable.o variable.cc -std=c++2a

bucle.o: bucle.cc
	g++ -c -o bucle.o bucle.cc -std=c++2a

main.o: main.cc
	g++ -c -o main.o main.cc -std=c++2a

comentario.o: comentario.cc
	g++ -c -o comentario.o comentario.cc -std=c++2a

return.o: return.cc
	g++ -c -o return.o return.cc -std=c++2a

clean:
	-rm expresiones_main.o expresiones_func.o variable.o bucle.o main.o comentario.o return.o expresiones_main