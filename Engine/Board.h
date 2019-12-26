#pragma once

#include "Graphics.h"
#include "Location.h"

class Board
{
public:
	Board( Graphics& gfx );
	void DrawCell(const Location& loc, Color c);
	int GetGridWidth() const;
	int GetGridHeight() const;
	bool IsInsideBoard( const Location& loc ) const;
	int getboardLeftCornerX() const;
	int getboardRightCornerY() const;
	void Draw();
private:
	static constexpr int dimension = 20;
	static constexpr int width = 36;
	static constexpr int height = 27;
	static constexpr Location LeftCorner = { 4,3 };
	static constexpr int borderDim = 5;
	const Color c = Colors::Magenta;
	Graphics& gfx;
};