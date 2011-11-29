all:: tetris_ncurses tetris_sdl

tetris_ncurses: display_ncurses.o tetris_ncurses.o generate.o pipe.o control_ncurses.o
	gcc -Wall -pedantic display_ncurses.o generate.o tetris_ncurses.o pipe.o control_ncurses.o -o tetris_ncurses -lncurses

tetris_sdl: display_sdl.o tetris_sdl.o generate.o pipe.o control_sdl.o
	gcc -Wall -pedantic display_sdl.o generate.o tetris_sdl.o pipe.o control_sdl.o -o tetris_sdl -lSDL -lSDL_ttf

tetris_ncurses.o: tetris_ncurses.h generate.h display_ncurses.h tetris_ncurses.c
	gcc -Wall -pedantic -c tetris_ncurses.c -std=c99

tetris_sdl.o: tetris_sdl.h generate.h display_sdl.h tetris_sdl.c
	gcc -Wall -pedantic -c tetris_sdl.c

display_ncurses.o: display_ncurses.c display_ncurses.h tetris_ncurses.h
	gcc -Wall -pedantic -c display_ncurses.c -std=c99

display_sdl.o: display_sdl.c display_sdl.h tetris_sdl.h
	gcc -Wall -pedantic -c display_sdl.c

generate.o: generate.h pipe.h generate.c
	gcc -Wall -pedantic -c generate.c

pipe.o: pipe.c pipe.h
	gcc -Wall -pedantic -c pipe.c

control_ncurses.o: control_ncurses.c control_ncurses.h
	gcc -Wall -pedantic -c control_ncurses.c

control_sdl.o: control_sdl.c control_sdl.h
	gcc -Wall -pedantic -c control_sdl.c

clean::
	rm -f tetris_ncurses
	rm -f tetris_sdl
	rm -f *.o
	rm -f *~

.PHONY: clean