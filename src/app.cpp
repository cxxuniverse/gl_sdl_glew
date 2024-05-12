#include "../include/app.h"

App::App()
{
    SDL_Init(SDL_INIT_EVERYTHING);
}

void App::create_window(const char *title, int width, int height)
{
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);

    gl_context = SDL_GL_CreateContext(window);
    // SDL_GL_CreateContext(window);
}

void App::game_loop()
{
    while (!close)
    {

        SDL_Event event{};

        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                close = true;
        }

        // clear the window
        glClearColor(0.7f, 0.2f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // update window with OpenGL rendering, used for double-buffered frame(buffer)
        SDL_GL_SwapWindow(window);
    }
}