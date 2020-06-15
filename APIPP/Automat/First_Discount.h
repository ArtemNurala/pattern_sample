#ifndef FIRST_DISCOUNT_H
#define FIRST_DISCOUNT_H

#include "Pricer_Discount.h"
#include <iostream>

using namespace std;

class First_Discount : public Pricer_Discount {
public:
    double get_price() override {
		return 5 + inPrice->get_price();
	}

	First_Discount(Pricer *inPrice) : Pricer_Discount(inPrice) {}
};

#endif