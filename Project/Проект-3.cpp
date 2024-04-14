

#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
#include<string>

int get_rand(int a, int b) {
    return rand() % (b - a + 1) + a;
}




int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    //system("pause");
    int r = 0, g = 0, b = 0, y = 0;

    sf::RenderWindow window(sf::VideoMode(800, 600), "Warehouse");
    int soccetSize = 50;
    int q = 0;
    std::vector<sf::RectangleShape> field;
    for (int i = 0; i <= window.getSize().y - soccetSize; i += soccetSize) {
        for (int j = 0; j <= window.getSize().x - soccetSize; j += soccetSize) {

            sf::RectangleShape soccet;




            soccet.setOutlineThickness(1);
            soccet.setOutlineColor(sf::Color::Black);
            soccet.setSize(sf::Vector2f(soccetSize, soccetSize));
            soccet.setPosition(sf::Vector2f(j, i));
            field.push_back(soccet);




        }

    }




    //---------------------------------------------------------
    sf::RectangleShape rectangle_R(sf::Vector2f(50, 50));
    rectangle_R.setFillColor(sf::Color::Red);
    rectangle_R.setPosition(sf::Vector2f(0, 0));



    sf::RectangleShape rectangle_B(sf::Vector2f(50, 50));
    rectangle_B.setFillColor(sf::Color::Blue);
    rectangle_B.setPosition(sf::Vector2f(0, 550));



    sf::RectangleShape rectangle_G(sf::Vector2f(50, 50));
    rectangle_G.setFillColor(sf::Color::Green);
    rectangle_G.setPosition(sf::Vector2f(750, 0));



    sf::RectangleShape rectangle_Y(sf::Vector2f(50, 50));
    rectangle_Y.setFillColor(sf::Color::Yellow);
    rectangle_Y.setPosition(sf::Vector2f(750, 550));
    //--------------------------------------------------------------------
    std::string fieldText_R = std::to_string(r);
    sf::Text text_R;
    sf::Font font;
    font.loadFromFile("arialbd.ttf");
    text_R.setFont(font);
    text_R.setString(fieldText_R);
    text_R.setCharacterSize(44);
    text_R.setFillColor(sf::Color::Black);
    text_R.setPosition(sf::Vector2f(0, 0));

    std::string fieldText_G = std::to_string(g);
    sf::Text text_G;
    // sf::Font font;
    font.loadFromFile("arialbd.ttf");
    text_G.setFont(font);
    text_G.setString(fieldText_G);
    text_G.setCharacterSize(44);
    text_G.setFillColor(sf::Color::Black);
    text_G.setPosition(sf::Vector2f(750, 0));

    std::string fieldText_B = std::to_string(b);
    sf::Text text_B;
    // sf::Font font;
    font.loadFromFile("arialbd.ttf");
    text_B.setFont(font);
    text_B.setString(fieldText_B);
    text_B.setCharacterSize(44);
    text_B.setFillColor(sf::Color::Black);
    text_B.setPosition(sf::Vector2f(0, 550));


    std::string fieldText_Y = std::to_string(y);
    sf::Text text_Y;
    //  sf::Font font;
    font.loadFromFile("arialbd.ttf");
    text_Y.setFont(font);
    text_Y.setString(fieldText_Y);
    text_Y.setCharacterSize(44);
    text_Y.setFillColor(sf::Color::Black);
    text_Y.setPosition(sf::Vector2f(750, 550));

    //------------------------------------------------------------------------------
    sf::CircleShape circle(soccetSize / 2);
    circle.setFillColor(sf::Color::Black);
    int countSoccetsWidth = window.getSize().x / soccetSize - 1;
    int countSoccetsHeight = window.getSize().y / soccetSize - 1;
    sf::Vector2f positionCircle(countSoccetsWidth / 2, countSoccetsHeight / 2);
    circle.setPosition(sf::Vector2f(positionCircle.x * soccetSize,
        positionCircle.y * soccetSize));





    sf::CircleShape circle_G(soccetSize / 2);
    circle_G.setFillColor(sf::Color::Green);
    int countSoccetsWidth_G = window.getSize().x / soccetSize - 1;
    int countSoccetsHeight_G = window.getSize().y / soccetSize - 1;
    sf::Vector2f positionCircle_G(countSoccetsWidth_G / 2 + get_rand(-5, 5), countSoccetsHeight_G / 2 + get_rand(-5, 5));
    circle_G.setPosition(sf::Vector2f(positionCircle_G.x * soccetSize,
        positionCircle_G.y * soccetSize));



    sf::CircleShape circle_R(soccetSize / 2);
    circle_R.setFillColor(sf::Color::Red);
    int countSoccetsWidth_R = window.getSize().x / soccetSize - 1;
    int countSoccetsHeight_R = window.getSize().y / soccetSize - 1;
    sf::Vector2f positionCircle_R(countSoccetsWidth_R / 2 + get_rand(-5, 5), countSoccetsHeight_R / 2 + get_rand(-5, 5));
     circle_R.setPosition(sf::Vector2f(positionCircle_R.x * soccetSize,
       positionCircle_R.y * soccetSize));
   


    sf::CircleShape circle_B(soccetSize / 2);
    circle_B.setFillColor(sf::Color::Blue);
    int countSoccetsWidth_B = window.getSize().x / soccetSize - 1;
    int countSoccetsHeight_B = window.getSize().y / soccetSize - 1;
    sf::Vector2f positionCircle_B(countSoccetsWidth_B / 2 + get_rand(-5, 5), countSoccetsHeight_B / 2 + get_rand(-5, 5));
    circle_B.setPosition(sf::Vector2f(positionCircle_B.x * soccetSize,
        positionCircle_B.y * soccetSize));

    sf::CircleShape circle_Y(soccetSize / 2);
    circle_Y.setFillColor(sf::Color::Yellow);
    int countSoccetsWidth_Y = window.getSize().x / soccetSize - 1;
    int countSoccetsHeight_Y = window.getSize().y / soccetSize - 1;
    sf::Vector2f positionCircle_Y(countSoccetsWidth_Y / 2 + get_rand(-5, 5), countSoccetsHeight_Y / 2 + get_rand(-5, 5));
    circle_Y.setPosition(sf::Vector2f(positionCircle_Y.x * soccetSize,
        positionCircle_Y.y * soccetSize));


    //---------------------------------------------------------------------------------------------------

    while (window.isOpen())
    {



        sf::Event event;
        while (window.pollEvent(event))
        {



            if (event.type == sf::Event::Closed)
                window.close();





            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))




                if (positionCircle.x > 0) positionCircle.x--;

            



            if (positionCircle.x == positionCircle_G.x && positionCircle.y == positionCircle_G.y&& positionCircle_G.x>0) positionCircle_G.x--;
            if (positionCircle_G.x == positionCircle_R.x && positionCircle_G.y == positionCircle_R.y) positionCircle.x++ && positionCircle_G.x++;
            if (positionCircle_G.x == positionCircle_B.x && positionCircle_G.y == positionCircle_B.y)  positionCircle.x++ && positionCircle_G.x++;
            if (positionCircle_G.x == positionCircle_Y.x && positionCircle_G.y == positionCircle_Y.y)  positionCircle.x++ && positionCircle_G.x++;



            if (positionCircle_R.x > 0);
            if (positionCircle.x == positionCircle_R.x && positionCircle.y == positionCircle_R.y&&positionCircle_R.x>0) positionCircle_R.x--;
            if (positionCircle_R.x == positionCircle_G.x && positionCircle_R.y == positionCircle_G.y) positionCircle.x++ && positionCircle_R.x++;
            if (positionCircle_R.x == positionCircle_B.x && positionCircle_R.y == positionCircle_B.y)  positionCircle.x++ && positionCircle_R.x++;
            if (positionCircle_R.x == positionCircle_Y.x && positionCircle_R.y == positionCircle_Y.y)  positionCircle.x++ && positionCircle_R.x++;


            if (positionCircle_B.x > 0);
            if (positionCircle.x == positionCircle_B.x && positionCircle.y == positionCircle_B.y&&positionCircle_B.x>0) positionCircle_B.x--;
            if (positionCircle_B.x == positionCircle_R.x && positionCircle_B.y == positionCircle_R.y) positionCircle.x++ && positionCircle_B.x++;
            if (positionCircle_B.x == positionCircle_G.x && positionCircle_B.y == positionCircle_G.y)  positionCircle.x++ && positionCircle_B.x++;
            if (positionCircle_B.x == positionCircle_Y.x && positionCircle_B.y == positionCircle_Y.y)  positionCircle.x++ && positionCircle_B.x++;

            if (positionCircle_Y.x > 0);
            if (positionCircle.x == positionCircle_Y.x && positionCircle.y == positionCircle_Y.y&& positionCircle_Y.x > 0) positionCircle_Y.x--;
            if (positionCircle_Y.x == positionCircle_R.x && positionCircle_Y.y == positionCircle_R.y) positionCircle.x++ && positionCircle_Y.x++;
            if (positionCircle_Y.x == positionCircle_G.x && positionCircle_Y.y == positionCircle_G.y)  positionCircle.x++ && positionCircle_Y.x++;
            if (positionCircle_Y.x == positionCircle_B.x && positionCircle_Y.y == positionCircle_B.y)  positionCircle.x++ && positionCircle_Y.x++;



            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                if (positionCircle.x < countSoccetsWidth) positionCircle.x++;

            if (positionCircle_G.x < countSoccetsWidth);
            if (positionCircle.x == positionCircle_G.x && positionCircle.y == positionCircle_G.y&& positionCircle_G.x < countSoccetsWidth) positionCircle_G.x++;
            if (positionCircle_G.x == positionCircle_R.x && positionCircle_G.y == positionCircle_R.y) positionCircle.x-- && positionCircle_G.x--;
            if (positionCircle_G.x == positionCircle_B.x && positionCircle_G.y == positionCircle_B.y)  positionCircle.x-- && positionCircle_G.x--;
            if (positionCircle_G.x == positionCircle_Y.x && positionCircle_G.y == positionCircle_Y.y)  positionCircle.x-- && positionCircle_G.x--;


            if (positionCircle_R.x < countSoccetsWidth);
            if (positionCircle.x == positionCircle_R.x && positionCircle.y == positionCircle_R.y&& positionCircle_R.x < countSoccetsWidth) positionCircle_R.x++;
            if (positionCircle_R.x == positionCircle_G.x && positionCircle_R.y == positionCircle_G.y) positionCircle.x-- && positionCircle_R.x--;
            if (positionCircle_R.x == positionCircle_B.x && positionCircle_R.y == positionCircle_B.y)  positionCircle.x-- && positionCircle_R.x--;
            if (positionCircle_R.x == positionCircle_Y.x && positionCircle_R.y == positionCircle_Y.y)  positionCircle.x-- && positionCircle_R.x--;


            if (positionCircle_B.x < countSoccetsWidth);
            if (positionCircle.x == positionCircle_B.x && positionCircle.y == positionCircle_B.y&& positionCircle_B.x < countSoccetsWidth) positionCircle_B.x++;
            if (positionCircle_B.x == positionCircle_R.x && positionCircle_B.y == positionCircle_R.y) positionCircle.x-- && positionCircle_B.x--;
            if (positionCircle_B.x == positionCircle_G.x && positionCircle_B.y == positionCircle_G.y)  positionCircle.x-- && positionCircle_B.x--;
            if (positionCircle_B.x == positionCircle_Y.x && positionCircle_B.y == positionCircle_Y.y)  positionCircle.x-- && positionCircle_B.x--;

            if (positionCircle_Y.x < countSoccetsWidth);
            if (positionCircle.x == positionCircle_Y.x && positionCircle.y == positionCircle_Y.y&& positionCircle_Y.x < countSoccetsWidth) positionCircle_Y.x++;
            if (positionCircle_Y.x == positionCircle_R.x && positionCircle_Y.y == positionCircle_R.y) positionCircle.x-- && positionCircle_Y.x--;
            if (positionCircle_Y.x == positionCircle_G.x && positionCircle_Y.y == positionCircle_G.y)  positionCircle.x-- && positionCircle_Y.x--;
            if (positionCircle_Y.x == positionCircle_B.x && positionCircle_Y.y == positionCircle_B.y)  positionCircle.x-- && positionCircle_Y.x--;


            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                if (positionCircle.y > 0) positionCircle.y--;

            if (positionCircle_G.y > 0);
            if (positionCircle.y == positionCircle_G.y && positionCircle.x == positionCircle_G.x&& positionCircle_G.y > 0) positionCircle_G.y--;
            if (positionCircle_G.x == positionCircle_R.x && positionCircle_G.y == positionCircle_R.y) positionCircle.y++ && positionCircle_G.y++;
            if (positionCircle_G.x == positionCircle_B.x && positionCircle_G.y == positionCircle_B.y)  positionCircle.y++ && positionCircle_G.y++;
            if (positionCircle_G.x == positionCircle_Y.x && positionCircle_G.y == positionCircle_Y.y)  positionCircle.y++ && positionCircle_G.y++;

            if (positionCircle_R.y > 0);
            if (positionCircle.y == positionCircle_R.y && positionCircle.x == positionCircle_R.x&& positionCircle_R.y > 0) positionCircle_R.y--;
            if (positionCircle_R.x == positionCircle_G.x && positionCircle_R.y == positionCircle_G.y) positionCircle.y++ && positionCircle_R.y++;
            if (positionCircle_R.x == positionCircle_B.x && positionCircle_R.y == positionCircle_B.y)  positionCircle.y++ && positionCircle_R.y++;
            if (positionCircle_R.x == positionCircle_Y.x && positionCircle_R.y == positionCircle_Y.y)  positionCircle.y++ && positionCircle_R.y++;

            if (positionCircle_B.y > 0);
            if (positionCircle.y == positionCircle_B.y && positionCircle.x == positionCircle_B.x&& positionCircle_B.y > 0) positionCircle_B.y--;
            if (positionCircle_B.x == positionCircle_R.x && positionCircle_B.y == positionCircle_R.y) positionCircle.y++ && positionCircle_B.y++;
            if (positionCircle_B.x == positionCircle_G.x && positionCircle_B.y == positionCircle_G.y)  positionCircle.y++ && positionCircle_B.y++;
            if (positionCircle_B.x == positionCircle_Y.x && positionCircle_B.y == positionCircle_Y.y)  positionCircle.y++ && positionCircle_B.y++;

            if (positionCircle_Y.y > 0);
            if (positionCircle.y == positionCircle_Y.y && positionCircle.x == positionCircle_Y.x&& positionCircle_Y.y > 0) positionCircle_Y.y--;
            if (positionCircle_Y.x == positionCircle_R.x && positionCircle_Y.y == positionCircle_R.y) positionCircle.y++ && positionCircle_Y.y++;
            if (positionCircle_Y.x == positionCircle_G.x && positionCircle_Y.y == positionCircle_G.y)  positionCircle.y++ && positionCircle_Y.y++;
            if (positionCircle_Y.x == positionCircle_B.x && positionCircle_Y.y == positionCircle_B.y)  positionCircle.y++ && positionCircle_Y.y++;


            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                if (positionCircle.y < countSoccetsHeight) positionCircle.y++;
            if (positionCircle_G.y < countSoccetsHeight);
            if (positionCircle.y == positionCircle_G.y && positionCircle.x == positionCircle_G.x&& positionCircle_G.y < countSoccetsHeight) positionCircle_G.y++;
            if (positionCircle_G.x == positionCircle_R.x && positionCircle_G.y == positionCircle_R.y) positionCircle.y-- && positionCircle_G.y--;
            if (positionCircle_G.x == positionCircle_B.x && positionCircle_G.y == positionCircle_B.y)  positionCircle.y-- && positionCircle_G.y--;
            if (positionCircle_G.x == positionCircle_Y.x && positionCircle_G.y == positionCircle_Y.y)  positionCircle.y-- && positionCircle_G.y--;

            if (positionCircle_R.y < countSoccetsHeight);
            if (positionCircle.y == positionCircle_R.y && positionCircle.x == positionCircle_R.x&& positionCircle_R.y < countSoccetsHeight) positionCircle_R.y++;
            if (positionCircle_R.x == positionCircle_G.x && positionCircle_R.y == positionCircle_G.y) positionCircle.y-- && positionCircle_R.y--;
            if (positionCircle_R.x == positionCircle_B.x && positionCircle_R.y == positionCircle_B.y)  positionCircle.y-- && positionCircle_R.y--;
            if (positionCircle_R.x == positionCircle_Y.x && positionCircle_R.y == positionCircle_Y.y)  positionCircle.y-- && positionCircle_R.y--;

            if (positionCircle_B.y < countSoccetsHeight);
            if (positionCircle.y == positionCircle_B.y && positionCircle.x == positionCircle_B.x&& positionCircle_B.y < countSoccetsHeight) positionCircle_B.y++;
            if (positionCircle_B.x == positionCircle_R.x && positionCircle_B.y == positionCircle_R.y) positionCircle.y-- && positionCircle_B.y--;
            if (positionCircle_B.x == positionCircle_G.x && positionCircle_B.y == positionCircle_G.y)  positionCircle.y-- && positionCircle_B.y--;
            if (positionCircle_B.x == positionCircle_Y.x && positionCircle_B.y == positionCircle_Y.y)  positionCircle.y-- && positionCircle_B.y--;

            if (positionCircle_Y.y < countSoccetsHeight);
            if (positionCircle.y == positionCircle_Y.y && positionCircle.x == positionCircle_Y.x&& positionCircle_Y.y < countSoccetsHeight) positionCircle_Y.y++;
            if (positionCircle_Y.x == positionCircle_R.x && positionCircle_Y.y == positionCircle_R.y) positionCircle.y-- && positionCircle_Y.y--;
            if (positionCircle_Y.x == positionCircle_G.x && positionCircle_Y.y == positionCircle_G.y)  positionCircle.y-- && positionCircle_Y.y--;
            if (positionCircle_Y.x == positionCircle_B.x && positionCircle_Y.y == positionCircle_B.y)  positionCircle.y-- && positionCircle_Y.y--;



            circle.setPosition(positionCircle.x * soccetSize,
                positionCircle.y * soccetSize);

            circle_G.setPosition(positionCircle_G.x * soccetSize,
                positionCircle_G.y * soccetSize);

            circle_R.setPosition(positionCircle_R.x * soccetSize,
                positionCircle_R.y * soccetSize);
            circle_B.setPosition(positionCircle_B.x * soccetSize,
                positionCircle_B.y * soccetSize);
            circle_Y.setPosition(positionCircle_Y.x * soccetSize,
                positionCircle_Y.y * soccetSize);



            if (circle_B.getPosition() == rectangle_B.getPosition())
            {
                text_B.setString(std::to_string(b++));
                
                    
            }
            if (circle_R.getPosition() == rectangle_R.getPosition())
            {
                text_R.setString(std::to_string(r++));
            }
            if (circle_G.getPosition() == rectangle_G.getPosition())
            {
                text_G.setString(std::to_string(g++));
            }
            if (circle_Y.getPosition() == rectangle_Y.getPosition())
            {
                text_Y.setString(std::to_string(y++));
            }

        }



        window.clear(sf::Color::White);
        for (auto el : field) {
            window.draw(el);
        }


       

        window.draw(circle);

        window.draw(circle_Y);
        window.draw(circle_R);

        window.draw(circle_G);
        window.draw(circle_B);

        window.draw(rectangle_R);
        window.draw(rectangle_B);
        window.draw(rectangle_G);
        window.draw(rectangle_Y);

        window.draw(text_R);
        window.draw(text_G);
        window.draw(text_B);
        window.draw(text_Y);
        window.display();

    }

    return 0;
}