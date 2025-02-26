#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Window/Event.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "PingPongGame");
    sf::CircleShape circle;
    circle.setRadius(7);
    circle.setFillColor(sf::Color::White);
    circle.setPosition({390.0f, 290.0f});
    sf::RectangleShape leftpaddle;
    leftpaddle.setSize(sf::Vector2f(10, 100));
    leftpaddle.setFillColor(sf::Color::White);
    leftpaddle.setPosition({10.0f, static_cast<float>(window.getSize().y) / 2 - 50});
    sf::RectangleShape rightpaddle;
    rightpaddle.setSize(sf::Vector2f(10, 100));
    rightpaddle.setFillColor(sf::Color::White);
    rightpaddle.setPosition({static_cast<float>(window.getSize().x) - 20, static_cast<float>(window.getSize().y) / 2 - 50});
    sf::Vector2f velocity(0.0f, 0.0f);
    sf::Clock clock;
    float speed = 200.0f;

    sf::Vector2 velocity1(200.0f, 150.0f);
    sf::Clock clock1;
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) 
            velocity.y=speed;
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
            velocity.y = -speed;
        else
            velocity.y = 0;
        float deltaTime = clock.restart().asSeconds();
        float deltaTime1 = clock1.restart().asSeconds();
        window.clear(sf::Color::Black);
        leftpaddle.move(sf::Vector2f(0, velocity.y * deltaTime));
        rightpaddle.move(sf::Vector2f(0, -0.6 * velocity.y * deltaTime));
        if(leftpaddle.getPosition().y < 0)
            leftpaddle.setPosition({10.0f, 0.0f});
        if(leftpaddle.getPosition().y + leftpaddle.getSize().y > window.getSize().y)
            leftpaddle.setPosition({10.0f, window.getSize().y-leftpaddle.getSize().y});
        if(rightpaddle.getPosition().y < 0)
            rightpaddle.setPosition({window.getSize().x - 20.0f, 0.0f});
        if(rightpaddle.getPosition().y + rightpaddle.getSize().y > window.getSize().y)
            rightpaddle.setPosition({window.getSize().x - 20.0f, window.getSize().y-rightpaddle.getSize().y});
        circle.move(velocity1 * deltaTime1);
        window.draw(circle);
        window.draw(leftpaddle);
        window.draw(rightpaddle);
        window.display();
    }
}