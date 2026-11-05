#include "Colision.h"

Colisionable::Colisionable() {
	
}

bool Colisionable::isColision(Colisionable& obj) const{
	return getBounds().intersects(obj.getBounds());
}
