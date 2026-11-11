#include "Mono.h"

Mono::Mono(float x, float yPies) {
	cargar();
	actualizarAnimacion();
	_sprite.setOrigin(_sprite.getTextureRect().width / 2.f, static_cast<float>(_sprite.getTextureRect().height));
	_sprite.setPosition(x, yPies);
	_posX = x;
	_posY = yPies;
}

void Mono::cargar(){
	if(!_texture.loadFromFile("img/mono.png")) return;
	_sprite.setTexture(_texture);
}

void Mono::pararseEn(float yPies) {
	_sprite.setPosition(_sprite.getPosition().x, yPies);
	_posY = yPies;
	_velocity = 0.f;
	_enSuelo = true;
}

void Mono::actualizarAnimacion(){
	switch(_estado){
	case Estado::CORRIENDO1:
		_sprite.setTextureRect(sf::IntRect(300, 47, 110, 130));
		break;
	case Estado::CORRIENDO2:
		_sprite.setTextureRect(sf::IntRect(170, 47, 110, 130));
		break;
	case Estado::SALTO:
		_sprite.setTextureRect(sf::IntRect(850, 220, 155, 160));
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
		if(!_enSuelo) _estado = Estado::SALTO;
		actualizarAnimacion();
	}
	
	_velocity += _gravity * dt;
	_sprite.move(0.f, _velocity * dt);
	
	if (_sprite.getPosition().y >= _posY) {
		pararseEn(_posY);
	}
}

void Mono::acercar(){
	if(_sprite.getPosition().x <= _posX + 158.0f){
		_sprite.move(2.0f, 0.f);
		_posX +=158.f;
	}

}

void Mono::saltar(){
	if(!_enSuelo) return;
	_velocity = -_impulso;
	_enSuelo = false;
}

sf::FloatRect Mono::getBounds() const{
	return _sprite.getGlobalBounds();
}
void Mono::draw(sf::RenderTarget& target, sf::RenderStates states) const{
	target.draw(_sprite, states);
}
