#pragma once

#include <OldCat/Objects/Object.h>
#include <OldCat/Graphics/Sprite.h>


class Plant : public OldCat::Object
{
public:
	Plant(std::string name, OldCat::GameContext& context, OldCat::Sprite sprite);

	void render() override;
	void update() override;

private:
	OldCat::Sprite m_sprite;
};
