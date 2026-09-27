#include "Game_TinyDungeon.h"

#include <OldCat/Core/GameContext.h>
#include <OldCat/Math/Rect.h>
#include <OldCat/World/SpriteObject.h>
#include <OldCat/World/Transform.h>

using OldCat::Vector2;
using OldCat::Rect;
using OldCat::Transform;

Game_TinyDungeon::Game_TinyDungeon(OldCat::GameContext& gameContext) : OldCat::Game(gameContext)
, m_font("assets/fonts/PressStart2P-Regular.ttf", 24.0f)
{
	spawn<OldCat::SpriteObject>(
		"Background",
		context(),
		Transform { Vector2(256.0f, 256.0f) },
		"assets/tinydungeon/images/T_Floor.png",
		Rect(
			Vector2(-16.0f, -16.0f),
			Vector2(32.0f, 32.0f)
		)
			);
}

void Game_TinyDungeon::update(float deltaTime) { }
void Game_TinyDungeon::render() { }