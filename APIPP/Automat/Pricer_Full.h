#ifndef PRICER_FULL_H
#define PRICER_FULL_H

#include "Pricer.h"

class Pricer_Full : public Pricer {
public:
	double get_price() override {
		return 0;
	}
};

#endif