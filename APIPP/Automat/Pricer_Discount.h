#ifndef PRICER_DISCOUNT_H
#define PRICER_DISCOUNT_H

#include "Pricer.h"

class Pricer_Discount : public Pricer {
protected:
	Pricer *inPrice;
public:
    double get_price() override {
		return 20;
	}

	Pricer_Discount(Pricer *inPrice) {
		this->inPrice = inPrice;
	}
};

#endif