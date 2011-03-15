#ifdef _WIN32
    #pragma comment(lib, "SDL.lib")
    #pragma comment(lib, "SDLmain.lib")
    #pragma comment(lib, "SDL_ttf.lib")
    #include <SDL.h>
    #include <SDL_ttf.h>
#else
    #include <SDL/SDL.h>
    #include <SDL/SDL_ttf.h>
#endif
