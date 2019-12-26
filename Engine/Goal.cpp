#include "Goal.h"

Goal::Goal( std::mt19937& rng, const Board& brd, const Snake& snake )
{
	Respawn( rng, brd, snake );
}

void Goal::Respawn( std::mt19937& rng, const Board& brd, const Snake& snake )
{
	std::uniform_int_distribution<int> xDist( brd.getboardLeftCornerX() , brd.GetGridWidth() - 1 );
	std::uniform_int_distribution<int> yDist( brd.getboardRightCornerY() , brd.GetGridHeight() - 1 );

	Location newLoc;
	do
	{
		newLoc.x = xDist( rng );
		newLoc.y = yDist( rng );
	} while (snake.IsInTile( newLoc ));

	loc = newLoc;
}

void Goal::Draw( Board& brd ) const
{
	brd.DrawCell( loc, c );
}

bool Goal::IsInTile( const Location& target ) const
{
	if (loc == target)
	{
		return true;
	}
	else
	{
		return false;
	}
}

const Location& Goal::GetLocation() const
{
	return loc;
}
