#include "Personaje.h"

Personaje::Personaje() {
	cargar();
}

void Personaje::cargar(){
	if(!_texture.loadFromFile("img/princesa.png")) return;
	_sprite.setTexture(_texture);
	
	_sprite.setTextureRect(sf::IntRect(237, 90, 100, 180));
	_sprite.setPosition(sf::Vector2f(500.f, 360.f));
	
}

void Personaje::draw(sf::RenderTarget& target, sf::RenderStates states) const{
	target.draw(_sprite, states);
}
