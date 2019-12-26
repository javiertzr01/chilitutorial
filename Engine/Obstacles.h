#pragma once
#include "Board.h"
#include <random>
#include "Snake.h"
#include "Goal.h"

class Obstacles
{
public:
	class IndividualObstacle
	{
	public:
		void Draw( Board& brd ) const;
		void ResetSpawnLocation( std::mt19937 rnd, const Snake& snake, const Board& brd, const Goal& goal );
	private:
		Location loc;
		Color c = Colors::LightGray;
	};
public:
	Obstacles( std::mt19937 rnd, const Snake& snake, const Board& brd, const Goal& goal );
	void Draw( Board& brd ) const ;
	void ObstacleIncrement();
	void SpawnObstacle( std::mt19937 rnd, const Snake& snake, const Board& brd, const Goal& goal );
private:
	static constexpr int nObstaclesMax = 100;
	int nObstacles = 1;
	IndividualObstacle obstacles[nObstaclesMax];

};