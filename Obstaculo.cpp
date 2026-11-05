#include "Obstaculo.h"

Obstaculo::Obstaculo(float piso) {
	cargar();
	_sprite.setOrigin(_sprite.getTextureRect().width / 2.f, static_cast<float>(_sprite.getTextureRect().height));
	_sprite.setPosition(1350, piso);
}

void Obstaculo::cargar(){
	if(!_texture.loadFromFile("img/obstaculo1.png")) return;
	_sprite.setTexture(_texture);
	
	_sprite.setTextureRect(sf::IntRect(40, 590, 115, 130));
	_sprite.setScale(0.5f * -1.0f, 0.5f);
	
}


void Obstaculo::actualizar(){
	_sprite.move(-_velocity, 0.f);
}

sf::FloatRect Obstaculo::getBounds() const{
	return _sprite.getGlobalBounds();
}

void Obstaculo::draw(sf::RenderTarget& target, sf::RenderStates states) const{
	target.draw(_sprite, states);
}
