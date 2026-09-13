#include <SFML/Graphics.hpp>
#include "Conversation.h"
 
int main()
{
    sf::RenderWindow window(sf::VideoMode(800,600), "Window");
    window.setFramerateLimit(60);

    DialogBox db1;
    Conversation c = Conversation(db1);

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
        c.draw(window);
        window.display();
    }

    return EXIT_SUCCESS;
}
