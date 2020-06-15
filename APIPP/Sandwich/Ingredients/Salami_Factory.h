#ifndef SALAMI_FACTORY_H
#define SALAMI_FACTORY_H

#include "Factory.h"
#include "Ingredient.h"
#include "Ingredient_Salami.h"

class Salami_Factory : public Factory {
public:
	Ingredient * createIngr() {
		return new Ingredient_Salami(15, "Salami", 250, 20);
	}
};

#endif