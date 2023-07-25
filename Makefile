all: compile link delete run

compile:
	g++ -c src/main.cpp src/*.cpp

link:
	g++ *.o -o main -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

run:
	./main

delete:
	rm -rf *.o