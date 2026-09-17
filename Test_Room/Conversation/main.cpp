#include <SFML/Graphics.hpp>
#include "Conversation.h"
 
int main()
{
    sf::RenderWindow window(sf::VideoMode(800,600), "Window");
    window.setFramerateLimit(60);

    DialogBox db1;
    Dialog d1;
    d1.characterId = 1;
    d1.dialog = "Excuse me! You looked at me, didn't you? Thank you for waiting. We've restored you pokemon to full health We hope to see you again! Bug catcher collin sent out caterpie.";
    Conversation c = Conversation(d1);

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
            if(event.type = sf::Event::KeyPressed)
            {
              if(event.key.code == sf::Keyboard::N)
              {
                c.turn_page();
              }
            }
        }

        window.clear(sf::Color::Yellow);
        c.draw(window);
        window.display();
    }

    return EXIT_SUCCESS;
}
