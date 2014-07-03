all: gensokyo-upside-down.out

gensokyo-upside-down.out: Main.o
	g++ Main.o -o gensokyo-upside-down.out -lsfml-graphics -lsfml-window -lsfml-system

Main.o: Main.cpp
	g++ -Wall -Wshadow -c Main.cpp

clean:
	@rm sfml-app; rm *.o