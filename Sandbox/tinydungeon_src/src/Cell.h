#pragma once

#include <OldCat/World/Object.h>
#include "CellType.h"

#include <OldCat/Components/SpriteComponent.h>

class Cell : public OldCat::Object
{
public:
	Cell(std::string name, OldCat::GameContext& gameContext, OldCat::Transform transform,
		const char* texturePath, CellType cellType);

	void update(float deltaTime) override;

	CellType& cellType();
	OldCat::SpriteComponent& sprite();

private:
	CellType m_type;
	OldCat::SpriteComponent* m_sprite;
};