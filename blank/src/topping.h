#include <string>

class Topping{
    public:
        void init(std::string name, double sweetness_level, int price){
            if(!(0 <= sweetness_level && sweetness_level <= 1)){
                throw std::string("Sweetness level should be between [0, 1].");
            }
            if(!(0 <= price)){
                throw std::string("Price should be between [0, inf).");
            }
            if(name.length() < 4){
                throw std::string("The length of topping name should longer than 4.");
            }
            _topping_name = name;
            _topping_sweetness_level = sweetness_level;
            _topping_price = price;
        }

        Topping() = default;
        Topping(std::string name, double sweetness_level, int price){
            init(name, sweetness_level, price);
        }
        ~Topping() = default;
        double getSweetnessLevel() const {
            return _topping_sweetness_level;
        }
        int getPrice() const {
            return _topping_price;
        }
        std::string getName() const {
            return _topping_name;
        }
        Topping operator=(const Topping &other){
            if (this != &other){
                init(other.getName(), other.getSweetnessLevel(), other.getPrice());
            }
            return *this;
        }
    private:
        double _topping_sweetness_level = -1;
        int _topping_price = 0;
        std::string _topping_name = "";
};
