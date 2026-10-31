#include "Fondo.h"

Fondo::Fondo(std::string name, float vel) {
	setNombre(name);
	setVelocidad(vel);
	cargar();
}

void Fondo::cargar(){
	if(!_textura.loadFromFile(_nombre)) return;
	
	_ancho = _textura.getSize().x;
	
	_sprite1.setTexture(_textura);
	_sprite2.setTexture(_textura);
	
	_sprite1.setPosition(0.f, 0.f);
	_sprite2.setPosition(_ancho, 0.f);
}

void Fondo::actualizar(){
	float dt = reloj.restart().asSeconds();
	
	_sprite1.move(-_velocidad * dt, 0.f);
	_sprite2.move(-_velocidad * dt, 0.f);
	
	if (_sprite1.getPosition().x <= -_ancho)
	{
		_sprite1.move(_ancho * 2.f, 0.f);
	}
	
	if (_sprite2.getPosition().x <= -_ancho)
	{
		_sprite2.move(_ancho * 2.f, 0.f);
	}
}

void Fondo::draw(sf::RenderTarget& target, sf::RenderStates states) const{
	target.draw(_sprite1, states);
	target.draw(_sprite2, states);
}

void Fondo::setVelocidad(float vel){
	_velocidad = vel;
}

void Fondo::setNombre(std::string nombre){
	_nombre = nombre;
}
