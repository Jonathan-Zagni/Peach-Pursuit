#pragma once
#include <SFML/Graphics.hpp>

class Obstaculo: public sf::Drawable{
private:
	sf::Texture _texture;
	sf::Sprite _sprite;
	
	float _velocity = 3.0f;
public:
	Obstaculo(float piso);
	
	void cargar();
	void actualizar();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

};


