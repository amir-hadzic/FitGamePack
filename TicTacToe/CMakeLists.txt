add_executable(TicTacToe
    main
    TicTacToe.cc TicTacToe.h
    GridEventHandlers
)
target_link_libraries(TicTacToe 
    Fitgy 
    ${FITGY_LIBRARIES}
)