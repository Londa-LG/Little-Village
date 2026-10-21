#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "Helpers.h"
#include "Settings.h" 

int main()
{
    Settings settings;
    init_settings(settings);

    sf::RenderWindow window(sf::VideoMode(settings.width,settings.height), settings.title);
    window.setFramerateLimit(settings.frame_rate);


    StatusFlags flags;
    flags.gameplay = false;
    flags.start_menu = true;
    flags.pause_menu = false;
    flags.settings_menu = false;

    AssetManager am = AssetManager();
    StartMenu start = StartMenu(am,settings);


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
        
            start.update(event,flags);
        }
        


        window.clear(sf::Color::White);
        start.draw(window,flags);
        window.display();
    }

    return EXIT_SUCCESS;
}
