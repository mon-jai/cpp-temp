#ifndef TOPPING_H
#define TOPPING_H

#include <string>

class Topping {
public:
    Topping() = default;
    Topping(std::string name, double sweetnessLevel, int price);
    ~Topping() = default;

    void init(std::string name, double sweetnessLevel, int price);

    std::string getName() const { return m_Name; }
    double getSweetnessLevel() const { return m_SweetnessLevel; }
    int getPrice() const { return m_Price; }

    Topping operator=(const Topping &other);

private:
    std::string m_Name = "";
    double m_SweetnessLevel = -1;
    int m_Price = 0;
};

Topping::Topping(std::string name, double sweetnessLevel, int price) {
    init(name, sweetnessLevel, price);
}

void Topping::init(std::string name, double sweetnessLevel, int price) {
    if (!(0 <= sweetnessLevel && sweetnessLevel <= 1))
        throw std::string("Sweetness level should be between [0, 1].");

    if (!(0 <= price))
        throw std::string("Price should be between [0, inf).");

    if (name.length() < 4)
        throw std::string("The length of topping name should longer than 4.");

    m_Name = name;
    m_SweetnessLevel = sweetnessLevel;
    m_Price = price;
}

Topping Topping::operator=(const Topping &other) {
    if (this != &other)
        init(other.getName(), other.getSweetnessLevel(), other.getPrice());

    return *this;
}

#endif