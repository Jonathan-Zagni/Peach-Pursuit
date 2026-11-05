#pragma once
#include <SFML/Graphics.hpp>
#include "Colision.h"

class Obstaculo: public sf::Drawable, public Colisionable{
private:
	sf::Texture _texture;
	sf::Sprite _sprite;
	
	float _velocity = 3.0f;
	float _posY;
public:
	Obstaculo(float piso);
	
	void cargar();
	void actualizar();
	void spawn();
	float getPosX();
	sf::FloatRect getBounds() const override;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

};


