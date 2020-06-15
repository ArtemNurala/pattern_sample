#ifndef SALMON_FACTORY_H
#define SALMON_FACTORY_H

#include "Factory.h"
#include "Ingredient.h"
#include "Ingredient_Salmon.h"

class Salmon_Factory : public Factory {
public:
	Ingredient * createIngr() {
		return new Ingredient_Salmon(30, "Salmon", 1000, 40);
	}
};

#endif