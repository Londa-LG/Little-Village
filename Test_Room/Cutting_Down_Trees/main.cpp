#include <SFML/Graphics.hpp>
#include "Items.h"
#include "Player.h"
#include "AssetManager.h"
 
int main()
{
    sf::RenderWindow window(sf::VideoMode(800,600), "Player");
    window.setFramerateLimit(60);

    Tree tree;
    TreeGenerator trg;
    tree = trg.generate_tree(tree,sf::Vector2f(300,300),sf::Vector2f(16,16));

    AssetManager am = AssetManager();

    Player player = Player(am);

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
              if(event.key.code == sf::Keyboard::Escape)
              {
                window.close();
              }
              if(event.key.code == sf::Keyboard::A)
              {
                player.movement.moving_left = true;
              }
              if(event.key.code == sf::Keyboard::D)
              {
                player.movement.moving_right = true;
              }
              if(event.key.code == sf::Keyboard::W)
              {
                player.movement.moving_up = true;
              }
              if(event.key.code == sf::Keyboard::S)
              {
                player.movement.moving_down = true;
              }
            }
            if(event.type == sf::Event::KeyReleased)
            {
              if(event.key.code == sf::Keyboard::A)
              {
                player.movement.moving_left = false;
              }
              if(event.key.code == sf::Keyboard::D)
              {
                player.movement.moving_right = false;
              }
              if(event.key.code == sf::Keyboard::W)
              {
                player.movement.moving_up = false;
              }
              if(event.key.code == sf::Keyboard::S)
              {
                player.movement.moving_down = false;
              }
            }
        }

        player.sMovement();

        if(collision_detection_player(player,tree.bounds))
        {
          handle_collision_player_box(player,tree.bounds);
        }

        window.clear(sf::Color::White);
        player.draw(window);
        window.draw(tree.bounds.sprite);
        window.display();
    }

    return EXIT_SUCCESS;
}
