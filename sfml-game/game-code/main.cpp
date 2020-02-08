#include <SFML/Graphics.hpp>

using namespace sf;

int WinMain()
{
    int windowWidth = 1280;
    int windowHeight = 720;
    int windowStyle = Style::Titlebar | Style::Close | Style::Resize;

    RenderWindow window(VideoMode(windowWidth, windowHeight), "Checkers - Mentorship Project", windowStyle);

    CircleShape player;
    player.setRadius(20.0f);
    player.setFillColor(Color::Yellow);

    // Put the player in the center of the screen (width and height divided by 2)
    // We also have to subtract the radius, because the "position" is actually the
    // top left corner, not the center.
    Vector2f playerPosition;
    playerPosition.x = (windowWidth / 2.0f) - player.getRadius();
    playerPosition.y = (windowHeight / 2.0f) - player.getRadius();

    player.setPosition(playerPosition);

    while (window.isOpen())
    {
        Event sfmlEvent;
        while (window.pollEvent(sfmlEvent))
        {
            // do things with events here! events are things like mouse clicks, key presses, etc.
            // This page can be a bit confusing, but explains everything you'll ever need to know
            // about sfml events: https://www.sfml-dev.org/tutorials/2.5/window-events.php

            // For example:
            if (sfmlEvent.type == Event::KeyPressed)
            {
                // do something here, like checking "sfmlEvent.key.code"
            }
            else if (sfmlEvent.type == Event::Closed)
            {
                window.close();
            }
        }

        window.clear();

        // Draw all your things here, between clear() and display()
        window.draw(player);


        window.display();
    }

    return 0;
}
