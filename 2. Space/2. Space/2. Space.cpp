#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>
using namespace sf;

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "space");
	sf::Vector2f position(400.0f, 300.0f);

	float speed = 0.0f;

	window.setFramerateLimit(60);


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::A))
		{
			speed -= 1.0f;
		}

		if (Keyboard::isKeyPressed(Keyboard::D)) {
			speed += 1.0f;
		}
		

		float deltaTime = 1.0f / 60.0f;

		position.x += speed * deltaTime;

		window.clear();
		sf::CircleShape object(20.0f);
		object.setPosition(position);
		object.setFillColor(sf::Color::Green);
		window.draw(object);
		window.display();
	}
	return 0;
}
