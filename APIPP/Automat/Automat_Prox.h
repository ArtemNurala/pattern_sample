#ifndef AUTOMAT_PROX_H
#define AUTOMAT_PROX_H

#include "..\Orderer.h"
#include "Automat.h"
#include "Pricer.h"
#include "..\Commander.h"
#include "Strategy.h"
#include <iostream>

using namespace std;

class Automat_Prox : public Orderer {
private:
	Automat *real_automat;
	Pricer *sum_price;
	Commander *c;
	Strategy *s;
	double sum_discount, total, sum_time;
public:
	Automat_Prox(Automat *real_automat, Pricer *sum_price, Strategy *s) {
		this->real_automat = real_automat;
		this->sum_price = sum_price;
		this->s = s;
	}

	Automat_Prox() {
		this->real_automat = NULL;
	};

    double take_order(Bread *bread_comp, Recipe recipe_comp, vector<Additive *> add_comp, double in_money) override {
		total = 0;
		sum_time = double(recipe_comp.calc_time()) / 1000;
		for (auto it = add_comp.begin(); it != add_comp.end(); ++it)
			total += (*it)->get_price();
		total += bread_comp->get_price() + recipe_comp.calc_set();
		//overall *= sum_price->get_price();
		sum_discount = (100 - sum_price->get_price());
		total *= sum_discount / 100;
		if (in_money < total) {
			cout << "Insufficient funds!" << endl;
			return in_money;
		}
		stat();
		Sandwich res = real_automat->take_order(bread_comp, recipe_comp, add_comp);
		return in_money - total;
	};

	void stat() {
		cout << "Summary discount: " << sum_discount << '%' << endl;
		cout << "Summary price: " << total << endl;
		cout << "Total time: " << sum_time << " seconds" << endl;
	}

	void use_strategy() {
		this->s->stat(sum_discount, total, sum_time);
	}

	void set_strategy(Strategy *s) {
		this->s = s;
	}

	void save_command(Commander *c) {
		this->c = c;
	}

	void exec() {
		this->c->execute();
	}
};

#endif