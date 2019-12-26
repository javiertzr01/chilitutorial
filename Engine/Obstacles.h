#pragma once
#include "Board.h"
#include <random>
#include "Snake.h"

class Obstacles
{
public:
	void Draw( Board& brd ) const ;
	void Respawn( std::mt19937 rnd, Snake& snake, );
private:
	Location loc;
	Color c = Colors::LightGray;
};