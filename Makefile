CC = clang
# CFLAGS =

CFLAGS = -Wall -Wpedantic -Werror -Wextra


all: wordle_main

wordle_main: wordle_game.o wordle_main.o
	$(CC) wordle_game.o wordle_main.o -o wordle_main

wordle_main.o: wordle_main.c wordle_game.h
	$(CC) $(CFLAGS) -c wordle_main.c 

wordle_game.o: wordle_game.c wordle_game.h
	$(CC) $(CFLAGS) -c wordle_game.c 

clean:
	rm -f wordle_main wordle_game.o wordle_main.o

format:
	clang-format -i -style=file *.[ch]
