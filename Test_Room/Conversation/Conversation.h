#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

struct Dialog
{
  int characterId;
  std::string dialog;
};

struct DialogBox
{
  sf::Font font;
  sf::Text text;
  sf::RectangleShape outline;
};

class Conversation
{
  public:
    DialogBox d_box;
    int max_char = 46;
    int max_lines = 4;
    int font_size = 20;
    int page_index = 0;
    sf::Vector2f position = { 20,480 };
    std::vector<std::string> character_dialog;
    std::string default_text = "Excuse me! You looked at me, didn't you? Thank you for waiting. We've restored you pokemon to full health We hope to see you again! Bug catcher collin sent out caterpie.";

    Conversation(Dialog d1);
    void load_character_dialog(Dialog p_dialog);
    void remove_space(std::vector<std::string> &list);
    std::string sub_str(std::string text,int start, int end);

    void turn_page();
    void draw(sf::RenderWindow &window);
};
