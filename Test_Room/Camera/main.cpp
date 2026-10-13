#include <SFML/Graphics.hpp>
#include "AssetManager.h"
#include "World.h"
#include "Player.h"
 
int main()
{
    sf::RenderWindow window(sf::VideoMode(800,600), "World");
    window.setFramerateLimit(60);

    AssetManager am = AssetManager();
    Layer ground = Layer("test_room_floor.csv");
    Layer objects = Layer("test_room_objects.csv");
    Layer character = Layer("test_room_characters.csv");
    Player player = Player(am);

    // Camera
    sf::View view;
    sf::Vector2f camera_size = {240,280};
    view.reset(sf::FloatRect(0,0,camera_size.x,camera_size.y));
    window.setView(view);

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

        view.setCenter(player.sprite.getPosition().x,player.sprite.getPosition().y);
        window.setView(view);

        window.clear(sf::Color::White);
        ground.draw(am.tiles, window);
        objects.draw(am.tiles, window);
        character.draw(am.characters, window);
        player.draw(window);
        window.display();
    }

    return EXIT_SUCCESS;
}
