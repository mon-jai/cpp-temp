#ifndef DRINK_H
#define DRINK_H

#include <iostream>
#include <string>
#include <vector>

#include "topping.h"

class Drink {
public:
    Drink() = default;
    Drink(const std::string name, const double sweetnessLevel, const int price,
          const std::vector<Topping> toppings = {});
    ~Drink() = default;

    std::string getName() const;
    double getSweetnessLevel() const;
    int getPrice() const;
    Topping getToppingByIndex(const std::size_t index) const;
    std::size_t getToppingCount() const;

    void addTopping(const Topping topping);

    Drink &operator=(const Drink &other) = default;

private:
    std::string m_Name = "";
    double m_SweetnessLevel = -1;
    int m_Price = -1;
    std::vector<Topping> m_Toppings = {};
};

Drink::Drink(const std::string name, const double sweetnessLevel,
             const int price, const std::vector<Topping> toppings) {
    if (name.size() < 4)
        throw std::string("Invalid Name");

    if (sweetnessLevel > 1 || sweetnessLevel < 0)
        throw std::string("Invalid Sweetness Level");

    if (price < 0)
        throw std::string("Invalid Price");

    m_Name = name;
    m_SweetnessLevel = sweetnessLevel;
    m_Price = price;
    m_Toppings = toppings;
}

std::string Drink::getName() const {
    if (m_Name == "")
        throw std::string("Empty Name");

    return m_Name;
}

double Drink::getSweetnessLevel() const {
    if (m_SweetnessLevel == -1)
        throw std::string("Empty Sweetness Level");

    return m_SweetnessLevel;
}

int Drink::getPrice() const {
    if (m_Price == -1)
        throw std::string("Empty Price");

    return m_Price;
}

Topping Drink::getToppingByIndex(const std::size_t index) const {
    std::size_t size = getToppingCount();

    if (index >= size)
        throw std::string("Index Out of Range");

    return m_Toppings[index];
}

std::size_t Drink::getToppingCount() const {
    return m_Toppings.size();
}

void Drink::addTopping(const Topping topping) {
    m_Toppings.push_back(topping);
    m_SweetnessLevel += topping.getSweetnessLevel();
    m_Price += topping.getPrice();
}

#endif