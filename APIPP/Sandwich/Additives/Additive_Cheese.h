#ifndef ADDITIVE_CHEESE_H
#define ADDITIVE_CHEESE_H

#include "Additive.h"
#include <string>

using namespace std;

class Additive_Cheese : public Additive {
private:
	int price;
	string name;
public:
	Additive_Cheese(int price, string name)  {
		this->price = price;
		this->name = name;
	}
    int get_price() override {
		return this->price;
	}
};

#endif