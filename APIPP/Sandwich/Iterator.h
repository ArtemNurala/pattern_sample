#ifndef ITERATOR_H
#define ITERATOR_H

#include "Ingredients\Ingredient.h"
#include <vector>
#include <algorithm>

class Iterator {
protected:
	vector<Ingredient *> ing_list;
	unsigned int pos;
public:
	virtual bool hasNext() = 0;
	virtual Ingredient * getNext() = 0;
};

#endif