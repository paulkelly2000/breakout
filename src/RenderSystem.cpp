#include "RenderSystem.h"
#include "Object.h"
#include "Util.h"

#include "SFML/Graphics.hpp"

Breakout::RenderSystem::RenderSystem(sf::RenderWindow* _window) : window(_window) {}

void Breakout::RenderSystem::Update(float deltaTime, const std::vector<std::shared_ptr<Object>>& gameObjects)
{
    // get components of type
    UNUSED_ARGS(deltaTime);

    for (auto& object : gameObjects)
    {
        auto renderComponent = dynamic_cast<RenderComponent*>(object->GetComponent(CT_RENDERCOMPONENT));
        window->draw(*renderComponent->GetShape());
    }
}
