add_executable(TicTacToe
    main
    TicTacToe.cc TicTacToe.h
    GridEventHandlers
)
target_link_libraries(TicTacToe 
    Fitgy 
    ${SDL_LIBRARY} 
    ${SDLTTF_LIBRARY} 
    ${SDLMIXER_LIBRARY}
    ${SDLIMAGE_LIBRARY}
)
