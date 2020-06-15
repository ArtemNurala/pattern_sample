#ifndef BACKWARD_ITERATOR_H
#define BACKWARD_ITERATOR_H

#include "Iterator.h"

class Backward_Iterator : public Iterator {
public:
	Backward_Iterator(vector<Ingredient *> ing_list) {
		this->ing_list = ing_list;
		pos = ing_list.size();
		sort(ing_list.begin(), ing_list.end(), [](Ingredient *a, Ingredient *b) -> bool {
			return a->get_priority() > b->get_priority();
		});
	}

	bool hasNext() override {
		return pos > 0;
	}

	Ingredient * getNext() override {
		return hasNext() ? ing_list[--pos] : nullptr;
	}
};

#endif