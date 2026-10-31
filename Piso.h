#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

class Piso : public sf::Drawable {
private:
	sf::Texture _textura;
	std::vector<sf::Sprite> _tiles;
	sf::Clock _reloj;

	std::string _ruta;
	float _velocidad;
	float _altoTile;
	float _anchoTile;
	float _y;
	unsigned int _anchoVentana;

public:
	Piso(std::string ruta, float velocidad, float alto, sf::Vector2u tamVentana);
	void cargar();
	void actualizar();
	float getY() const;
	float getAlto() const;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
