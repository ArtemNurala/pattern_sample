#ifndef STRATEGY_H
#define STRATEGY_H

class Strategy {
public:
	virtual void stat(double sum_discount, double total, double time) = 0;
};

#endif