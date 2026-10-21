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
    flags.start_menu = false;
    flags.pause_menu = true;
    flags.settings_menu = false;

    AssetManager am = AssetManager();
    StartMenu start = StartMenu(am,settings);
    PauseMenu pause = PauseMenu(am,settings);
    Button btn1 = Button(am,"Test",{410,570},{380,20});


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
            pause.update(event,window,flags);
        }
        


        window.clear(sf::Color::White);
        start.draw(window,flags);
        pause.draw(window,flags);
        btn1.draw(window);
        window.display();
    }

    return EXIT_SUCCESS;
}
