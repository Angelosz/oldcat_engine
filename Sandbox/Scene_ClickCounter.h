#pragma once

#include <OldCat/Core/Scene.h>
#include <OldCat/Graphics/Font.h>
#include <OldCat/UI/TextWidget.h>

#include "Plant.h"

class Scene_ClickCounter : public OldCat::Scene
{
public:
    explicit Scene_ClickCounter(OldCat::GameContext& gameContext);

    void update(float deltaTime) override;
    void render() override;

private:
    int m_counter = 0;

    OldCat::Font m_font;
    OldCat::TextWidget* m_clicksText = nullptr;

    Plant* m_plant = nullptr;

    void increaseCounter();
};