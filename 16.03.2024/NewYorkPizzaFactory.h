#pragma once
#include <iostream>
#include "PizzaFactory.h"
#include "NewYorkCheesePizza.h"
#include "NewYorkPepperoniPizza.h"
class NewYorkPizzaFactory : public PizzaFactory {
public:
    Pizza* createCheesePizza() override
    {
        return new NewYorkCheesePizza();
    }

    Pizza* createPepperoniPizza() override
    {
        return new NewYorkPepperoniPizza();
    }
};

