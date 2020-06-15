#ifndef INGREDIENT_SALMON_H
#define INGREDIENT_SALMON_H

#include "Ingredient.h"
#include <string>

using namespace std;

class Ingredient_Salmon : public Ingredient {
public:
	Ingredient_Salmon(Ingredient *another) : Ingredient(another) {}
	Ingredient_Salmon(int price, string name, int time) : Ingredient(price, name, time) {}
	Ingredient_Salmon(int price, string name, int time, int priority) : Ingredient(price, name ,time, priority) {}

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
		return new Ingredient_Salmon(*this);
	}
};

#endif