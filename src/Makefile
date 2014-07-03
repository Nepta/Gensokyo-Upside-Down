all: gensokyo-upside-down

gensokyo-upside-down: Main.o
	g++ Main.o -o gensokyo-upside-down -lsfml-graphics -lsfml-window -lsfml-system

Main.o: Main.cpp
	g++ -Wall -Wshadow -c Main.cpp

clean:
	@rm sfml-app; rm *.o