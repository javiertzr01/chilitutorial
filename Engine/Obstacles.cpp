#include "Obstacles.h"

void Obstacles::IndividualObstacle::Draw( Board& brd ) const
{
	brd.DrawCell( loc, c );
}

void Obstacles::IndividualObstacle::ResetSpawnLocation( std::mt19937 rnd, const Snake& snake, const Board& brd, const Goal& goal )
{
	std::uniform_int_distribution<int> xDist( brd.getboardLeftCornerX(), brd.GetGridWidth() - 2 );
	std::uniform_int_distribution<int> yDist( brd.getboardRightCornerY(), brd.GetGridHeight() - 2 ); 

	Location NewLoc;

	do
	{
		NewLoc.x = xDist( rnd );
		NewLoc.y = yDist( rnd );
	} while (snake.IsInTile( NewLoc ) || goal.IsInTile(NewLoc));

	loc = NewLoc;
}

Obstacles::Obstacles( std::mt19937 rnd, const Snake& snake, const Board& brd, const Goal& goal )
{
	obstacles[0].ResetSpawnLocation(rnd, snake, brd, goal);
}

void Obstacles::Draw( Board& brd ) const
{
	for (int i = 0; i < nObstacles; i++)
	{
		obstacles[i].Draw( brd );
	}
}

void Obstacles::ObstacleIncrement()
{
	nObstacles++;
}

void Obstacles::SpawnObstacle( std::mt19937 rnd, const Snake& snake, const Board& brd, const Goal& goal )
{
	obstacles[nObstacles].ResetSpawnLocation( rnd, snake, brd, goal );
	ObstacleIncrement();
}
