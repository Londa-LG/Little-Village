#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class DialogBox
{
  public:
    sf::Font font;
    sf::Text text;
    int wait = 0;
    bool show = false;
    int page_index = 0;
    int font_size = 20;
    int page_duration = 140;
    bool turned_page = false;
    sf::RectangleShape outline;
    std::string default_text = "...!\n...!\n...!";

    sf::Vector2f size = {760,100};
    sf::Vector2f position = {20,480};
    sf::Vector2f text_position = {30,490};

    std::vector<std::string> dialog;

    DialogBox();
    void update();
    void turn_page();
    void load_dialog(std::string p_dialog);
    void draw(sf::RenderWindow &window);
};
