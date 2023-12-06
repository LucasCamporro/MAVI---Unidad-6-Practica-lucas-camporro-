#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>
int main()
{

	sf::RenderWindow window(sf::VideoMode(800, 600), "toreto");
	sf::Vector2f position(5.0f, 300.0f);

	float speed = 1.0f;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}


		float deltaTime = 1.0f / 60.0f;

		position.x += speed * deltaTime;

		if (position.x > 800.0f)
		{
			position.x = 5.0f;

			if (speed < 10){
				speed += 1.0f;
			}

		}
		window.clear();
		sf::CircleShape object(20.0f);
		object.setPosition(position);
		object.setFillColor(sf::Color::Green);
		window.draw(object);
		window.display();
	}
	return 0;
}
