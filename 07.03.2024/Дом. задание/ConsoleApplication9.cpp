

using namespace std;
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    sf::RectangleShape rectangle(sf::Vector2f(50.f, 50.f));
    rectangle.setFillColor(sf::Color::White);
    rectangle.setOutlineThickness(1.f);
    rectangle.setOutlineColor(sf::Color::Black);
    int soccetSize = 50;
    std::vector<sf::RectangleShape>field;
    for (int i = 0; i <= window.getSize().y - soccetSize; i += soccetSize) {
        for (int j = 0; j <= window.getSize().x - soccetSize; j += soccetSize) {
           
            rectangle.setSize(sf::Vector2f(soccetSize, soccetSize));
            rectangle.setPosition(sf::Vector2f(j, i));
            field.push_back(rectangle);
        }
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) 
              
            {
               
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                for (auto& el : field) {
                    if ((mousePos.x >= el.getPosition().x) &&
                        (mousePos.x <= (el.getPosition().x + el.getSize().x)) &&
                        (mousePos.y >= el.getPosition().y) &&
                        (mousePos.y <= (el.getPosition().y + el.getSize().y))) {
                    
                        el.setFillColor(sf::Color::Red);
                      
                        


                    }
                }

            }


            if (sf::Mouse::isButtonPressed(sf::Mouse::Right))

            {

                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                for (auto& el : field) {
                    if ((mousePos.x >= el.getPosition().x) &&
                        (mousePos.x <= (el.getPosition().x + el.getSize().x)) &&
                        (mousePos.y >= el.getPosition().y) &&
                        (mousePos.y <= (el.getPosition().y + el.getSize().y))) {

                        el.setFillColor(sf::Color::Blue);




                    }
                }

            }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Middle))

            {

                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                for (auto& el : field) {
                    if ((mousePos.x >= el.getPosition().x) &&
                        (mousePos.x <= (el.getPosition().x + el.getSize().x)) &&
                        (mousePos.y >= el.getPosition().y) &&
                        (mousePos.y <= (el.getPosition().y + el.getSize().y))) {

                        el.setFillColor(sf::Color::Green);




                    }
                }

            }

        }

        window.clear();
        for (auto el : field) {
            window.draw(el);
        }
        window.draw(rectangle);
        window.display();
    }

    return 0;
}
