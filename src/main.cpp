#include "main.h"
#include "SFML/Graphics.hpp"


class Hexagon {
    sf::RenderWindow& window;
    sf::ConvexShape shape;

public:
    Hexagon(sf::RenderWindow& window, sf::Vector2f pos, float radius, float rotation): window(window) {
        shape.setPointCount(6);
        shape.setFillColor(sf::Color::Transparent);
        shape.setOutlineThickness(3.f);
        shape.setOutlineColor(sf::Color::White);
        shape.setRotation(sf::degrees(rotation));

        for (int i = 0; i < 6; i++) {
            float angle = i * 2.f * 3.14f / 6.f;

            float x = radius * std::cos(angle);
            float y = radius * std::sin(angle);

            shape.setPoint(i, { x, y });
        }

        shape.setOrigin({ 0.f, 0.f });
        shape.setPosition(pos);
    }

    void render() {
        window.draw(shape);
    }
};

class RecursiveFigure {
    std::vector<Hexagon*> figure;
    sf::RenderWindow& window;
    
public:
    RecursiveFigure(sf::RenderWindow& window, sf::Vector2f pos, float initialRadius, int depth): window(window) {
        generate(pos, initialRadius, 360.f, depth);
    }

    void generate(
        sf::Vector2f pos,
        float radius,
        float rotation,
        int depth) 
    {
        if (depth <= 0) {
            return;
        }
        figure.push_back(new Hexagon(window, pos, radius, rotation));
        float newRadius = radius * 0.9;
        float newRotation = rotation * 0.96;
        
        generate(pos, newRadius, newRotation, --depth);
    }

    void render() {
        for (auto hex : figure) {
            hex->render();
        }
    }
};

int main()
{
    int depth;
    std::cout << "Enter depth of the recursion: ";
    std::cin >> depth;
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

        RecursiveFigure figure(window, { 400.f, 400.f }, 300.f, depth);

        window.clear();
        
        figure.render();
        
        window.display();
    }

    return 0;
}