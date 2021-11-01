#ifndef _PLATFORM
#define _PLATFORM
#include <iostream>
#include "header.hpp"

struct Plform
{
	int pform_x_coord[14];
	const int y_coord = 28;
	int temp_x_coord_left, temp_x_coord_right;
		
	public:
		Plform()
		{
			for(int i = 0; i < 14; ++i)
			{
				pform_x_coord[i] = 60 + i;
			}
			temp_x_coord_left = temp_x_coord_right = 0;
		}
		
		void Modify_Platform_Coord()
		{
			if(keyb.kbhit())
			{
				temp_x_coord_left = pform_x_coord[0];
				temp_x_coord_right = pform_x_coord[13];
				switch(keyb.getch())
				{
					case 'd': 
					{
						Move_Platform_Right();
						break;
					}
					
					case 'a':
					{
					Move_Platform_Left();
						break;
					}
					
					case 27: exit(0); break; 
				}
			}
		}
		
		void Print()
		{
			if(temp_x_coord_left != pform_x_coord[0])
			{
				(temp_x_coord_left < pform_x_coord[0]) ? gotoxy(temp_x_coord_left,y_coord) : gotoxy(temp_x_coord_right,y_coord);
				std::cout << " " << std::flush;
				gotoxy(pform_x_coord[0],y_coord);
				std::cout << std::flush;
				for(int i = 0; i < 14; ++i)
				{
					std::cout << "\033[32;2m\u2588" << std::flush;
				}
				gotoxy(0,0);
				std::cout << std::flush;
			}
			usleep(15000);
		}
		
		private:
			void Move_Platform_Left()
			{
				if(pform_x_coord[0] - 1 < 17)
					return;
					
				for(int i = 13; i > 0; --i)
				{
					pform_x_coord[i] = pform_x_coord[i - 1];
				}
				--pform_x_coord[0];
			}
			
			void Move_Platform_Right()
			{
				if(pform_x_coord[13] + 1 > 112)
					return;
					
				for(int i = 0; i < 13; ++i)
				{
					pform_x_coord[i] = pform_x_coord[i + 1];
				}
				++pform_x_coord[13];
			}
};

Plform plform;

#endif
