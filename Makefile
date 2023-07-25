all: compile link run

compile:
	
	g++ -IC:\SFML-2.5.1\include -c src/main.cpp

link:
	g++ main.o -o main -LC:\SFML-2.5.1\lib -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system
	
	
run:
	./main.exe