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

    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height,
                              SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

    gl_context = SDL_GL_CreateContext(window);

    // init glew
    GLenum err = glewInit();

    if (err != GLEW_OK)
    {
        std::cerr << "Error: " << glewGetErrorString(err) << std::endl;
        std::exit(-1);
    }

    // prints current OpenGL Version (GPU Driver)
    std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;

    // set background clear color
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void App::game_loop()
{

    Vertex vertices[3] = {
        {-0.5f, -0.5f, 0.0f},
        {0.0f, 0.5f, 0.0f},
        {0.5f, -0.5f, 0.0f},
    };

    while (!close)
    {

        SDL_Event event{};

        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                close = true;
        }

        // clear window (background)
        glClear(GL_COLOR_BUFFER_BIT);
        // update window with OpenGL rendering, used for double-buffered frame(buffer)
        SDL_GL_SwapWindow(window);

        /* draw triangle - legacy method (old pipeline):

            glBegin(GL_TRIANGLES);

            glVertex2f(-0.5f, -0.5f);
            glVertex2f(0.0f, 0.5f);
            glVertex2f(0.5f, -0.5f);

            glEnd();

        end triangle draw */
    }
}