#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class Fondo: public sf::Drawable{
private:
	sf::Texture _textura;
	sf::Sprite _sprite1;
	sf::Sprite _sprite2;
	sf::Clock reloj;
		
	std::string _nombre;
	
	float _velocidad;
	float _ancho;
	
public:
	
	Fondo(std::string name, float vel);
	void cargar();
	void setVelocidad(float vel);
	void setNombre(std::string nombre);
	void actualizar();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

