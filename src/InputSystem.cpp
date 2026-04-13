#include "InputSystem.h"
#include "SFML\Window\Keyboard.hpp"
#include "Util.h"

Breakout::InputSystem::InputSystem()
{
}

void Breakout::InputSystem::Update(const std::vector<std::shared_ptr<Object>>& gameObjects)
{
    UpdateInputs();

    // Pass inputs into objects with input components
    for (auto& object : gameObjects)
    {
        Assert(object != nullptr, "Invalid game object.");

        auto inputComponent = object->GetComponent<InputComponent>();

        if (inputComponent != nullptr)
        {
            // for formating
            inputComponent->SetInputs(currentInputs);
        }
    }
}

void Breakout::InputSystem::UpdateInputs()
{
    currentInputs.moveLeft  = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left);
    currentInputs.moveRight = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right);
    currentInputs.action    = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space);
    currentInputs.exit      = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape);
}
