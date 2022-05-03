#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"

enum class ViewType{ Map, Shop, Chat, Menu, CloseWindow };

ViewType CheckCurrentView(BaseStruct& Struct, sf::Vector2i& MousePos) {
    std::string Type = Struct.CheckBoundaries(MousePos);
    if (Type == "Map") return ViewType::Map;
    if (Type == "Shop") return ViewType::Shop;
    if (Type == "Chat") return ViewType::Chat;
    if (Type == "Menu") return ViewType::Menu;
    if (Type == "CloseWindow") return ViewType::CloseWindow;

    std::cout << "Error while getting ViewType from string\n";
    return ViewType::Map;
}


int main() {

    auto CurrentView = ViewType::Menu;

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "POTATO SIMULATOR");


    try
    {
//============================================== Creating Elems ==============================================

        Shop Shop;
        Menu Menu;
        Map Map;
        Chat Chat;

        Player farmer = Player(860, 440, 50, 92, 4, 8, "player.png");

//============================================================================================================

        sf::Clock Clock;
        float CurrentFrame = 0;

        while (window.isOpen())
        {
            float time = Clock.getElapsedTime().asMicroseconds() / 800;
            Clock.restart();

            sf::Vector2i MousePos = sf::Mouse::getPosition(window);

            sf::Event event{};
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }

                if (event.type == sf::Event::KeyPressed)                                                // Keyboard
                {
                    if (event.key.code == sf::Keyboard::Tab)
                    {
                        if (CurrentView == ViewType::Map) {
                            CurrentView = ViewType::Shop;
                        }
                        else if (CurrentView == ViewType::Shop) {
                            CurrentView = ViewType::Map;
                        }
                    }
                    else if (event.key.code == sf::Keyboard::Escape) {
                        if (CurrentView == ViewType::Chat || CurrentView == ViewType::Shop) {
                            CurrentView = ViewType::Map;
                        }
                        else if (CurrentView == ViewType::Map) {
                            CurrentView = ViewType::Menu;
                        }
                        else if (CurrentView == ViewType::Menu) {
                            window.close();
                        }
                    }
                }

                else if (event.type == sf::Event::MouseButtonPressed)                               // Mouse Buttons
                {
                    if (event.mouseButton.button == sf::Mouse::Left)
                    {
                        if (CurrentView == ViewType::Map) {
                            CurrentView = CheckCurrentView(Map, MousePos);
                        }
                        else if (CurrentView == ViewType::Shop) {
                            CurrentView = CheckCurrentView(Shop, MousePos);

                        }
                        else if (CurrentView == ViewType::Chat) {
                            CurrentView = CheckCurrentView(Chat, MousePos);
                        }
                        else if (CurrentView == ViewType::Menu) {
                            CurrentView = CheckCurrentView(Menu, MousePos);
                        }
                    }
                }
            }


            if (CurrentView == ViewType::Map)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                    farmer.GoLeft(CurrentFrame, time);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                    farmer.GoRight(CurrentFrame, time);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                    farmer.GoUp(CurrentFrame, time);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                    farmer.GoDown(CurrentFrame, time);

                farmer.update(time);
            }

            if (CurrentView == ViewType::Menu) {
                Menu.ChangeColor(window);
            }



//============================================== Draw ========================================================


            window.clear(sf::Color(34, 177, 76));


            if (CurrentView == ViewType::Map) {
                Map.Draw(window);
                window.draw(farmer.mSprite);
            }
            else if (CurrentView == ViewType::Shop) {
                Shop.Draw(window);
            }
            else if (CurrentView == ViewType::Chat) {
                Chat.Draw(window);
            }
            else if (CurrentView == ViewType::Menu) {
                Menu.Draw(window);
            }
            else if (CurrentView == ViewType::CloseWindow) {
                window.close();
            }



//============================================= Display ==============================================================


            window.display();
        }
    }
    catch(const std::exception &e)
    {
        std::cout << e.what();
        return 0;
    }
}
