COMPILER = g++

FITGY_SOURCES = Fitgy/*.h Fitgy/*.cc

TICTACTOE_SOURCES = TicTacToe/*.h TicTacToe/*.cc
    

SDL_ARGS = `pkg-config --libs --cflags sdl`

all:	TicTacToe

TicTacToe: ${FITGY_SOURCES} ${TICTACTOE_SOURCES}
	${COMPILER} -Wall -Wextra -pedantic ${SDL_ARGS} -o Play_TicTacToe ${TICTACTOE_SOURCES} ${FITGY_SOURCES} 

clean:
	rm TicTacToe
	
