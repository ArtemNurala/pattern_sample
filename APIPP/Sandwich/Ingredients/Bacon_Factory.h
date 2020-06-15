#ifndef BACON_FACTORY_H
#define BACON_FACTORY_H

#include "Factory.h"
#include "Ingredient.h"
#include "Ingredient_Bacon.h"

class Bacon_Factory : public Factory {
public:
	Ingredient * createIngr() {
		return new Ingredient_Bacon(20, "Bacon", 500, 30);
	}
};

#endif