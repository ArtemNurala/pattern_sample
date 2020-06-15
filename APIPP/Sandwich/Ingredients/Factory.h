#ifndef FACTORY_H
#define FACTORY_H

#include "Ingredient.h"

class Factory {
public:
	virtual Ingredient * createIngr() = 0;
};

#endif