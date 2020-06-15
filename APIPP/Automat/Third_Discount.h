#ifndef THIRD_DISCOUNT_H
#define THIRD_DISCOUNT_H

#include "Pricer_Discount.h"

class Third_Discount : public Pricer_Discount {
public:
    double get_price() override {
		return 50 + inPrice->get_price();
	}

	Third_Discount(Pricer *inPrice) : Pricer_Discount(inPrice) {}
};

#endif