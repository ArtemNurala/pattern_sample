#include "stdafx.h"
#include <iostream>

#include "Customer.h"
#include "Automat\Pricer_Discount.h"
#include "Automat\Pricer_Full.h"
#include "Automat\First_Discount.h"
#include "Automat\Second_Discount.h"
#include "Automat\Third_Discount.h"
#include "Sandwich\Breads\Bread_Brown.h"
#include "Sandwich\Breads\Bread_White.h"
#include "Sandwich\Additives\Additive_Cheese.h"
#include "Sandwich\Additives\Additive_Cinnamon.h"
#include "Sandwich\Ingredients\Ingredient_Bacon.h"
#include "Sandwich\Ingredients\Ingredient_Salami.h"
#include "Sandwich\Ingredients\Ingredient_Salmon.h"
#include "Sandwich\Ingredients\Ingredient_Tomato.h"
#include "Sandwich\Forward_Iterator.h"
#include "Sandwich\Backward_Iterator.h"
#include "Automat\Strategy_EN.h"

Automat *Automat::only_one = NULL;

int main() {
	Bread *brown_one = new Bread_Brown(10, "Brown");
	Bread *white_one = new Bread_White(15, "White");

	Additive *cheese_one = new Additive_Cheese(5, "Cheese");
	Additive *cinnamon_one = new Additive_Cinnamon(2, "Cinnamon");

	Ingredient_Bacon *bacon_sample = new Ingredient_Bacon(20, "Bacon", 500, 30);
	Ingredient *bacon_one = bacon_sample->get_clone();
	Ingredient_Salami *salami_sample = new Ingredient_Salami(15, "Salami", 250, 20);
	Ingredient *salami_one = salami_sample->get_clone();
	Ingredient_Salmon *salmon_sample = new Ingredient_Salmon(30, "Salmon", 1000, 40);
	Ingredient *salmon_one = salmon_sample->get_clone();
	Ingredient_Tomato *tomato_sample = new Ingredient_Tomato(10, "Tomato", 100, 10);
	Ingredient *tomato_one = tomato_sample->get_clone();

	/*vector<Ingredient *> *bacon_n_tomat = new vector<Ingredient *>();
	bacon_n_tomat->push_back(bacon_one);
	bacon_n_tomat->push_back(tomato_one);
	vector<Ingredient *> *bacon_n_salmon = new vector<Ingredient *>;
	bacon_n_salmon->push_back(bacon_one);
	bacon_n_salmon->push_back(salmon_one);*/

	vector<Additive *> cheese_n_cinnamon;
	cheese_n_cinnamon.push_back(cheese_one);
	cheese_n_cinnamon.push_back(cinnamon_one);
	vector<Additive *> just_cinnamon;
	just_cinnamon.push_back(cinnamon_one);

	/*Recipe *tomat_n_bacon = new Recipe(bacon_n_tomat, "Bacon and Tomato");
	Recipe *salmon_n_bacon = new Recipe(bacon_n_salmon, "Bacon and Salmon");*/
	//Sandwich *first_one = new Sandwich(cheese_n_cinnamon, brown_one, bacon_n_tomato);
	//Sandwich *second_one = new Sandwich(cheese_n_cinnamon, white_one, bacon_n_tomato);
	
	/*Recipe tomat_n_bacon("Bacon and Tomato");
	tomat_n_bacon.add_ing(tomato_one);
	tomat_n_bacon.add_ing(bacon_one);
	tomat_n_bacon.add_ing(salmon_one);
	tomat_n_bacon.display_ing();
	tomat_n_bacon.remove_ing(salmon_one->get_name());
	tomat_n_bacon.display_ing();*/






	vector<string> instance;
	instance.push_back("Bacon");
	instance.push_back("Salmon");
	Recipe salmon_n_bacon(instance, "Salmon and Bacon");
	Strategy *s = new Strategy_EN();
	Automat_Prox *someauto = new Automat_Prox(Automat::get_instance(), new First_Discount(new Second_Discount(new Third_Discount(new Pricer_Full))), s);
	someauto->set_strategy(s);
	Customer customer(Customer(1000, someauto, new Prox_Commander(someauto)));
	customer.create_copy();
	customer.reset_state();
	cout << "Change: " << customer.take_order(white_one, salmon_n_bacon, cheese_n_cinnamon, customer.get_money()) << endl;
	Automat *gh = Automat::get_instance();
	someauto->use_strategy();
	/*cout << "Before restoring: " << customer.get_money() << endl;
	customer.restore_state();
	cout << "After restoring: " << customer.get_money() << endl;
	customer.press_button();*/

	/*Backward_Iterator *bbt = new Backward_Iterator(*bacon_n_tomat);
	Backward_Iterator *bbs = new Backward_Iterator(*bacon_n_salmon);
	Forward_Iterator *fbs = new Forward_Iterator(*bacon_n_salmon);
	Forward_Iterator *fbt = new Forward_Iterator(*bacon_n_tomat);
	while (bbt->hasNext())
		cout << bbt->getNext()->get_name() << ' ';
	cout << endl;*/
}