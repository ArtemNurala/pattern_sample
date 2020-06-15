#ifndef BREAD_BROWN_H
#define BREAD_BROWN_H

#include "Bread.h"
#include <string>

using namespace std;

class Bread_Brown : public Bread {
private:
	int price;
	string name;
public:
	Bread_Brown(int price, string name) {
		this->price = price;
		this->name = name;
	}
    int get_price() override {
		return this->price;
	}};

#endif