#include <SFML/Graphics.hpp>
#include "AssetManager.h"
#include "World.h"
 
int main()
{
    sf::RenderWindow window(sf::VideoMode(800,600), "World");
    window.setFramerateLimit(60);

    AssetManager am = AssetManager();
    Layer ground = Layer("test_room_floor.csv");
    Layer objects = Layer("test_room_objects.csv");
    Layer character = Layer("test_room_characters.csv");

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

        window.clear(sf::Color::Yellow);
        ground.draw(am.world_texture,am.tiles, window);
        objects.draw(am.world_texture,am.tiles, window);
        character.draw(am.character_texture,am.characters, window);
        window.display();
    }

    return EXIT_SUCCESS;
}
