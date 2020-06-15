#ifndef BREAD_WHITE_H
#define BREAD_WHITE_H

#include "Bread.h"
#include <string>

using namespace std;

class Bread_White : public Bread {
private:
	int price;
	string name;
public:
	Bread_White(int price, string name) {
		this->price = price;
		this->name = name;
	}
    int get_price() override {
		return this->price;
	}
};

#endif