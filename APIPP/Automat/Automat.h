#ifndef AUTOMAT_H
#define AUTOMAT_H

#include "..\Sandwich\Sandwich.h"
#include "Sandwich\Breads\Bread.h"
#include "Sandwich\Recipe.h"
#include "Sandwich\Additives\Additive.h"
#include <vector>
#include <iostream>
#include <Windows.h>

using namespace std;

class Automat {
	static Automat *only_one;
	Automat() {}
public:
    Sandwich take_order(Bread *bread_comp, Recipe recipe_comp, vector<Additive *> add_comp) {
		for (auto it = recipe_comp.get_ing().begin(); it != recipe_comp.get_ing().end(); ++it){
			cout << "Preparing " << (*it)->get_name() << "...";
			Sleep((*it)->get_time());
			cout << endl;
		}
		cout << "Finished!" << endl;
		return Sandwich(add_comp, bread_comp, recipe_comp);
	}

	static Automat * get_instance() {
		if (!only_one)
			only_one = new Automat();
		return only_one;
	}
};

#endif