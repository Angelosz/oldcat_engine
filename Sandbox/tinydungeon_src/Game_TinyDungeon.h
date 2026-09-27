#pragma once

#include <OldCat/Core/Game.h>
#include <OldCat/Graphics/Font.h>

class Game_TinyDungeon : public OldCat::Game
{
public:
	explicit Game_TinyDungeon(OldCat::GameContext& gameContext);

	void update(float deltaTime) override;
	void render() override;

private:
	OldCat::Font m_font;
};