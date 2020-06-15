#ifndef CUSTOMER_MEMENTO_H
#define CUSTOMER_MEMENTO_H

#include "Automat\Automat_Prox.h"

class Customer_Memento {
private:
    double money;
	Automat_Prox automat;
public:
	Customer_Memento(double money, Automat_Prox automat) {
		this->money = money;
		this->automat = automat;
	}

	void set_state(double money) {
		this->money = money;
	}

	double get_state() {
		return this->money;
	}
};

#endif