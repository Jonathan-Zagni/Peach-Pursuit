#pragma once
#include <SFML/Graphics.hpp>
#include "Colision.h"
enum class Estado{
	CORRIENDO1,
	CORRIENDO2,
	SALTO
};

class Mono: public sf::Drawable, public Colisionable {
private:
	sf::Texture _texture;
	sf::Sprite _sprite;
	sf::Clock _reloj;
	
	Estado _estado = Estado::CORRIENDO1;
	
	float _acumulado = 0.f;
	float _posX;
	float _posY;
	bool _enSuelo = true;
	float _velocity;
	float _impulso = 900.f;
	float _gravity = 1900.f;
	
public:
	Mono(float x, float yPies);
	
	void pararseEn(float yPies);
	void acercar();
	void saltar();
	void cargar();
	void actualizar();
	void actualizarAnimacion();
	sf::FloatRect getBounds() const override;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
