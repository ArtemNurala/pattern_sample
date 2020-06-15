#ifndef RECIPE_H
#define RECIPE_H

#include "Ingredients\Ingredient.h"
#include "Ingredients\IngrFactory.h"
#include "Ingredients\Bacon_Factory.h"
#include "Ingredients\Salami_Factory.h"
#include "Ingredients\Salmon_Factory.h"
#include "Ingredients\Tomato_Factory.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Recipe{
private:
	IngrFactory storage;
	vector<Ingredient *> variant;
	string name;
public:
	Recipe(vector<Ingredient *> variant, string name) {
		this->variant = variant;
		this->name = name;
	}

	/*Recipe(vector<string> names, string name) {
		for (auto it = names.begin(); it != names.end(); ++it)
			this->variant.push_back(&storage.get_Ingr(*it));
	}*/

	Recipe(vector<string> names, string name) {
		for (auto it = names.begin(); it != names.end(); ++it) {
			if (*it == "Bacon")
				this->variant.push_back(Bacon_Factory().createIngr());
			if (*it == "Salami")
				this->variant.push_back(Salami_Factory().createIngr());
			if (*it == "Salmon")
				this->variant.push_back(Salmon_Factory().createIngr());
			if (*it == "Tomato")
				this->variant.push_back(Tomato_Factory().createIngr());
		}
	}
	
	Recipe(string name) {
		this->name = name;
	}

	Recipe() {};

	int calc_set() {
		int sum = 0;
		for (auto it = variant.begin(); it != variant.end(); ++it)
			sum += (*it)->get_price();
		return sum;
	}

	int calc_time() {
		int sum = 0;
		for (auto it = variant.begin(); it != variant.end(); ++it)
			sum += (*it)->get_time();
		return sum;
	}

	const vector<Ingredient *> & get_ing() {
		return variant;
	}

	void add_ing(Ingredient* ing) {
		this->variant.push_back(ing);
	}

	void remove_ing(string name) {
		for (auto it = variant.begin(); it != variant.end(); ++it)
			if ((*it)->get_name() == name) {
				variant.erase(it);
				return;
			}
		cout << "No such ingredient!" << endl;
	}

	void display_ing() {
		cout << "List of ingredients:" << endl;
		for (auto it = variant.begin(); it != variant.end(); ++it)
			cout << (*it)->get_name() << ' ';
		cout << endl;
	}
};

#endif