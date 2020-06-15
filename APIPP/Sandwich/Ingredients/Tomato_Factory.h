#ifndef TOMATO_FACTORY_H
#define TOMATO_FACTORY_H

#include "Factory.h"
#include "Ingredient.h"
#include "Ingredient_Tomato.h"

class Tomato_Factory : public Factory {
public:
	Ingredient * createIngr() {
		return new Ingredient_Tomato(10, "Tomato", 100, 10);
	}
};

#endif