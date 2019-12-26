/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include "SpriteCodex.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
    brd( gfx ),
    rng(std::random_device()()),
    snek( {5,5} ),
    goal( rng, brd, snek )
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
    if (GameStarted)
    {
        if (!GameOver)
        {
            if (wnd.kbd.KeyIsPressed( VK_UP ))
            {
                CheckInput( { 0, -1 } );
            }
            if (wnd.kbd.KeyIsPressed( VK_DOWN ))
            {
                CheckInput( { 0, 1 } );
            }
            if (wnd.kbd.KeyIsPressed( VK_LEFT ))
            {
                CheckInput( { -1, 0 } );
            }
            if (wnd.kbd.KeyIsPressed( VK_RIGHT ))
            {
                CheckInput( { 1, 0 } );
            }

            snekMoveCounter++;
            UpdateCounter++;
            if (snekMoveCounter >= snekMovePeriod)
            {
                snekMoveCounter = 0;
                const Location next = snek.GetNextHeadLocation( delta_loc );
                if (!brd.IsInsideBoard( next ))
                {
                    GameOver = true;
                }
                else
                {
                    if (snek.IsInTileExceptEnd( next ))
                    {
                        GameOver = true;
                    }
                    const bool eating = next == goal.GetLocation();
                    if (eating)
                    {
                        MoveOpposite = false;
                        snek.Grow();
                        snek.MoveBy( delta_loc );
                        goal.Respawn( rng, brd, snek );
                    }
                    else
                    {
                        snek.MoveBy( delta_loc );
                    }
                }
            }
            if (UpdateCounter >= UpdatePeriod)
            {
                UpdateCounter = 0;
                snekMovePeriod -= 1;
            }
        }
    }
    else
    {
        if (wnd.kbd.KeyIsPressed( VK_RETURN ))
        {
            GameStarted = true;
        }
    }
}

void Game::CheckInput( const Location input_loc )
{
    if (MoveOpposite || !(input_loc == negative_delta_loc))
    {
        delta_loc = input_loc;
        negative_delta_loc.Negative( delta_loc );
    }
}

void Game::ComposeFrame()
{
    snek.Draw( brd );
    goal.Draw( brd );
    brd.Draw();
    if (GameOver)
    {
        SpriteCodex::DrawGameOver( 350, 250, gfx );
    }
    if (!GameStarted)
    {
        SpriteCodex::DrawTitle( 300, 225, gfx );
    }
}