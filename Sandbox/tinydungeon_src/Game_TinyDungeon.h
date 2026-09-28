#pragma once

#include <OldCat/Core/Game.h>
#include <OldCat/Graphics/Font.h>

#include "src/DungeonFactory.h"

class Game_TinyDungeon : public OldCat::Game
{
public:
	explicit Game_TinyDungeon(OldCat::GameContext& gameContext);

	void update(float deltaTime) override;
	void render() override;

private:
	OldCat::Font m_font;
	DungeonFactory m_dungeonFactory;
};