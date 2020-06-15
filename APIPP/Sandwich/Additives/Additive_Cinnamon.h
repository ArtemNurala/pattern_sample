#ifndef ADDITIVE_CINNAMON_H
#define ADDITIVE_CINNAMON_H

#include "Additive.h"
#include <string>

using namespace std;

class Additive_Cinnamon : public Additive {
private:
	int price;
	string name;
public:
	Additive_Cinnamon(int price, string name) {
		this->price = price;
		this->name = name;
	}
    int get_price() override {
		return this->price;
	}
};

#endif