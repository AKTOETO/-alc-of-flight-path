#include "stdafx.h"
#include "Canvas.h"

int main()
{
    cout << "created program\n";
    Canvas canv;

	RenderWindow window(VideoMode(WIDTH, HEIGHT), "Calculating flight path");
    cout << "window created\n";
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        // drawing
        window.clear();
        window.draw(canv);
        window.display();
    }

	return 0;
}