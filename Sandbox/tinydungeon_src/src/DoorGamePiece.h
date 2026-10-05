#pragma once
#include "GamePiece.h"

namespace TinyDungeon
{
	class DoorGamePiece : public GamePiece
	{
	public:
		DoorGamePiece(
			OldCat::GameContext& gameContext,
			OldCat::Transform& transform,
			OldCat::Vector2 position
		);

		void openDoor();
	};
}