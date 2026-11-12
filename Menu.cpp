#include "Menu.h"

Menu::Menu(sf::Vector2u tamVentana): alto(tamVentana.y), ancho(tamVentana.x), selectedItem(0) {
	cargar();
}

void Menu::cargar(){
	if(!fondoInicio.loadFromFile("img/fondo.png"))
	{
		std::cout << "Error de asignacion de fondo del menu"<<std::endl;
		return;
	}
	
	if (!font.loadFromFile("fuentes/SuperMario256.ttf"))
	{
		std::cout << "Error de asignacion de texto" <<std::endl;
		return;
	}
	fondoSprite.setTexture(fondoInicio);
	
	sf::Vector2u tamTex = fondoInicio.getSize();
	if (tamTex.x > 0 && tamTex.y > 0) {
		fondoSprite.setScale(ancho / static_cast<float>(tamTex.x),
		                     alto  / static_cast<float>(tamTex.y));
	}
	
	const std::string textos[CANT_OPCIONES] = { "Iniciar", "Puntajes", "Salir" };
	
	for (int i = 0; i < CANT_OPCIONES; i++) {
		opciones[i].setFont(font);
		opciones[i].setFillColor(sf::Color(255, 182, 193));
		opciones[i].setString(textos[i]);
		opciones[i].setCharacterSize(30);
		
		
		centrarOpcion(i);
	}
	opciones[selectedItem].setCharacterSize(45);
	centrarOpcion(selectedItem);
}

void  Menu::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(fondoSprite, states);
	for(int i=0; i<CANT_OPCIONES; i++)
	{
	target.draw(opciones[i], states);	
	}
	
}

void Menu::centrarOpcion(int indice)
{
	sf::FloatRect limites = opciones[indice].getLocalBounds();
	float x = (ancho - limites.width) / 2.f - limites.left;
	float inicioY = alto * 0.55f;
	float separacion = 70.f;
	float y = inicioY + separacion * indice - limites.height / 2.f - limites.top;
	opciones[indice].setPosition(x, y);
}

void Menu::moveUp()
{
	if(selectedItem > 0)
	{
		opciones[selectedItem].setCharacterSize(30);
		centrarOpcion(selectedItem);
		
		selectedItem--;
		
		opciones[selectedItem].setCharacterSize(45);
		centrarOpcion(selectedItem);
	}
}

void Menu::moveDown()
{
	if(selectedItem < CANT_OPCIONES - 1)
	{
		opciones[selectedItem].setCharacterSize(30);
		centrarOpcion(selectedItem);
		
		selectedItem++;
		
		opciones[selectedItem].setCharacterSize(45);
		centrarOpcion(selectedItem);
	}
}

int Menu::getSelectedItem(){
	return selectedItem;
}
