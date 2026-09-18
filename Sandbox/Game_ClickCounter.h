#pragma once

#include <OldCat/Game.h>

class Game_ClickCounter : public OldCat::Game
{
public:
    void update(const OldCat::Input& input) override;
    void render(OldCat::Renderer& renderer) override;

private:
    int m_counter = 0;
};