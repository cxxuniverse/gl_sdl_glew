#include "../include/app.h"

int main(int argc, char *argv[])
{
    App app{};

    app.create_window("C++ OpenGL / SDL", 800, 600);

    app.game_loop();
}