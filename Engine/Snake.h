#pragma once

#include "Board.h"

class Snake
{
private:
	class Segments
	{
	public:
		void InitHead( const Location& in_loc );
		void InitBody( const Color& colors );
		void Draw( Board& brd ) const;
		void Follow( Segments& next );
		void MoveBy( const Location& delta_loc );
		const Location& GetLocation() const;
	private:
		Location loc;
		Color c;
	};
public:
	Snake( const Location& loc );
	void Draw( Board& brd ) const;
	void Grow();
	void MoveBy( const Location& delta_loc );
	Location GetNextHeadLocation( const Location& delta_next ) const;
	bool IsInTileExceptEnd( const Location& target ) const;
	bool IsInTile( const Location& target ) const;

private:
	static constexpr Color headColor = Colors::Yellow;
	static constexpr Color bodyColor = Colors::Green;
	static constexpr int nSegmentsMax = 100;
	int nSegments = 1;
	Segments segments[nSegmentsMax];
	static constexpr Color colors[3] = { Colors::Green, Colors::Blue, Colors::Gray };
};