add_executable(PingPong
    main
    Game
)
target_link_libraries(
    PingPong 
    ${FITGY_LIBRARIES}
)