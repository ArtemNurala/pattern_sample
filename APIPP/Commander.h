#ifndef COMMANDER_H
#define COMMANDER_H

#include "Sandwich\Breads\Bread.h"
#include "Sandwich\Additives\Additive.h"
#include "Sandwich\Recipe.h"

class Commander {
public:
	virtual void execute() = 0;
};

#endif