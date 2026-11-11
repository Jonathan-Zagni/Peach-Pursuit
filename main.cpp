#include <SFML/Graphics.hpp>
#include "Personaje.h"
#include "Fondo.h"
#include "Piso.h"
#include "Mono.h"
#include "Obstaculo.h"

int main() {
	sf::RenderWindow ventana(sf::VideoMode(1280, 720), "La princesa");
	ventana.setFramerateLimit(60);
	
	Piso piso("img/suelo.png", 200.f, 180.f, ventana.getSize());
	Personaje princes(525.f, piso.getY());
	Fondo cielo("img/cielo.png", 20.f);
	Fondo montania("img/montania.png", 50.f);
	Mono mono(50.f, piso.getY());
	Obstaculo hongo(piso.getY());
	
	while (ventana.isOpen()) {
		sf::Event evento;
		while (ventana.pollEvent(evento)) {
			if (evento.type == sf::Event::Closed) ventana.close();
			if(evento.type == sf::Event::KeyPressed && evento.key.code == sf::Keyboard::Space) princes.saltar();
		}
		
		if(princes.isColision(hongo)){
			mono.acercar();
		}
		
		if(mono.isColision(hongo)){
			mono.saltar();
		}
		
		if(hongo.getPosX() <= 0.f){
			hongo.spawn();
		}
		
		piso.actualizar();
		cielo.actualizar();
		montania.actualizar();
		princes.actualizar();
		mono.actualizar();
		hongo.actualizar();
		
		ventana.draw(cielo);
		ventana.draw(montania);
		ventana.draw(princes);
		ventana.draw(mono);
		ventana.draw(hongo);
		
		ventana.draw(piso);
		ventana.display();                 
	}
	return 0;
}
