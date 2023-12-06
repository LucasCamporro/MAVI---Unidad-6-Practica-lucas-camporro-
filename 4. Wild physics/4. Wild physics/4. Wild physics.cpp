#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cstdlib>
#include <ctime>

using namespace sf;

Texture texturaCrosshair;
Sprite spriteCrosshair;


int main()
{
    sf::CircleShape ball(30.0f);

    texturaCrosshair.loadFromFile("Crosshair.png");
    spriteCrosshair.setTexture(texturaCrosshair);
    spriteCrosshair.setScale(0.3, 0.3);

    sf::RenderWindow window(sf::VideoMode(800, 600), "wild");

    std::srand(time(NULL));

    window.setMouseCursorVisible(false);

    sf::Vector2f position(5.0f, 300.0f);

    float speed = 1.0f;

    float deltaTime = 1.0f / 60.0f;

    int score = 0;

    Font font; 
    if (!font.loadFromFile("Inconsolata-Regular.ttf")) {
    }

    Text scoreText;
    scoreText.setFont(font);
    scoreText.setCharacterSize(20);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(10, 10);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (event.type == sf::Event::MouseMoved)
        {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
            spriteCrosshair.setPosition(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));
        }
        position.x += speed * deltaTime;

        if (position.x > 800.0f)
        {
            position.x = 5.0f;
            position.y = rand() % 500;
        }

        if (Mouse::isButtonPressed(Mouse::Left)) {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

            float distance = std::sqrt(std::pow(position.x - mousePosition.x, 2) + std::pow(position.y - mousePosition.y, 2));

            if (distance < 30.0f)
            {
                position.x = 5.0f;
                position.y = rand() % 500;

                score++;
            }
        }

        scoreText.setString("Puntaje: " + std::to_string(score));

        sf::CircleShape ball(30.0f);
        window.clear();
        ball.setFillColor(sf::Color::Blue);
        ball.setPosition(position);
        window.draw(ball);
        window.draw(spriteCrosshair);
        window.draw(scoreText);
        window.display();
    }

    return 0;
}