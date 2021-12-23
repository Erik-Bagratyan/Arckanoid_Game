#include <iostream>
#include <unistd.h>

#include "globalobjects.hpp"
#include "platform.hpp"

enum PF_MOVE {PF_LEFT = 'a', PF_RIGHT = 'd', PF_EXIT = 27};

Plform :: Plform() : pl_left_x(0), pl_right_x(0), pl_y(28), platform_length(14)  
{
	pform_position.reserve(platform_length);
	for(int i = 0; i < platform_length; ++i)
	{
		pform_position[i] = 60 + i;
	}
}
		
void Plform :: Move_Platform_Left()
{
	if(pform_position[0] - 1 < MAP_BOARDER::LEFT)
		return;
					
	for(int i = platform_length - 1; i > 0; --i)
	{
		pform_position[i] = pform_position[i - 1];
	}
	--pform_position[0];
}
			
void Plform :: Move_Platform_Right()
{
	if(pform_position[platform_length - 1] + 1 > MAP_BOARDER::RIGHT)
		return;
					
	for(int i = 0; i < platform_length - 1; ++i)
	{
		pform_position[i] = pform_position[i + 1];
	}
	++pform_position[platform_length - 1];
}
		
void Plform :: change_coord()
{
	if(keyb.kbhit())
	{
		pl_left_x = pform_position[0];
		pl_right_x = pform_position[platform_length - 1];
		switch(keyb.getch())
		{
			case PF_MOVE::PF_RIGHT : 
			{
				Move_Platform_Right();
				break;
			}
					
			case PF_MOVE::PF_LEFT :
			{
				Move_Platform_Left();
				break;
			}
					
			case PF_MOVE::PF_EXIT :
			{
			 	GameOver = true;
			 	EndGame();
			  	break; 
			}
		}
	}
}

int Plform :: get_length() const
{
	return platform_length;
}
		
void Plform :: print() const
{
	if(pl_left_x != pform_position[0])
	{
		(pl_left_x < pform_position[0]) ? gotoxy(pl_left_x, pl_y) : gotoxy(pl_right_x, pl_y);
		std::cout << " " << std::flush;
		gotoxy(pform_position[0], pl_y);
		std::cout << std::flush;
		for(int i = 0; i < platform_length; ++i)
		{
			std::cout << "\033[32;2m\u2588" << std::flush;
		}
		gotoxy(0,0);
		std::cout << std::flush;
	}
	usleep(15000);
}
		
