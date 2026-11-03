#pragma once
#include <SFML/Graphics.hpp>
enum class Estado{
	CORRIENDO1,
	CORRIENDO2
};

class Mono: public sf::Drawable {
private:
	sf::Texture _texture;
	sf::Sprite _sprite;
	sf::Clock _reloj;
	
	Estado _estado = Estado::CORRIENDO1;
	
	float _acumulado = 0.f;
	
public:
	Mono(float x, float yPies);
	void cargar();
	void actualizar();
	void actualizarAnimacion();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
