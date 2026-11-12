#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>


class Menu: public sf::Drawable{
public:
	Menu(sf::Vector2u tamVentana);
	//~Menu();
	
	void cargar();
	void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
	void moveUp();
	void moveDown();
	int getSelectedItem();
private:
	void centrarOpcion(int indice);
	float alto;
	float ancho;
	static int const CANT_OPCIONES=3;
	int selectedItem;
	sf::Font font;
	sf::Text opciones[CANT_OPCIONES];
	sf:: Texture fondoInicio;
	sf:: Sprite fondoSprite;
};
