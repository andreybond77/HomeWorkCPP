#pragma once
#include <iostream>
#include "Pizza.h"
class NewYorkCheesePizza : public Pizza {
public:
    void bake() override
    {
        std::cout << "Baking New York-style cheese pizza."
            << std::endl;
    }

    void cut() override
    {
        std::cout << "Cutting New York-style cheese pizza."
            << std::endl;
    }

    void box() override
    {
        std::cout << "Boxing New York-style cheese pizza."
            << std::endl;
    }
};

