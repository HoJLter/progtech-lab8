#include "main.h"
#include "SFML/Graphics.hpp"


int main()
{
    sf::RenderWindow window(
        sf::VideoMode({ 800, 800 }),
        "SFML"
    );

    while (window.isOpen())
    {
        while (auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();
        window.display();
    }

    return 0;
}