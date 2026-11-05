#pragma once
#include <SFML/Graphics.hpp>
#include "Colision.h"
enum class Princesa{
	CORRIENDO1,
	CORRIENDO2,
	SALTA
};

class Personaje: public sf::Drawable, public Colisionable{
private:
	sf::Texture _texture;
	sf::Sprite _sprite;
	sf::Clock _reloj;
	
	Princesa _estado = Princesa::CORRIENDO1;
	float _tiempoFrame = 0.15f;
	float _acumulado = 0.f;
	float _velocity = 0.f;
	float _gravity = 2000.f;
	float _impulso = 1200.f;
	float _ySuelo;
	bool _enSuelo;
	
	
public:
	Personaje(float x, float yPies);
	
	void saltar();
	void actualizar();
	float getAlto() const;
	void pararseEn(float yPies);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	sf::FloatRect getBounds() const override;
private:
	void cargar();
	void actualizarAnimacion();
};
