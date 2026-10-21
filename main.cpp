#include <SFML/Graphics.hpp>
#include <vector>
#include "Personaje.h"

int main() {
	Personaje princes;
	sf::RenderWindow ventana(sf::VideoMode(1280, 720), "La princesa");
	ventana.setFramerateLimit(60);
	
	sf::Texture texturaCielo;                         
	if (!texturaCielo.loadFromFile("cielo.png")){      
		return -1;                            
	}
	
	sf::Texture texturaPiso;
	if (!texturaPiso.loadFromFile("suelo.png")){
		return -1;
	}
	
	sf::Texture texturaMontania;
	if(!texturaMontania.loadFromFile("montaña.png")){
		return -1;
	}
	
	float anchoCielo = texturaCielo.getSize().x;
	float anchoMontanias=texturaMontania.getSize().x;

	sf::Sprite cielo1(texturaCielo);
	sf::Sprite cielo2(texturaCielo); 
	cielo1.setPosition(0.f, 0.f);                      
	cielo2.setPosition(anchoCielo, 0.f);         
	
	
	sf::Sprite montania1(texturaMontania);
	sf::Sprite montania2(texturaMontania);
	montania1.setPosition(0.f, 0.f);
	montania2.setPosition(anchoMontanias, 0.f);
	
	
	
	float velocidadCielo = 20.f;
	float velocidadMontania=50.f;
	
	
	
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
		cielo1.move(-velocidadCielo * dt, 0.f);
		cielo2.move(-velocidadCielo * dt, 0.f);        
		
		if (cielo1.getPosition().x <= -anchoCielo)
		{
			cielo1.move(anchoCielo * 2.f, 0.f);  
		}
		if (cielo2.getPosition().x <= -anchoCielo)
		{
			cielo2.move(anchoCielo * 2.f, 0.f); 
		}
		
		montania1.move(-velocidadMontania*dt, 0.f);
		montania2.move(-velocidadMontania*dt, 0.f);
		
		if(montania1.getPosition().x <= -anchoMontanias)
		{
			montania1.move(anchoMontanias*2.f, 0.f);
		}
		
		if(montania2.getPosition().x <= -anchoMontanias)
		{
			montania2.move(anchoMontanias*2.f, 0.f);
		}
		
		
		
		
		for (sf::Sprite& tile : piso) {
			tile.move(-velocidadPiso * dt, 0.f);
			if (tile.getPosition().x <= -anchoTile)
				tile.move(cantidadTiles * anchoTile, 0.f);
		}
		
		
		 
		ventana.draw(cielo1);
		ventana.draw(cielo2);  
		
		ventana.draw(montania1);
		ventana.draw(montania2);
		
		ventana.draw(princes);
		
		for (sf::Sprite& tile : piso)
			ventana.draw(tile);
		ventana.display();                 
	}
	return 0;
}
