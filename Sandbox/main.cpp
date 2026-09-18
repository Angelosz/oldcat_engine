#include <OldCat/Application.h>
#include "Game_ClickCounter.h"

int main()
{
    Game_ClickCounter testgame;

    OldCat::Application app(testgame);
    app.run();
    
    return 0;
}