#include <OldCat/Core/Application.h>

#include "tinydungeon_src/Game_TinyDungeon.h"
#include "tinydungeon_src/src/Constants.h"

#include <exception>
#include <iostream>

int main()
{
    try {
        OldCat::Application app("Tiny Dungeon", OldCat::Vector2(TinyDungeon::WindowWidth, TinyDungeon::WindowHeight));
        TinyDungeon::Game_TinyDungeon game(app.context());

        app.run(game);
    }
    catch (const std::exception& exception)
    {
        std::cerr << "ERROR\n"
            << exception.what()
            << "\n";
        
        return 1;
    }
    return 0;
}