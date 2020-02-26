#include <SFML/Graphics.hpp>
#include "Board.h"

using namespace sf;
enum GameState
{
	START,
	FIRST_PLAYER_TURN,
	SECOND_PLAYER_TURN,
	GAME_OVER
};

BoardSpace board[8][8];
CheckersPiece player1Pieces[12];
CheckersPiece player2Pieces[12];

void SetUpGameBoard()
{

	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if ((i + j) % 2 == 0) // if even, board space is white
			{
				board[i][j].color = 0;
				board[i][j].shape.setFillColor(Color::White);
			}
			else // if odd, board space is red
			{
				board[i][j].color = 1;
				board[i][j].shape.setFillColor(Color::Red);
			}
		}
	}

	board[0][0].piece = &player2Pieces[0];

	for (CheckersPiece& piece : player1Pieces)
	{
		piece.shape.setFillColor(Color::Red);
		piece.player = 0;
	}
	for (CheckersPiece& piece : player2Pieces)
	{
		piece.shape.setFillColor(Color::Black);
		piece.player = 1;
	}
}
int WinMain()
{
	GameState gameState = START;
    int windowWidth = 1280;
    int windowHeight = 720;
    int windowStyle = Style::Titlebar | Style::Close | Style::Resize;

    RenderWindow window(VideoMode(windowWidth, windowHeight), "Checkers - Mentorship Project", windowStyle);

	

    while (window.isOpen())
    {
        Event sfmlEvent;
        while (window.pollEvent(sfmlEvent))
        {
			switch (gameState)
			{
			case START:
				SetUpGameBoard();
				break;
			case FIRST_PLAYER_TURN:
				break;
			case SECOND_PLAYER_TURN:
				break;
			case GAME_OVER:
				gameState = START;
				break;
			default:
				break;
			}
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
            }
            else if (sfmlEvent.type == Event::Closed)
            {
                window.close();
            }
        }

        window.clear();

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

				if (board[i][j].piece != nullptr)
				{
					board[i][j].piece->shape.setPosition(board[i][j].shape.getPosition());
					board[i][j].piece->shape.setRadius(boardSquareSize / 2);
					window.draw(board[i][j].piece->shape);
				}
			}
		}


        window.display();
    }

    return 0;
}
