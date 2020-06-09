#! bin/bash

compile:
	g++ -c main.cpp MyGame.cpp -lSDL2 --std=c++11
	g++ -o screen_test main.o MyGame.o -lSDL2 --std=c++11
	ls
clean:
	rm screen_test main.o MyGame.o
	ls
run:
	./screen_test $(SIZE)
