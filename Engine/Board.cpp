#include "Board.h"
#include <assert.h>

Board::Board( Graphics& gfx )
	:
	gfx(gfx)
{
}

void Board::DrawCell( const Location& loc, Color c )
{
	assert( loc.x >= 0 );
	assert( loc.x * dimension < Graphics::ScreenWidth);
	assert( loc.y >= 0 );
	assert( loc.y * dimension < Graphics::ScreenHeight );
	gfx.DrawRectDim( loc.x * dimension, loc.y* dimension, dimension - 3, dimension - 3, c );
}

int Board::GetGridWidth() const
{
	return width;
}

int Board::GetGridHeight() const
{
	return height;
}

bool Board::IsInsideBoard( const Location& loc ) const
{
	return loc.x >= LeftCorner.x && loc.x < width &&
		loc.y >= LeftCorner.y && loc.y < height;
}

int Board::getboardLeftCornerX() const
{
	return LeftCorner.x;
}

int Board::getboardRightCornerY() const
{
	return LeftCorner.y;
}

void Board::Draw()
{
	int LeftX = LeftCorner.x * dimension;
	int RightX = width * dimension;
	int TopY = LeftCorner.y * dimension;
	int BottomY = height * dimension;
	for (int x = LeftX ; x < RightX - (dimension - borderDim) ; x++) //top right extension
	{
		gfx.DrawRectDim( x , TopY - borderDim , dimension , borderDim , c );
	}
	for (int y = TopY - borderDim ; y < BottomY - (dimension - borderDim); y++) //bottom left extension (Need top left)
	{
		gfx.DrawRectDim( LeftX - borderDim, y, borderDim, dimension, c );
	}
	for (int x = LeftX - borderDim; x < RightX - (dimension - borderDim) + 1; x++) //bottom right extension
	{
		gfx.DrawRectDim( x, BottomY , dimension, borderDim, c );
	}
	for (int y = TopY - borderDim; y < BottomY - (dimension - borderDim); y++) //bottom right down extension
	{
		gfx.DrawRectDim( RightX, y, borderDim, dimension, c );
	}
}
