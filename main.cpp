#include <SFML/Graphics.hpp>
#include <vector>
#include "Personaje.h"
#include "Fondo.h"
int main() {
	Personaje princes;
	Fondo cielo("img/cielo", 20.f);
	Fondo montania("img/montaña", 50.f);
	
	sf::RenderWindow ventana(sf::VideoMode(1280, 720), "La princesa");
	ventana.setFramerateLimit(60);
	
	sf::Texture texturaPiso;
	if (!texturaPiso.loadFromFile("img/suelo.png")){
		return -1;
	}
	float escalaPiso = 180.f / texturaPiso.getSize().y;
	float anchoTile = texturaPiso.getSize().x * escalaPiso;
	float altoTile = texturaPiso.getSize().y * escalaPiso;
	float yPiso = ventana.getSize().y - altoTile;
	
	int cantidadTiles = ventana.getSize().x / anchoTile + 2;
	
	std::vector<sf::Sprite> piso;
	for (int i = 0; i < cantidadTiles; i++) {
		sf::Sprite tile(texturaPiso);
		tile.setScale(escalaPiso, escalaPiso);
		tile.setPosition(i * anchoTile, yPiso);
		piso.push_back(tile);
	}
	
	float velocidadPiso = 200.f;
	
	
	
	
	
	sf::Clock reloj;       
	
	
	
	while (ventana.isOpen()) {
		sf::Event evento;
		while (ventana.pollEvent(evento)) {
			if (evento.type == sf::Event::Closed)
				ventana.close();
		}
		
		float dt = reloj.restart().asSeconds();  
		
		for (sf::Sprite& tile : piso) {
			tile.move(-velocidadPiso * dt, 0.f);
			if (tile.getPosition().x <= -anchoTile)
				tile.move(cantidadTiles * anchoTile, 0.f);
		}
		
		cielo.actualizar();
		montania.actualizar();
		ventana.draw(cielo);
		ventana.draw(montania);
		ventana.draw(princes);
		
		for (sf::Sprite& tile : piso)
			ventana.draw(tile);
		ventana.display();                 
	}
	return 0;
}
