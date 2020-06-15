#ifndef STRATEGY_EN_H
#define STRATEGY_EN_H

#include "Strategy.h"

class Strategy_EN : public Strategy {
public:
	virtual void stat(double sum_discount, double total, double sum_time) {
		cout << "Summary discount: " << sum_discount << '%' << endl;
		cout << "Summary price: " << total << endl;
		cout << "Total time: " << sum_time << " seconds" << endl;
	}
};

#endif