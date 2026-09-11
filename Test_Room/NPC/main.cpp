#include <SFML/Graphics.hpp>
#include "AssetManager.h"
#include "Character.h"
 
int main()
{
    sf::RenderWindow window(sf::VideoMode(800,600), "Window");
    window.setFramerateLimit(60);

    AssetManager am = AssetManager();
    Character npc1 = Character(am, 84,{200,300},{600,300});
    Character npc2 = Character(am, 86,{600,500},{200,500});

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
        }

        npc1.sMovement();
        npc1.Walk_to_destination();
        npc2.sMovement();
        npc2.Walk_to_destination();


        window.clear(sf::Color::Yellow);
        npc1.draw(window);
        npc2.draw(window);
        window.display();
    }

    return EXIT_SUCCESS;
}
