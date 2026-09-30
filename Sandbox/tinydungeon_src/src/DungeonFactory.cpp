#include "DungeonFactory.h"

#include <OldCat/World/World.h>
#include <OldCat/Core/GameContext.h>

#include "GamePiece.h"

namespace TinyDungeon
{
    DungeonFactory::DungeonFactory(OldCat::GameContext& gameContext, OldCat::World& world) 
        : m_context(gameContext), m_world(world) { }

    Cell* DungeonFactory::createCell(std::string type, OldCat::Transform transform)
    {
        if (type[0] == 'W')
        {
            return &m_world.spawn<Cell>(
                "Wall",
                m_context,
                transform,
                "assets/tinyDungeon/images/T_Wall.png",
                CellType::Wall
            );
        }

        if (type[0] == 'F')
        {
            Cell& cell = m_world.spawn<Cell>(
                "Floor",
                m_context,
                transform,
                "assets/tinyDungeon/images/T_Floor.png",
                CellType::Floor
            );

            if (type[2] == 'P')
            {
                m_world.spawn<GamePiece>(
                    "Player",
                    m_context,
                    transform,
                    "assets/tinyDungeon/images/T_Player.png",
                    PieceType::Player
                );
            }

            if (type[2] == 'S')
            {
                m_world.spawn<GamePiece>(
                    "Slime",
                    m_context,
                    transform,
                    "assets/tinyDungeon/images/T_Slime.png",
                    PieceType::Enemy
                );
            }

            if (type[2] == 'D')
            {
                m_world.spawn<GamePiece>(
                    "Door",
                    m_context,
                    transform,
                    "assets/tinyDungeon/images/T_Door.png",
                    PieceType::Door
                );
            }

            if (type[2] == 'G')
            {
                m_world.spawn<GamePiece>(
                    "Gold",
                    m_context,
                    transform,
                    "assets/tinyDungeon/images/T_Gold.png",
                    PieceType::Gold
                );
            }

            return &cell;
        }


        return nullptr;
    }

}
