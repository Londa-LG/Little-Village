#include <SFML/Graphics.hpp>
#include "Items.h"
#include "Character.h"
#include <vector>
#include <iostream>

bool collision_detected(Player &player,Item &item)
{
  sf::Vector2f size = sf::Vector2f(16,16);
  sf::Vector2f iposition = item.bounds.getPosition();

  if(((player.transform.position.x + size.x) > iposition.x) && ((player.transform.position.x) < (iposition.x + size.x)))
  {
    std::cout << "x collision" << std::endl;
    if((abs(player.transform.position.y - iposition.y) < size.y) && (abs((player.transform.position.y + size.y) - iposition.y) < size.y))
    {
      return true;
    }
  }
  if(player.transform.position.x > (iposition.x + size.x))
  {
    return false;
  }
  if((player.transform.position.y + size.y) < iposition.y)
  {
    return false;
  }
  if(player.transform.position.y > (iposition.y + size.y))
  {
    return false;
  }

  return false;
}

void item_collection(std::vector<Item> items,Player &player)
{
  for(int i=0;i<items.size();i++)
  {
    if(collision_detected(player,items[i]))
    {
      std::cout << "collision detected" << std::endl;
      items[i].collected = true;
    }
  }
}
 
int main()
{
    sf::RenderWindow window(sf::VideoMode(800,600), "Dialog");
    window.setFramerateLimit(60);

    std::vector<Item> items;

    AssetManager am = AssetManager();
    ItemGenerator ig = ItemGenerator();
    Item axe, b_axe, coin, log;

    log = ig.generate_wood(log,am);
    log.sprite.setPosition(10,100);

    coin = ig.generate_money(coin,am);
    coin.sprite.setPosition(10,500);

    axe = ig.generate_axe(axe,"Simple axe","A basic axe for wood cutting",am);
    axe.sprite.setPosition(750,100);

    b_axe = ig.generate_battle_axe(b_axe,"Worn out battle axe","An old battle axe in need of repair.",am);
    b_axe.sprite.setPosition(750,500);

    items.push_back(log);
    items.push_back(axe);
    items.push_back(coin);
    items.push_back(b_axe);

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
        item_collection(items,player);

        window.clear(sf::Color::White);

        for(int i=0;i<items.size();i++)
        {
          if(!items[i].collected)
          {
            window.draw(items[i].sprite);
          }
        }

        player.draw(window);

        window.display();
    }

    return EXIT_SUCCESS;
}
