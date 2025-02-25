#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "My window");
    sf::CircleShape circle;
    circle.setRadius(6);
    circle.setFillColor(sf::Color::White);
    circle.setOutlineThickness(2);
    circle.setPosition({390.0f, 290.0f});
    sf::RectangleShape leftpaddle;
    leftpaddle.setSize(sf::Vector2f(10, 100));
    leftpaddle.setFillColor(sf::Color::White);
    leftpaddle.setOutlineThickness(2);
    leftpaddle.setPosition({10.0f, static_cast<float>(window.getSize().y) / 2 - 50});
    sf::RectangleShape rightpaddle;
    rightpaddle.setSize(sf::Vector2f(10, 100));
    rightpaddle.setFillColor(sf::Color::White);
    rightpaddle.setOutlineThickness(2);
    rightpaddle.setPosition({static_cast<float>(window.getSize().x) - 20, static_cast<float>(window.getSize().y) / 2 - 50});
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        window.clear(sf::Color::Black);
        window.draw(circle);
        window.draw(leftpaddle);
        window.draw(rightpaddle);
        window.display();
    }
}