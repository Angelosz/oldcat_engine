#include <OldCat/Core/Application.h>

#include "Scene_ClickCounter.h"

#include <exception>
#include <iostream>

int main()
{
    try {
        OldCat::Application app("Click Counter", OldCat::Vector2(720.0f, 1280.0f));
        Scene_ClickCounter initialScene(app.context());

        app.run(initialScene);
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