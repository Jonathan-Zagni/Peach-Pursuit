#include "Mono.h"

Mono::Mono(float x, float yPies) {
	cargar();
	actualizarAnimacion();
	_sprite.setOrigin(_sprite.getTextureRect().width / 2.f, static_cast<float>(_sprite.getTextureRect().height));
	_sprite.setPosition(x, yPies);
}

void Mono::cargar(){
	if(!_texture.loadFromFile("img/mono.png")) return;
	_sprite.setTexture(_texture);
}

void Mono::actualizarAnimacion(){
	switch(_estado){
	case Estado::CORRIENDO1:
		_sprite.setTextureRect(sf::IntRect(300, 47, 110, 130));
		break;
	case Estado::CORRIENDO2:
		_sprite.setTextureRect(sf::IntRect(170, 47, 110, 130));
		break;
	}
}

void Mono::actualizar(){
	float dt = _reloj.restart().asSeconds();
	float _tiempoFrame = 0.15f;
	
	_acumulado += dt;
	if (_acumulado >= _tiempoFrame) {
		_acumulado -= _tiempoFrame;
		_estado = (_estado == Estado::CORRIENDO1) ? Estado::CORRIENDO2 : Estado::CORRIENDO1;
		actualizarAnimacion();
	}
}

sf::FloatRect Mono::getBounds() const{
	return _sprite.getGlobalBounds();
}
void Mono::draw(sf::RenderTarget& target, sf::RenderStates states) const{
	target.draw(_sprite, states);
}
