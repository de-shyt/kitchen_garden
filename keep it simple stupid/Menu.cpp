#include "BaseStruct.h"


Menu::Menu(Map *m, Player* pm) :
    Continue("CyrilicOld.ttf", 65, sf::Color::White, "Continue"),
    NewGame("CyrilicOld.ttf", 65, sf::Color::White, "New game"),
    Settings("CyrilicOld.ttf", 65, sf::Color::White, ""
                                                     "Settings"),
    Exit("CyrilicOld.ttf", 65, sf::Color::White, "Exit"),
    Carrot(BaseElem(600, -150, 918, 950, "carrot.png")),

    MapPtr(m), PlayerPtr(pm)
{
    Continue.mText.setPosition(100, 100);
    NewGame.mText.setPosition(100, 220);
    Settings.mText.setPosition(100, 340);
    Exit.mText.setPosition(100, 460);

    Carrot.mSprite.setRotation(15);
    Carrot.mSprite.setScale(1.2f, 1.2f);
}


void Menu::Draw(sf::RenderWindow &window) const
{
    window.draw(Carrot.mSprite);
    window.draw(Continue.mText);
    window.draw(NewGame.mText);
    window.draw(Settings.mText);
    window.draw(Exit.mText);
}


void Menu::ChangeColor(sf::RenderWindow &window)
{
    Continue.mText.setFillColor(sf::Color::White);
    Continue.mText.setOutlineColor(sf::Color::White);

    NewGame.mText.setFillColor(sf::Color::White);
    NewGame.mText.setOutlineColor(sf::Color::White);

    Settings.mText.setFillColor(sf::Color::White);
    Settings.mText.setOutlineColor(sf::Color::White);

    Exit.mText.setFillColor(sf::Color::White);
    Exit.mText.setOutlineColor(sf::Color::White);

    if (Continue.mText.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
    {
        double coord_x = INT_MAX;
        sql << "select x from players where name='abober'", soci::into(coord_x);

        if (coord_x == INT_MAX) {  // => нет сохранённой игры у игрока с именем abober
            return ;
        }

        Continue.mText.setFillColor(sf::Color::Blue);
        Continue.mText.setOutlineColor(sf::Color::Blue);
    }
    else if (NewGame.mText.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
        NewGame.mText.setFillColor(sf::Color::Blue);
        NewGame.mText.setOutlineColor(sf::Color::Blue);
    }
    else if (Settings.mText.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
        Settings.mText.setFillColor(sf::Color::Blue);
        Settings.mText.setOutlineColor(sf::Color::Blue);
    }
    else if (Exit.mText.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
        Exit.mText.setFillColor(sf::Color::Blue);
        Exit.mText.setOutlineColor(sf::Color::Blue);
    }
}


std::string Menu::CheckBoundaries(sf::Vector2i& MousePos)
{
    if (Continue.mText.getGlobalBounds().contains(MousePos.x, MousePos.y))
    {
        double coord_x = INT_MAX, coord_y;
        sql << "select x, y from players where name='abober'", soci::into(coord_x), soci::into(coord_y);

        if (coord_x != INT_MAX)   //  => есть сохранённая игра у игрока с именем abober
        {
            PlayerPtr->x = coord_x;
            PlayerPtr->y = coord_y;

            int LineCounter;
            sql << "select count(*) from objects_on_map", soci::into(LineCounter);

            if (LineCounter > 0 && MapPtr->BoughtItems.empty())
            {
                int id;
                std::string type_id;

                sql << "select * from objects_on_map", soci::into(type_id), soci::into(id), soci::into(coord_x), soci::into(coord_y);

                MapPtr->BoughtItems[type_id].push_back(new BaseElem(coord_x, coord_y, 32, 32, type_id + "32x32.png"));
            }
        }

        return "Map";
    }

    if (NewGame.mText.getGlobalBounds().contains(MousePos.x, MousePos.y))
    {
        MapPtr->BoughtItems.clear();

        soci::transaction tr(sql);

        sql << "delete from players where name = 'abober'";
        sql << "delete from objects_on_map";

        PlayerPtr->x = 950;
        PlayerPtr->y = 500;
        PlayerPtr->mSprite.setTextureRect(sf::IntRect(2 * 64, 0, 64, 96));

        sql << "insert into players values ('abober', 950, 500)";

        tr.commit();

        return "Map";
    }

    if (Exit.mText.getGlobalBounds().contains(MousePos.x, MousePos.y)) {
        return "CloseWindow";
    }
    return "Menu";
}

