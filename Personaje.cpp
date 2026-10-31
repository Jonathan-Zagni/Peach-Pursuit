#include "Personaje.h"

Personaje::Personaje(float x, float yPies) {
	actualizarAnimacion();
	_sprite.setOrigin(_sprite.getTextureRect().width / 2.f, static_cast<float>(_sprite.getTextureRect().height));
	_sprite.setPosition(x, yPies);
	cargar();
}

void Personaje::cargar(){
	if(!_texture.loadFromFile("img/princesa.png")) return;
	_sprite.setTexture(_texture);
	actualizarAnimacion();
}

void Personaje::actualizarAnimacion(){
	switch (_estado) {
	case Princesa::CORRIENDO1:
		_sprite.setTextureRect(sf::IntRect(580, 740, 100, 120));
		break;
	case Princesa::CORRIENDO2:
		_sprite.setTextureRect(sf::IntRect(700, 740, 100, 120));
		break;
	}
}

void Personaje::actualizar(){
	float dt = _reloj.restart().asSeconds();
	
	_acumulado += dt;
	if (_acumulado >= _tiempoFrame) {
		_acumulado = 0.f;
		_estado = (_estado == Princesa::CORRIENDO1) ? Princesa::CORRIENDO2 : Princesa::CORRIENDO1;
		
		actualizarAnimacion();
	}
}

float Personaje::getAlto() const {
	return static_cast<float>(_sprite.getTextureRect().height);
}

void Personaje::pararseEn(float yPies) {
	_sprite.setPosition(_sprite.getPosition().x, yPies);
}

void Personaje::draw(sf::RenderTarget& target, sf::RenderStates states) const{
	target.draw(_sprite, states);
}
