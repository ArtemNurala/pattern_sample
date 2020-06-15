#ifndef FORWARD_ITERATOR_H
#define FORWARD_ITERATOR_H

#include "Iterator.h"

class Forward_Iterator : public Iterator {
public:
	Forward_Iterator(vector<Ingredient *> ing_list) {
		this->ing_list = ing_list;
		pos = 0;
		sort(ing_list.begin(), ing_list.end(), [](Ingredient *a, Ingredient *b) -> bool {
			return a->get_priority() < b->get_priority();
		});
	}

	bool hasNext() override {
		return pos < ing_list.size();
	}

	Ingredient * getNext() override {
		return hasNext() ? ing_list[pos++] : nullptr;
	}
};

#endif