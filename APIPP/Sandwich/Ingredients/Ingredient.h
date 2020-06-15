#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <string>

using namespace std;

class Ingredient {
protected:
	string name;
	int price;
	int time;
	int priority;
public:
	Ingredient(Ingredient *another) {
		this->price = another->price;
		this->name = another->name;
		this->time = another->time;
		this->priority = another->priority;
	}

	Ingredient(int price, string name, int time) {
		this->price = price;
		this->name = name;
		this->time = time;
	}

	Ingredient(int price, string name, int time, int priority) {
		this->price = price;
		this->name = name;
		this->time = time;
		this->priority = priority;
	}

    virtual int get_price() = 0;
	virtual int get_time() = 0;
	virtual string get_name() = 0;
	virtual int get_priority() = 0;
	virtual Ingredient * get_clone() = 0;
};

#endif