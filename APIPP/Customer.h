#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Orderer.h"
#include "Automat\Automat_Prox.h"
#include "Customer_Memento.h"
#include "Prox_Commander.h"

class Customer : public Orderer {
private:
    double money;
	Automat_Prox *automat;
	Customer_Memento *memento;
	Commander *c;
public:
	Customer(double money, Automat_Prox *automat, Commander *c) {
		this->money = money;
		this->automat = automat;
		memento = NULL;
		this->c = c;
	}

    double take_order(Bread *bread_comp, Recipe recipe_comp, vector<Additive *> add_comp, double in_money) override {
		double res = this->automat->take_order(bread_comp, recipe_comp, add_comp, in_money);
		this->money = res;
		return res;
	};

	double get_money() {
		return this->money;
	}

	void create_copy() {
		if (!memento) {
			this->memento = new Customer_Memento(0, *this->automat);
			return;
		}
		this->memento->set_state(0);
	}

	void reset_state() {
		this->memento->set_state(this->money);
	}

	void restore_state() {
		this->money = this->memento->get_state();
	}

	void press_button() {
		this->automat->exec();
	}
};

#endif