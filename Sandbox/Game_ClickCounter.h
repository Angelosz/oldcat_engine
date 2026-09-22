#pragma once

#include <OldCat/Game.h>
#include <OldCat/Font.h>
#include <OldCat/Texture.h>

namespace OldCat
{
    class AssetManager;
    class Input;
    class Renderer;
}

class Game_ClickCounter : public OldCat::Game
{
public:
    explicit Game_ClickCounter(OldCat::GameContext& gameContext);

    void update() override;
    void render() override;

private:
    int m_counter = 0;

    OldCat::Font m_font;
    OldCat::Texture m_backgroundTexture;
    OldCat::Texture m_plantTexture;
};