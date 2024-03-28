#pragma once
#include <iostream>
#include "Pizza.h"
class ChicagoPepperoniPizza : public Pizza {
public:
    void bake() override
    {
        std::cout << "Baking Chicago-style pepperoni pizza."
            << std::endl;
    }

    void cut() override
    {
        std::cout
            << "Cutting Chicago-style pepperoni pizza."
            << std::endl;
    }

    void box() override
    {
        std::cout << "Boxing Chicago-style pepperoni pizza."
            << std::endl;
    }
};

