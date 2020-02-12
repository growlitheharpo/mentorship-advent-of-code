#include <SFML/Graphics.hpp>

struct CheckersPiece
{
    int player;
    bool isKing;
};

enum BoardSpaceColor
{
    Black,
    White
};

struct BoardSpace
{
    CheckersPiece* piece = nullptr;
    BoardSpaceColor color;
    sf::RectangleShape shape;
    int x;
    int y;
};

using namespace sf;
enum GameState
{
	START,
	FIRST_PLAYER_TURN,
	SECOND_PLAYER_TURN,
	GAME_OVER
};
int WinMain()
{
    BoardSpace board[8][8];
    CheckersPiece player1Pieces[12];
    //CheckersPiece player2Pieces[12];

    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            if ((i + j) % 2 == 0)
            {
                board[i][j].color = Black;
                board[i][j].shape.setFillColor(Color::Black);
            }
            else
            {
                board[i][j].color = White;
                board[i][j].shape.setFillColor(Color::White);
            }

            board[i][j].x = i;
            board[i][j].x = j;
        }
    }

    // do some stuff to "move" the pieces to the starting positions
    board[0][0].piece = &player1Pieces[0];
    board[0][1].piece = &player1Pieces[1];
    board[0][2].piece = &player1Pieces[2];


	GameState gameState = START;
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
			if (gameState == GAME_OVER)
			{
				if (sfmlEvent.type == Event::MouseButtonPressed)
				{
					if (sfmlEvent.mouseButton.button == Mouse::Left)
					{
						gameState = START;
					}
				}
			}
            // do things with events here! events are things like mouse clicks, key presses, etc.
            // This page can be a bit confusing, but explains everything you'll ever need to know
            // about sfml events: https://www.sfml-dev.org/tutorials/2.5/window-events.php

            // For example:
            if (sfmlEvent.type == Event::KeyPressed)
            {
				if (sfmlEvent.key.code == Keyboard::W || sfmlEvent.key.code == Keyboard::Up)
				{
					playerPosition.y -= 5;
					player.setPosition(playerPosition);
				}
				else if (sfmlEvent.key.code == Keyboard::A || sfmlEvent.key.code == Keyboard::Left)
				{
					playerPosition.x -= 5;
					player.setPosition(playerPosition);
				}
				else if (sfmlEvent.key.code == Keyboard::S || sfmlEvent.key.code == Keyboard::Down)
				{
					playerPosition.y += 5;
					player.setPosition(playerPosition);
				}
				else if (sfmlEvent.key.code == Keyboard::D || sfmlEvent.key.code == Keyboard::Right)
				{
					playerPosition.x += 5;
					player.setPosition(playerPosition);
				}
            }
            else if (sfmlEvent.type == Event::Closed)
            {
                window.close();
            }
        }

        window.clear(Color::Magenta);

        int targetBoardSize = windowHeight;
        int adjustX = (windowWidth - targetBoardSize) / 2;

        int boardSquareSize = targetBoardSize / 8;
        for (int i = 0; i < 8; ++i)
        {
            for (int j = 0; j < 8; ++j)
            {
                board[i][j].shape.setSize(Vector2f(boardSquareSize, boardSquareSize));
                board[i][j].shape.setPosition(Vector2f(i * boardSquareSize + adjustX, j * boardSquareSize));
                window.draw(board[i][j].shape);
            }
        }

        // Draw all your things here, between clear() and display()
        window.draw(player);


        window.display();
    }

    return 0;
}
