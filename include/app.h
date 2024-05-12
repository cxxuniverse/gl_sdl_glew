#pragma once

#include "vertex.h"

#include "./GL/glew.h"
#define SDL_MAIN_HANDLED

#ifdef _WIN32
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

#include <iostream>

struct App
{
    bool close = false;
    SDL_Window *window;
    SDL_GLContext gl_context;

    App();

    void create_window(const char *title, int width, int height);

    void game_loop();
};