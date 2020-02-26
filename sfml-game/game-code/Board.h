#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

struct CheckersPiece
{
	int player;
	bool isKing;
	CircleShape shape;
};

struct BoardSpace
{
	CheckersPiece* piece = nullptr;
	int color; // 0 for white, 1 for red
	RectangleShape shape;
};