#ifndef SECOND_DISCOUNT_H
#define SECOND_DISCOUNT_H

#include "Pricer_Discount.h"

class Second_Discount : public Pricer_Discount {
public:
    double get_price() override {
		return 10 + inPrice->get_price();
	}

	Second_Discount(Pricer *inPrice) : Pricer_Discount(inPrice) {}
};

#endif