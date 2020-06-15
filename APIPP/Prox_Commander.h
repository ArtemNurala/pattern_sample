#ifndef PROX_COMMANDER_H
#define PROX_COMMANDER_H

#include "Automat\Automat_Prox.h"
#include "Commander.h"


class Prox_Commander : public Commander {
protected:
	Automat_Prox *c;
public:
	Prox_Commander(Automat_Prox *c) {
		this->c = c;
		c->save_command(this);
	}

	void execute() override {
		c->stat();
	}
};

#endif