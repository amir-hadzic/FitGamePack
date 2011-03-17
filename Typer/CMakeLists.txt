add_executable(Typer
    main
    Typer
)
target_link_libraries(Typer Fitgy ${SDL_LIBRARY} ${SDLTTF_LIBRARY} )
