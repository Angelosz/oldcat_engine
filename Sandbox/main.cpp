#include <OldCat/Core/Application.h>

#include "Game_ClickCounter.h"

#include <exception>
#include <iostream>

int main()
{
    try {
        OldCat::Application app;
        Game_ClickCounter game(app.context());

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