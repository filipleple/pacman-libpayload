override CC := ../../libpayload/bin/lpgcc
override LD := ../../libpayload/bin/lpgcc

#CFLAGS = -Wall -D_DEBUG -g
#CFLAGS = -Wall
LDFLAGS = -lcurses -nostdlib
CFLAGS = -Os -fno-reorder-functions

pacman: pacman.o player.o ghosts.o pills.o render.o board.o gameloop.o
pacman.o: pacman.h render.h gameloop.h
player.o: pacman.h player.h ghosts.h pills.h board.h
ghosts.o: pacman.h ghosts.h board.h
board.o:  pacman.h board.h player.h ghosts.h pills.h
gameloop.o: pacman.h gameloop.h player.h ghosts.h pills.h board.h render.h
render.o: pacman.h render.h board.h
pills.o: pacman.h pills.h board.h

clean:
	-rm -f *.o pacman pactext

# DO NOT DELETE
