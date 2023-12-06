#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
int main()
{

	sf::RenderWindow window(sf::VideoMode(800, 600), "boing");

	sf::Vector2f position(400.0f, 10.0f);

	sf::Vector2f velocity(0.0f, 0.0f);

	const float gravity = 0.000098f;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		velocity.y += gravity;

		position += velocity;
		
		if (position.y > 600.0f)
		{
			velocity.y = -velocity.y;

		}
		window.clear();
		sf::CircleShape ball(20.0f);
		ball.setFillColor(sf::Color::Red);
		ball.setPosition(position);
		window.draw(ball);
		window.display();
	}
	return 0;
}
