#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics.hpp>
#include <iostream>


class Menu: public sf::Drawable{
public:
	Menu(float ancho, float alto);
	//~Menu();
	
	void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
	void MoveUp();
	void Movedown();
private:
	 static int const CANT_OPCIONES=3;
	int selectedItem;
	sf::Font font;
	sf::Text opciones[CANT_OPCIONES];
	sf:: Texture fondoInicio;
	sf:: Sprite fondoSprite;
};

#endif

