#include <iostream>
#include "Pizza.h"
#include "NewYorkCheesePizza.h"
#include "NewYorkPepperoniPizza.h"
#include "ChicagoCheesePizza.h"
#include "ChicagoPepperoniPizza.h"
#include "PizzaFactory.h"
#include "NewYorkPizzaFactory.h"
#include "ChicagoPizzaFactory.h"





int main()
{
   
    PizzaFactory* newYorkFactory
        = new NewYorkPizzaFactory();
    Pizza* newYorkCheesePizza
        = newYorkFactory->createCheesePizza();
    Pizza* newYorkPepperoniPizza
        = newYorkFactory->createPepperoniPizza();

 
    PizzaFactory* chicagoFactory
        = new ChicagoPizzaFactory();
    Pizza* chicagoCheesePizza
        = chicagoFactory->createCheesePizza();
    Pizza* chicagoPepperoniPizza
        = chicagoFactory->createPepperoniPizza();

   
    newYorkCheesePizza->bake();
    newYorkCheesePizza->cut();
    newYorkCheesePizza->box();

    newYorkPepperoniPizza->bake();
    newYorkPepperoniPizza->cut();
    newYorkPepperoniPizza->box();

    chicagoCheesePizza->bake();
    chicagoCheesePizza->cut();
    chicagoCheesePizza->box();

    chicagoPepperoniPizza->bake();
    chicagoPepperoniPizza->cut();
    chicagoPepperoniPizza->box();

  
    delete newYorkFactory;
    delete newYorkCheesePizza;
    delete newYorkPepperoniPizza;
    delete chicagoFactory;
    delete chicagoCheesePizza;
    delete chicagoPepperoniPizza;

    return 0;
}
