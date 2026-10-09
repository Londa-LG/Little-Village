#include <SFML/Graphics.hpp>
#include "AssetManager.h"
#include "Inventory.h"
 
int main()
{
    sf::RenderWindow window(sf::VideoMode(800,600), "Inventory");
    window.setFramerateLimit(60);

    AssetManager am = AssetManager();
    ItemGenerator ig = ItemGenerator();

    Inventory inv = Inventory();

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
              if(event.key.code == sf::Keyboard::C)
              {
                Item coin;
                coin = ig.generate_money(coin,am);
                inv.add_item(coin);
              }
              if(event.key.code == sf::Keyboard::L)
              {
                Item log;
                log = ig.generate_wood(log,am);
                inv.add_item(log);
              }
            }
        }

        window.clear(sf::Color::Black);
        inv.draw(window);
        window.display();
    }

    return EXIT_SUCCESS;
}
