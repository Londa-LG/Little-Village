#include <SFML/Graphics.hpp>
#include "Settings.h" 

int main()
{
    Settings settings;
    init_settings(settings);

    sf::RenderWindow window(sf::VideoMode(settings.width,settings.height), settings.title);
    window.setFramerateLimit(settings.frame_rate);

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

        window.clear(sf::Color::White);
        window.display();
    }

    return EXIT_SUCCESS;
}
