#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Collisions.h"
#include "AssetManager.h"
#include <iostream>
 
int main()
{
    sf::RenderWindow window(sf::VideoMode(800,600), "Window");
    window.setFramerateLimit(60);

    BoundingBox b1,b2,b3,b4;
    b1 = generate_bounding_box(sf::Vector2f(100,100),sf::Vector2f(20,20));
    b2 = generate_bounding_box(sf::Vector2f(200,200),sf::Vector2f(100,20));
    b3 = generate_bounding_box(sf::Vector2f(300,300),sf::Vector2f(20,20));
    b4 = generate_bounding_box(sf::Vector2f(400,400),sf::Vector2f(100,200));

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

        player.sMovement();

        if(collision_detection_player(player,b1))
        {
          std::cout << "1 handle collision" << std::endl;
          handle_collison_player_box(player,b1);
        }
        if(collision_detection_player(player,b2))
        {
          std::cout << "2 handle collision" << std::endl;
        }
        if(collision_detection_player(player,b3))
        {
          std::cout << "3 handle collision" << std::endl;
        }
        if(collision_detection_player(player,b4))
        {
          std::cout << "4 handle collision" << std::endl;
        }

        window.clear(sf::Color::White);
        window.draw(b1.sprite);
        window.draw(b2.sprite);
        window.draw(b3.sprite);
        window.draw(b4.sprite);
        player.draw(window);
        window.display();
    }

    return EXIT_SUCCESS;
}
