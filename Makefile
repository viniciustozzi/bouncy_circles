all:
	gcc -Wall -o main main.c `sdl2-config --cflags --libs`
	./main
