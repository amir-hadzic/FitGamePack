COMPILER = g++

FITGY_SOURCES = Fitgy/*.h Fitgy/*.cc

TICTACTOE_SOURCES = TicTacToe/*.h TicTacToe/*.cc
    

SDL_ARGS = `pkg-config --cflags --libs sdl`

all:	TicTacToe

TicTacToe: ${FITGY_SOURCES} ${TICTACTOE_SOURCES}
	${COMPILER} -Wall -Wextra -pedantic ${SDL_ARGS} -lSDL_ttf -o Play_TicTacToe ${TICTACTOE_SOURCES} ${FITGY_SOURCES} 

clean:
	rm Play_TicTacToe
	
