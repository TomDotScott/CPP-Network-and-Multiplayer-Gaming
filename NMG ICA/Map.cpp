#include "Map.h"

#include <iostream>

Map::Map()
{
	if (!m_image.loadFromFile("images/map.png"))
	{
		std::cout << "Unable to load the background image!" << std::endl;
	}

	m_texture.loadFromImage(m_image);

	const sf::Vector2f checkPointColliderSize{ globals::k_checkPointWidth, globals::k_checkPointHeight };

	
}

void Map::CheckCollisions(Player& player) const
{
	const sf::Vector2f playerPosition = player.GetPosition();

	const auto playerPixel = m_image.getPixel(
		static_cast<unsigned>(playerPosition.x),
		static_cast<unsigned>(playerPosition.y)
	);

	if (playerPixel == sf::Color::Black || playerPixel == sf::Color::White)
	{
		player.SetSpeed(globals::k_carTrackSpeed);
	} else
	{
		player.SetSpeed(globals::k_carGrassSpeed);
	}
}

void Map::Render(sf::RenderWindow& window) const
{
	const sf::Sprite sprite(m_texture);
	window.draw(sprite);
}

