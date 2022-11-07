#include <string>
#include <vector>
#include "topping.h"

class Drink{
public:

	Drink() = default;

	/* The constructor of the Drink. */
	Drink(std::string name, double sweetness_level, int price){}

	/* The destructor of the Drink. */
	~Drink(){}

	/* Return the name of drink. */
	std::string getName() const {}

	/* Return the level of sweetness. */
	double getSweetnessLevel() const {}

	/* Return the price of drink. */
	int getPrice() const {}

	/* Add a topping to the drink. */
	void addTopping(Topping topping){}

	/* Get the topping of drink by index, the index is determine by the order of topping added and start from 0. */
	Topping getToppingByIndex(int index) const {}

	/* Get the count of topping in drink. */
	int getToppingCount() const{}

	/* Operator overloading */
	Drink &operator=(const Drink& other){}

private:
	/* Put some attribute on here if necessary. */
};
