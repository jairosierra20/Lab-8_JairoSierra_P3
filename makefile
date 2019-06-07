main.out: Main.o Pieza.o Posicion.o Alfil.o Torre.o Reina.o Caballo.o Peon.o Rey.o Partida.o
	g++ Main.o Pieza.o Posicion.o Alfil.o Torre.o Reina.o Caballo.o Peon.o Rey.o Partida.o -o main.out
main.o: Main.cpp Pieza.cpp Posicion.cpp Alfil.cpp Torre.cpp Reina.cpp Caballo.cpp Peon.cpp Rey.cpp Partida.cpp
	g++ -c 	main.cpp