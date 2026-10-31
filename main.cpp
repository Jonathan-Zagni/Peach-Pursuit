#include <SFML/Graphics.hpp>
#include "Personaje.h"
#include "Fondo.h"
#include "Piso.h"
int main() {
	sf::RenderWindow ventana(sf::VideoMode(1280, 720), "La princesa");
	ventana.setFramerateLimit(60);
	
	Personaje princes;
	Fondo cielo("img/cielo.png", 20.f);
	Fondo montania("img/montaña.png", 50.f);
	Piso piso("img/suelo.png", 200.f, 180.f, ventana.getSize());
	
	while (ventana.isOpen()) {
		sf::Event evento;
		while (ventana.pollEvent(evento)) {
			if (evento.type == sf::Event::Closed)
				ventana.close();
		}
		
		piso.actualizar();
		cielo.actualizar();
		montania.actualizar();
		
		ventana.draw(cielo);
		ventana.draw(montania);
		ventana.draw(princes);
		
		ventana.draw(piso);
		ventana.display();                 
	}
	return 0;
}
