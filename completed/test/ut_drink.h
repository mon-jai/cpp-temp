#ifndef UT_DRINK_H
#define UT_DRINK_H

#include <gtest/gtest.h>

#include "../src/drink.h"

class DrinkTest : public ::testing::Test {
public:
    Drink normalDrink =
        Drink("pee pee poo poo", 0.5, 100, {Topping("yoooo", 0.1, 40)});
    Drink emptyDrink;
};

TEST_F(DrinkTest, NormalName) {
    const std::string target = "pee pee poo poo";

    ASSERT_EQ(normalDrink.getName(), target);
}

TEST_F(DrinkTest, NormalSweetnessLevel) {
    const double target = 0.5;

    ASSERT_NEAR(normalDrink.getSweetnessLevel(), target, 0.01f);
}

TEST_F(DrinkTest, NormalPrice) {
    const int target = 100;

    ASSERT_EQ(normalDrink.getPrice(), target);
}

TEST_F(DrinkTest, NormalAddTopping) {
    normalDrink.addTopping(Topping("weed", 0.06, 2));

    std::size_t targetCount = 2;

    ASSERT_EQ(normalDrink.getToppingCount(), targetCount);

    std::string targetName = "weed";

    ASSERT_EQ(normalDrink.getToppingByIndex(1).getName(), targetName);
}

TEST_F(DrinkTest, NormalDrinkCopyConstructor) {
    Drink targetDrink(normalDrink);

    std::size_t targetCount = 1;

    ASSERT_EQ(targetDrink.getToppingCount(), targetCount);
}

TEST_F(DrinkTest, NormalDrinkCopyAssignment) {
    Drink targetDrink;
    targetDrink = normalDrink;

    std::size_t targetCount = 1;

    ASSERT_EQ(targetDrink.getToppingCount(), targetCount);
}

TEST_F(DrinkTest, EmptyName) {
    ASSERT_THROW(emptyDrink.getName(), std::string);
}

TEST_F(DrinkTest, EmptySweetnessLevel) {
    ASSERT_THROW(emptyDrink.getSweetnessLevel(), std::string);
}

TEST_F(DrinkTest, EmptyPrice) {
    ASSERT_THROW(emptyDrink.getPrice(), std::string);
}

TEST_F(DrinkTest, InvalidTopping) {
    ASSERT_THROW(emptyDrink.getToppingByIndex(1), std::string);
}

TEST(Drink, InvalidName) {
    ASSERT_THROW(Drink("", 0.4, 50), std::string);
}

TEST(Drink, InvalidSweetnessLevel) {
    ASSERT_THROW(Drink("long boi", 420.69, 50), std::string);
}

TEST(Drink, InvalidPrice) {
    ASSERT_THROW(Drink("even looonger boi", 0.4, -10), std::string);
}

TEST(Drink, FuckUpCopyAssignmentAttempt) {
    Drink a;
    Drink b;
    b = a;
}

#endif