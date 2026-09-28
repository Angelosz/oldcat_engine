#include "DungeonFactory.h"

#include <OldCat/World/World.h>
#include <OldCat/Core/GameContext.h>

DungeonFactory::DungeonFactory(OldCat::GameContext& gameContext, OldCat::World& world) 
    : m_context(gameContext), m_world(world) { }

Cell* DungeonFactory::createCell(std::string type, OldCat::Transform transform)
{
    if (type == "W")
    {
        return &m_world.spawn<Cell>(
            "Wall",
            m_context,
            transform,
            "assets/tinyDungeon/images/T_Wall.png",
            CellType::Wall
        );
    }

    if (type == "F")
    {
        return &m_world.spawn<Cell>(
            "Floor",
            m_context,
            transform,
            "assets/tinyDungeon/images/T_Floor.png",
            CellType::Floor
        );
    }


    return nullptr;
}
