#ifndef ORDERER_H
#define ORDERER_H

#include "Sandwich\Breads\Bread.h"
#include "Sandwich\Recipe.h"
#include "Sandwich\Additives\Additive.h"
#include <vector>

using namespace std;

class Orderer {
public:
    virtual double take_order(Bread *bread_comp, Recipe recipe_comp, vector<Additive *> add_comp, double in_money) = 0;
};

#endif