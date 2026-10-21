#pragma once
#include <SFML/Graphics.hpp>

class Personaje: public sf::Drawable{
private:
	sf::Texture _texture;
	sf::Sprite _sprite;
	int _velocity;
public:
	Personaje();
	
	void cargar();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

};
