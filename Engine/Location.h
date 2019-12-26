#pragma once

class Location
{
public:
	void Add( const Location& delta_loc )
	{
		x += delta_loc.x;
		y += delta_loc.y;
	}
	void Negative( const Location& loc )
	{
		x = loc.x * -1;
		y = loc.y * -1;
	}
	bool operator==( const Location& rhs ) const
	{
		return x == rhs.x && y == rhs.y;
	}
	int x;
	int y;
};