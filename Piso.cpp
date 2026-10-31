#include "Piso.h"

Piso::Piso(std::string ruta, float velocidad, float alto, sf::Vector2u tamVentana)
	: _ruta(ruta),
	  _velocidad(velocidad),
	  _altoTile(alto),
	  _anchoTile(0.f),
	  _y(static_cast<float>(tamVentana.y) - alto),
	  _anchoVentana(tamVentana.x) {
	cargar();
}

void Piso::cargar(){
	if (!_textura.loadFromFile(_ruta)) return;

	float escala = _altoTile / static_cast<float>(_textura.getSize().y);
	_anchoTile = _textura.getSize().x * escala;

	int cantidadTiles = static_cast<int>(_anchoVentana / _anchoTile) + 2;

	_tiles.clear();
	for (int i = 0; i < cantidadTiles; i++) {
		sf::Sprite tile(_textura);
		tile.setScale(escala, escala);
		tile.setPosition(i * _anchoTile, _y);
		_tiles.push_back(tile);
	}
}

void Piso::actualizar(){
	float dt = _reloj.restart().asSeconds();

	for (sf::Sprite& tile : _tiles) {
		tile.move(-_velocidad * dt, 0.f);
		if (tile.getPosition().x <= -_anchoTile)
			tile.move(_anchoTile * static_cast<float>(_tiles.size()), 0.f);
	}
}

float Piso::getY() const{
	return _y;
}

float Piso::getAlto() const{
	return _altoTile;
}

void Piso::draw(sf::RenderTarget& target, sf::RenderStates states) const{
	for (const sf::Sprite& tile : _tiles)
		target.draw(tile, states);
}
