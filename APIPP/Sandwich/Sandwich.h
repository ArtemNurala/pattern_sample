#ifndef SANDWICH_H
#define SANDWICH_H

#include "Breads\Bread.h"
#include "Additives\Additive.h"
#include "Recipe.h"

class Sandwich {
private:
	vector<Additive *> add_comp;
	Bread *bread_comp;
	Recipe recipe_comp;
public:
	Sandwich(vector<Additive *> add_comp, Bread *bread_comp, Recipe recipe_comp) {
		this->add_comp = add_comp;
		this->bread_comp = bread_comp;
		this->recipe_comp = recipe_comp;
	}
};

#endif