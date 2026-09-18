#include <SFML/Graphics.hpp>
#include "Dialog.h"
#include "Character.h"
#include "AssetManager.h"
 
int main()
{
    sf::RenderWindow window(sf::VideoMode(800,600), "Dialog");
    window.setFramerateLimit(60);

    AssetManager am = AssetManager();

    Player player = Player(am);
    Character npc = Character(am,84,{200,300},{600,300});

    DialogBox d_box = DialogBox();
    d_box.load_dialog("line 1\nline 2\nline 3\n");
    d_box.load_dialog("row 1\nrow 2\nrow 3\n");

    // Game loop
    while (window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
            if(event.type == sf::Event::KeyPressed)
            {
              if(event.key.code == sf::Keyboard::Space)
              {
                d_box.turn_page();
              }

              if(event.key.code == sf::Keyboard::W)
              {
                player.movement.moving_up = true;
              }
              if(event.key.code == sf::Keyboard::A)
              {
                player.movement.moving_left = true;
              }
              if(event.key.code == sf::Keyboard::S)
              {
                player.movement.moving_down = true;
              }
              if(event.key.code == sf::Keyboard::D)
              {
                player.movement.moving_right = true;
              }
            }
            if(event.type == sf::Event::KeyReleased)
            {
              if(event.key.code == sf::Keyboard::W)
              {
                player.movement.moving_up = false;
              }
              if(event.key.code == sf::Keyboard::A)
              {
                player.movement.moving_left = false;
              }
              if(event.key.code == sf::Keyboard::S)
              {
                player.movement.moving_down = false;
              }
              if(event.key.code == sf::Keyboard::D)
              {
                player.movement.moving_right = false;
              }
            }
        }

        // Start dialog
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
          sf::Vector2f mousePosition = {sf::Mouse::getPosition(window).x / 1.0f, sf::Mouse::getPosition(window).y / 1.0f};
          sf::FloatRect npcBounds = npc.sprite.getGlobalBounds();

          if((mousePosition.x > npcBounds.left) && (mousePosition.x < (npcBounds.left + npcBounds.width)))
          {
            if((mousePosition.y > npcBounds.top) && (mousePosition.y < (npcBounds.top + npcBounds.height)))
            {
              d_box.show = true;
            }
          }
        }

        player.sMovement();
        d_box.update();

        window.clear(sf::Color::White);
        player.draw(window);
        npc.draw(window);
        d_box.draw(window);
        window.display();
    }

    return EXIT_SUCCESS;
}
