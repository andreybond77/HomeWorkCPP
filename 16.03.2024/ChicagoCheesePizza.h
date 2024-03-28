#pragma once
#include <iostream>
#include "Pizza.h"
class ChicagoCheesePizza : public Pizza {
public:
    void bake() override
    {
        std::cout << "Baking Chicago-style cheese pizza."
            << std::endl;
    }

    void cut() override
    {
        std::cout << "Cutting Chicago-style cheese pizza."
            << std::endl;
    }

    void box() override
    {
        std::cout << "Boxing Chicago-style cheese pizza."
            << std::endl;
    }
};

