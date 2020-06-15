#ifndef INGRFACTORY_H
#define INGRFACTORY_H

#include "Ingredient.h"
#include "Ingredient_Bacon.h"
#include "Ingredient_Salami.h"
#include "Ingredient_Salmon.h"
#include "Ingredient_Tomato.h"
#include <map>
#include <string>

using namespace std;

class IngrFactory {
	map<string, Ingredient*> mIngrs;
public:
	Ingredient & get_Ingr(string name) {
		map<string, Ingredient*>::const_iterator it = mIngrs.find(name);
		if (it == mIngrs.end()) {
			Ingredient *i;
			if (name == "Bacon")
				i = new Ingredient_Bacon(20, "Bacon", 500, 30);
			if (name == "Salami")
				i = new Ingredient_Salami(15, "Salami", 250, 20);
			if (name == "Salmon")
				i = new Ingredient_Salmon(30, "Salmon", 1000, 40);
			if (name == "Tomato")
				i = new Ingredient_Tomato(30, "Salmon", 1000, 40);
			mIngrs[name] = i;
			return *i;
		}
		else
			return *it->second;
	}
};

#endif