#include <SFML/Graphics.hpp>
#include "Items.h"
#include "Character.h"
 
int main()
{
    sf::RenderWindow window(sf::VideoMode(800,600), "Dialog");
    window.setFramerateLimit(60);

    AssetManager am = AssetManager();
    ItemGenerator ig = ItemGenerator();
    Item axe, b_axe, coin, log;

    log = ig.generate_wood(log,am);
    log.sprite.setPosition(10,100);

    coin = ig.generate_money(coin,am);
    coin.sprite.setPosition(30,100);

    axe = ig.generate_axe(axe,"Simple axe","A basic axe for wood cutting",am);
    axe.sprite.setPosition(50,100);

    b_axe = ig.generate_battle_axe(b_axe,"Worn out battle axe","An old battle axe in need of repair.",am);
    b_axe.sprite.setPosition(70,100);


    Player player = Player(am);
    Character npc = Character(am,84,{200,300},{600,300});

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

        window.clear(sf::Color::White);

        window.draw(log.sprite);
        window.draw(coin.sprite);
        window.draw(axe.sprite);
        window.draw(b_axe.sprite);

        player.draw(window);

        window.display();
    }

    return EXIT_SUCCESS;
}
