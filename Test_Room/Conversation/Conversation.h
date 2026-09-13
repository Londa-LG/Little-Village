#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

struct Dialog
{
  int characterId;
  std::vector<std::string> dialog;
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
    std::string default_text = "Default text. Replace me.";
    Dialog player_dialog;
    Dialog character_dialog;
    sf::Vector2f position = { 20,480 };

    Conversation(DialogBox db1);
    void load_player_dialog(Dialog p_dialog);
    void load_character_dialog(Dialog p_dialog);

    void scale_dialog();
    void update_dialog_box();
    void draw(sf::RenderWindow &window);
};
