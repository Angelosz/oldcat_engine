#include "DoorGamePiece.h"

#include <OldCat/Assets/AssetManager.h>

namespace TinyDungeon
{
	DoorGamePiece::DoorGamePiece(
		OldCat::GameContext& gameContext,
		OldCat::Transform& transform,
		OldCat::Vector2 position)
		: GamePiece(
			"Door",
			gameContext,
			transform,
			"assets/tinyDungeon/images/T_Door.png",
			PieceType::Door,
			position
		)
	{ }

	void DoorGamePiece::openDoor()
	{
		spriteComponent().sprite().setTexture(
				assetManager()
				.loadTexture("assets/tinydungeon/images/T_Stairs.png")
		);
	}
}