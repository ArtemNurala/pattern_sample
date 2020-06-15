#ifndef INGREDIENT_BACON_H
#define INGREDIENT_BACON_H

#include "Ingredient.h"
#include <iostream>
#include <string>

using namespace std;

class Ingredient_Bacon : public Ingredient {
public:
	Ingredient_Bacon(Ingredient *another) : Ingredient(another) {}
	Ingredient_Bacon(int price, string name, int time) : Ingredient(price, name, time) {}
	Ingredient_Bacon(int price, string name, int time, int priority) : Ingredient(price, name ,time, priority) {}

    int get_price() override {
		return this->price;
	}

	int get_time() override {
		return this->time;
	}

	string get_name() override {
		return this->name;
	}

	int get_priority() {
		return this->priority;
	}

	Ingredient * get_clone() {
		return new Ingredient_Bacon(*this);
	}
};

#endif