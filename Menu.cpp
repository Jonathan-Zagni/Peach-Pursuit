#include "Menu.h"

Menu::Menu(float ancho, float alto) {
	selectedItem = 0;

	if(!fondoInicio.loadFromFile("img/fondo.png"))
	{
		std::cout << "Error de asignacion de fondo del menu"<<std::endl;
	}
	
	if (!font.loadFromFile("fuentes/SuperMario256.ttf"))
	{
		std::cout << "Error de asignacion de texto" <<std::endl;
	}
	fondoSprite.setTexture(fondoInicio);
	

	const std::string textos[CANT_OPCIONES] = { "Iniciar", "Puntajes", "Salir" };

	for (int i = 0; i < CANT_OPCIONES; i++) {
		opciones[i].setFont(font);
		opciones[i].setFillColor(sf::Color(255, 182, 193));
		opciones[i].setString(textos[i]);
		opciones[i].setCharacterSize(30);

		
		sf::FloatRect limites = opciones[i].getLocalBounds();
		float x = (ancho - limites.width) / 2.f - limites.left;
		float inicioY = alto * 0.55f;
		float separacion = 70.f;
		float y = inicioY + separacion * i - limites.height / 2.f - limites.top;
		opciones[i].setPosition(x, y);
	}
	opciones[selectedItem].setCharacterSize(45);
	
}

void  Menu::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(fondoSprite, states);
	for(int i=0; i<CANT_OPCIONES; i++)
	{
	target.draw(opciones[i], states);	
	}
	
}

void Menu::MoveUp()
{
	if(selectedItem > 0)
	{
		
		opciones[selectedItem].setCharacterSize(30);
		
		selectedItem--;
		
	
		opciones[selectedItem].setCharacterSize(45);
	}
}

void Menu::Movedown()
{
	if(selectedItem < CANT_OPCIONES - 1)
	{
		
		opciones[selectedItem].setCharacterSize(30);
		
		selectedItem++;
		
		
		opciones[selectedItem].setCharacterSize(45);
	}
}
