add_executable(Play_TicTacToe
    main
    TicTacToe.cc TicTacToe.h
    GridEventHandlers
)
target_link_libraries(Play_TicTacToe Fitgy ${SDL_LIBRARY} ${SDLTTF_LIBRARY} )
