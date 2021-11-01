#ifndef _BALL
#define _BALL

#include <iostream>
#include "platform.hpp"

enum Ball_Move {UP_RIGHT, UP_LEFT, DOWN_RIGHT, DOWN_LEFT};
Ball_Move Move = DOWN_RIGHT;

struct Ball
{
	int x_coord;	//	66
	int y_coord;	//  28
	
	Ball() : x_coord(66), y_coord(27), temp_x(0), temp_y(0) {}
	
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
	
	void Print()
	{
		
		gotoxy(temp_x,temp_y);
		std::cout << " " << std::flush;
		if(y_coord != 29)
		{
			gotoxy(x_coord,y_coord);
			std::cout << "\u26AA" << std::flush;
			gotoxy(0,0);
			std::cout << std::flush;
			usleep(30000);
		}
		else 
		{
			gotoxy(0,0);
			exit(0);
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
					if(x_coord == 111)
					{
						if(y_coord == 4)
							Move = DOWN_LEFT;
						else Move = UP_LEFT;
					}
					else if(y_coord == 4)
					{
						Move = DOWN_RIGHT;
					}
					break;
				}
				case UP_LEFT: { 
					if(x_coord == 17)
					{
						if(y_coord == 4)
							Move = DOWN_RIGHT;
						else Move = UP_RIGHT;
					}
					else if(y_coord == 4)
					{
						Move = DOWN_LEFT;
					}
					break;
				}
				case DOWN_RIGHT: { 
					if(x_coord == 111)
					{
						// == 29
						if(y_coord == 28)
						{
							if(foo())
							{
								Move = UP_LEFT;		
							}
						}
						else 
							Move = DOWN_LEFT;
					}
					else if(y_coord == 27)
						{
							if(foo())
							{
								Move = UP_RIGHT;
							}
						}
					break;
				}
				case DOWN_LEFT: { 
					if(x_coord == 17)
					{
						if(y_coord == 28)
						{
							if(foo())
							{
								Move = UP_RIGHT;		
							}
						}
						else Move = DOWN_RIGHT;
					}
					else if(y_coord == 27)
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
			for(int i = 0; i < 14; ++i)
			{
				if(plform.pform_x_coord[i] == x_coord)
					return true;
			}
			
			return false;
		}
};

Ball ball;

#endif
