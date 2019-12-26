#include "Snake.h"
#include <assert.h>


void Snake::Segments::InitHead( const Location& in_loc )
{
	loc = in_loc;
	c = Snake::headColor;
}

void Snake::Segments::InitBody( const Color& colors )
{
	c = colors;
}

void Snake::Segments::Draw( Board& brd ) const
{
	brd.DrawCell( loc, c );
}

void Snake::Segments::Follow( Segments& next ) 
{
	loc = next.loc;
}

void Snake::Segments::MoveBy( const Location& delta_loc )
{
	assert( abs( delta_loc.x ) + abs( delta_loc.y ) == 1 );
	loc.Add( delta_loc );
}

 const Location& Snake::Segments::GetLocation() const
{
	return loc;
}

Snake::Snake( const Location& loc )
{
	segments[0].InitHead( loc );
}

void Snake::Draw( Board& brd ) const
{
	for (int i = 0; i < nSegmentsMax; i++)
	{
		segments[i].Draw( brd );
	}
}

void Snake::Grow()
{
	int i = nSegments - 1;
	while (i > 2)
	{
		i -= 3;
	}
	if (nSegments < nSegmentsMax)
	{
		segments[nSegments].InitBody( colors[i] );
		nSegments++;
	}
}

void Snake::MoveBy( const Location& delta_loc )
{
	for (int i = nSegments - 1; i > 0; --i)
	{
		segments[i].Follow( segments[i - 1] );
	}
	segments[0].MoveBy( delta_loc );
}

Location Snake::GetNextHeadLocation( const Location& delta_next ) const
{
	Location l = (segments[0].GetLocation());
	l.Add( delta_next );
	return l;
}

bool Snake::IsInTileExceptEnd( const Location& target ) const
{
	for (int i = 0; i < nSegments - 1; i++)
	{
		if (segments[i].GetLocation() == target)
		{
			return true;
		}
	}
	return false;
}

bool Snake::IsInTile( const Location& target ) const
{
	for (int i = 0; i < nSegments; i++)
	{
		if (segments[i].GetLocation() == target)
		{
			return true;
		}
	}
	return false;
}
