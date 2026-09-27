#pragma once

#include <OldCat/World/Object.h>


class Plant : public OldCat::Object
{
public:
	explicit Plant(std::string name, OldCat::GameContext& context, OldCat::Transform transform);

	void update(float deltaTime) override;
private:
};