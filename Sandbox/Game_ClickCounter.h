#pragma once

#include <OldCat/Core/Game.h>
#include <OldCat/Graphics/Font.h>
#include <OldCat/UI/Text.h>

#include "Plant.h"

class Game_ClickCounter : public OldCat::Game
{
public:
    explicit Game_ClickCounter(OldCat::GameContext& gameContext);

    void update() override;
    void render() override;

private:
    int m_counter = 0;

    OldCat::Font m_font;
    OldCat::Text* m_clicksText = nullptr;

    Plant* m_plant = nullptr;

    void increaseCounter();
};