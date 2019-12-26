#include "Obstacles.h"

void Obstacles::Draw( Board& brd ) const
{
	brd.DrawCell( loc, c );
}

void Obstacles::Respawn( std::mt19937 rnd, Snake& snake, )
{
	std::uniform_int_distribution<int> xDist(  );
}
