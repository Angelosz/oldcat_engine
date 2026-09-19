#pragma once

#include <OldCat/Game.h>
#include <OldCat/Font.h>



class Game_ClickCounter : public OldCat::Game
{
public:
    Game_ClickCounter();

    void update(const OldCat::Input& input) override;
    void render(OldCat::Renderer& renderer) override;

private:
    int m_counter = 0;

    OldCat::Font m_font;
};