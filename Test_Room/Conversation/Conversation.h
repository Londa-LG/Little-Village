#pragma once

struct Dialog
{
  int characterId;
  std::string dialog;
};

struct DialogBox
{
  std::string text;
  sf::Rectangle outline;
}

class Conversation
{
  public:
    DialogBox d_box;
    std::string default;
    Dialog player_dialog;
    Dialog character_dialog;

    Conversation();
    void load_player_dialog(Dialog p_dialog);
    void load_character_dialog(Dialog p_dialog);

    void scale_dialog();
    void update_dialog_box();
    void draw(RenderWindow &window);
};
