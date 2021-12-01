#include <iostream>

#include "bricks.hpp"
#include "termio.hpp"
#include "ball.hpp"
#include "header.hpp"

int Bricks :: bricks_length = 15;

Bricks :: Bricks(int lvl, int bricks_coord_x, int bricks_coord_y)
{
	if(lvl < 1 || lvl > 3)
		exit(-1);
	
	this->lvl = lvl;
	bricks_color = bricksColor(lvl);
	bricks_pieces.reserve(bricks_length);
	
	for(int i = 0; i < bricks_length; ++i)
	{
		bricks_pieces.push_back(std::make_pair(bricks_coord_x + i, bricks_coord_y));
	}
}

void Bricks :: print_bricks() const
{
	std::pair<int,int> start_pieces = bricks_pieces[0]; 
	gotoxy(start_pieces.first, start_pieces.second);
	for(int i = 0; i < bricks_length; ++i)
	{
		std::cout << "\033[32;2m\u2588" << std::flush;
	}
}

bool Bricks :: is_collide()
{
	if(ball.y_coord != bricks_pieces[0].second)
		return false;

	const int bricks_start_coord_x = bricks_pieces[0].first;
	const int bricks_end_coord_x = bricks_pieces[bricks_pieces.size() - 1].first;
	if(ball.x_coord < bricks_start_coord_x || ball.x_coord > bricks_end_coord_x)
		return false;
		
	for(const std::pair<int,int>& elem : bricks_pieces)
	{
		if(elem.first == ball.x_coord)
			return true; 
	}
	
	return false;
}

int Bricks :: get_coord_right_pieces() const
{
	return bricks_pieces[bricks_pieces.size() - 1].first + 2;
}

void Bricks :: bricks_change_of_state()
{
	return;
}
