#include <SFML/Graphics.hpp>
#include "Dialog.h"
 
int main()
{
    sf::RenderWindow window(sf::VideoMode(800,600), "Dialog");
    window.setFramerateLimit(60);

    DialogBox d_box = DialogBox();
    d_box.load_dialog("line 1\nline 2\nline 3\n");
    d_box.load_dialog("row 1\nrow 2\nrow 3\n");

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
              if(event.key.code == sf::Keyboard::Space)
              {
                d_box.turn_page();
              }
              if(event.key.code == sf::Keyboard::S)
              {
                d_box.show = true;
              }
            }
        }

        d_box.update();

        window.clear(sf::Color::Yellow);
        d_box.draw(window);
        window.display();
    }

    return EXIT_SUCCESS;
}
