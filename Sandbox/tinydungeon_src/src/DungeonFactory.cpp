#include "DungeonFactory.h"

#include <OldCat/World/World.h>
#include <OldCat/Core/GameContext.h>

#include "GamePiece.h"
#include "DoorGamePiece.h"
#include "GameTable.h"
#include "Constants.h"

using OldCat::Vector2;
using OldCat::Transform;

namespace TinyDungeon
{
    DungeonFactory::DungeonFactory(OldCat::GameContext& gameContext, OldCat::World& world) 
        : m_context(gameContext), m_world(world) { }

    GameTable& DungeonFactory::setupDungeon(const std::vector<std::string>& grid, int nRows, int nColumns, float cellSize)
    {
        GameTable& gameTable = m_world.spawn<GameTable>("GameTable", m_context, Transform(), nColumns, nRows);

        createCells(gameTable, grid, nRows, nColumns, cellSize);
        createGamePieces(gameTable, grid, nRows, nColumns, cellSize);

        return gameTable;
    }

    void DungeonFactory::createCells(GameTable& gameTable, const std::vector<std::string>& grid, int nRows, int nColumns, float cellSize)
    {
        for (int row = 0; row < nRows; ++row)
        {
            for (int column = 0; column < nColumns; ++column)
            {
                const int index = row * nColumns + column;
                char cellTypeIdentifier = grid[index][0];

                Transform transform =
                    Transform{
                        Vector2{
                            (WindowWidth / 2) + (column - (nColumns - 1) / 2.0f) * cellSize,
                            (WindowHeight / 2) + (row - (nRows - 1) / 2.0f) * cellSize
                        }
                };

                switch (cellTypeIdentifier)
                {
                case 'F':
                    gameTable.addCell(
                        m_world.spawn<Cell>(
                            "Floor",
                            m_context,
                            transform,
                            "assets/tinyDungeon/images/T_Floor.png",
                            CellType::Floor,
                            Vector2(column, row)
                        )
                    );
                    break;
                case 'W':
                    gameTable.addCell(
                        m_world.spawn<Cell>(
                            "Wall",
                            m_context,
                            transform,
                            "assets/tinyDungeon/images/T_Wall.png",
                            CellType::Wall,
                            Vector2( column, row)
                        )
                    );
                    break;
                default:
                    break;
                }
            }
        }
    }

    void DungeonFactory::createGamePieces(GameTable& gameTable, const std::vector<std::string>& grid, int nRows, int nColumns, float cellSize)
    {
        for (int row = 0; row < nRows; ++row)
        {
            for (int column = 0; column < nColumns; ++column)
            {
                const int index = row * nColumns + column;
                char cellTypeIdentifier = grid[index][0];

                Transform transform =
                    Transform{
                        Vector2{
                            (WindowWidth / 2) + (column - (nColumns - 1) / 2.0f) * cellSize,
                            (WindowHeight / 2) + (row - (nRows - 1) / 2.0f) * cellSize
                        }
                };

                if (cellTypeIdentifier == 'F')
                {
                    char gamePieceIdentifier = grid[index][2];
                    
                    switch (gamePieceIdentifier)
                    {
                    case 'P':
                        gameTable.addPlayer(m_world.spawn<GamePiece>(
                            "Player",
                            m_context,
                            transform,
                            "assets/tinyDungeon/images/T_Player.png",
                            PieceType::Player,
                            Vector2(column, row)
                        ));
                        break;
                    case 'G':
                        gameTable.addEnvironmentPiece(m_world.spawn<GamePiece>(
                            "Gold",
                            m_context,
                            transform,
                            "assets/tinyDungeon/images/T_Gold.png",
                            PieceType::Gold,
                            Vector2(column, row)
                        ));
                        break;
                    case 'D':
                        gameTable.addDoor(m_world.spawn<DoorGamePiece>(
                            m_context,
                            transform,
                            Vector2(column, row)
                        ));
                        break;
                    case 'E':
                        gameTable.addEnemyPiece(m_world.spawn<GamePiece>(
                            "Slime",
                            m_context,
                            transform,
                            "assets/tinyDungeon/images/T_Slime.png",
                            PieceType::Enemy,
                            Vector2(column, row)
                        ));
                        break;
                    }
                }
            }
        }
    }
}
