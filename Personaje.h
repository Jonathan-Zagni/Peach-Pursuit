#pragma once
#include <SFML/Graphics.hpp>

enum class Princesa{
	CORRIENDO1,
	CORRIENDO2
};

class Personaje: public sf::Drawable{
private:
	sf::Texture _texture;
	sf::Sprite _sprite;
	sf::Clock _reloj;
	
	Princesa _estado = Princesa::CORRIENDO1;
	float _tiempoFrame = 0.15f;
	float _acumulado = 0.f;
	
public:
	Personaje(float x, float yPies);
	
	void actualizar();
	float getAlto() const;
	void pararseEn(float yPies);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	void cargar();
	void actualizarAnimacion();
};
