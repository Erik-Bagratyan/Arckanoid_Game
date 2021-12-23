#ifndef _BALL
#define _BALL


#include <iostream>
#include <unistd.h>
#include <ctime>
#include <vector>

//#include "platform.hpp"
#include "globalobjects.hpp"

constexpr int ball_move_count = 4;
enum Ball_Move {UP_RIGHT, UP_LEFT, DOWN_RIGHT, DOWN_LEFT};
static Ball_Move Move = DOWN_RIGHT;

class Ball
{
	public:
		int x_coord;	//	66
		int y_coord;	//  28
	
		Ball() : x_coord(66), y_coord(27), temp_x(0), temp_y(0)
		{}
		
		int get_x() const
		{
			return x_coord;
		}
	
		void Modify_Ball_Coord()
		{
			temp_x = x_coord;
			temp_y = y_coord;
				
			Modify_Ball_Move();
			
			switch(Move)
			{
				case UP_RIGHT: { 
					--y_coord;
					++x_coord;
					break;
				}
				case UP_LEFT: { 
					--y_coord;
					--x_coord;
					break;
				}
				case DOWN_RIGHT: { 
					++y_coord;
					++x_coord;
					break;
				}
				case DOWN_LEFT: { 
					++y_coord;
					--x_coord;
					break;
				}
			}
		}
			
		bool is_collide(const Bricks& obj)
		{
				int y = y_coord;
				int x = x_coord;
				if(y == obj.bricks_pieces[0].second)
				{
					const int bricks_start_coord_x = obj.bricks_pieces[0].first;
					const int bricks_end_coord_x = obj.bricks_pieces[obj.bricks_pieces.size() - 1].first;
					if(x >= bricks_start_coord_x && x <= bricks_end_coord_x)
						return true;	
				}		
				return false;
		}
			
		void Inverse_Move()
		{
			switch(Move)
			{
				case UP_RIGHT: { 
					Move = DOWN_RIGHT;
					break;
				}
				case UP_LEFT: { 
					Move = DOWN_LEFT;
					break;
				}
				case DOWN_RIGHT: { 
					Move = UP_RIGHT;
					break;
				}
				case DOWN_LEFT: { 
					Move = UP_LEFT;	
					break;
				}
			}
			/*
			srand(time(NULL));
			if(Move > 1)
			{
				Move = static_cast<Ball_Move>(rand() % 2);
			}else{
				Move = static_cast<Ball_Move>(rand() % 2 + 2);
			}*/
			x_coord = temp_x;
			y_coord = temp_y;
			
			Modify_Ball_Coord();
		}
		
		void modify_lifes()
		{
			int x = 128;
			int y = 13;
			gotoxy(x,y);
			std::cout << lvl_lifes_score[1] << std::flush;
			Inverse_Move();
		}
			
		void Print()
		{
			gotoxy(temp_x,temp_y);
			std::cout << std::flush;
			std::cout << " " << std::flush;
			if(y_coord != 29)
			{
				gotoxy(x_coord,y_coord);
				std::cout << "\u26AA" << std::flush;
				gotoxy(0,0);
				std::cout << std::flush;
				//usleep(300000);
				usleep(50000);
			}
			else if(lvl_lifes_score[1] != 0) 
			{
				--lvl_lifes_score[1];
				modify_lifes(); 
			}
			else
			{
				GameOver = true;
				EndGame();
			}
		}
	
	private: 
		int temp_x,temp_y; 
	//	GRANICE
	// 110 -Right
	// 17 - Left
	// 4 - Up
	// 29 - Down
		void Modify_Ball_Move()
		{
			switch(Move)
			{
				case UP_RIGHT: { 
					if(x_coord == MAP_BOARDER::RIGHT - 1)
					{
						if(y_coord == MAP_BOARDER::UP)
							Move = DOWN_LEFT;
						else Move = UP_LEFT;
					}
					else if(y_coord == MAP_BOARDER::UP)
					{
						Move = DOWN_RIGHT;
					}
					break;
				}
				case UP_LEFT: { 
					if(x_coord == MAP_BOARDER::LEFT)
					{
						if(y_coord == MAP_BOARDER::UP)
							Move = DOWN_RIGHT;
						else Move = UP_RIGHT;
					}
					else if(y_coord == MAP_BOARDER::UP)
					{
						Move = DOWN_LEFT;
					}
					break;
				}
				case DOWN_RIGHT: { 
					if(x_coord == MAP_BOARDER::RIGHT - 1)
					{
						// == 29
						if(y_coord == MAP_BOARDER::DOWN - 1)
						{
							if(foo())
							{
								Move = UP_LEFT;		
							}
						}
						else 
							Move = DOWN_LEFT;
					}
					else if(y_coord == MAP_BOARDER:: DOWN - 2)
						{
							if(foo())
							{
								Move = UP_RIGHT;
							}
						}
					break;
				}
				case DOWN_LEFT: { 
					if(x_coord == MAP_BOARDER::LEFT)
					{
						if(y_coord == MAP_BOARDER::DOWN - 1)
						{
							if(foo())
							{
								Move = UP_RIGHT;		
							}
						}
						else Move = DOWN_RIGHT;
					}
					else if(y_coord == MAP_BOARDER::DOWN - 2)
					{
						if(foo())
						{
							Move = UP_LEFT;
						}
					}
					break;
				}
			}
		}
		
		bool foo()
		{
			const int pf_length = plform.get_length();
			for(int i = 0; i < pf_length; ++i)
			{
				if(plform.pform_position[i] == x_coord)
					return true;
			}
			
			return false;
		}
};

static Ball ball;


#endif
