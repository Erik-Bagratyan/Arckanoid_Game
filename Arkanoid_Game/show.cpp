#include <iostream>
#include <string>
#include <unistd.h>
#include <vector>

#include "termio.hpp"
#include "platform.hpp"
#include "ball.hpp"
#include "header.hpp"
#include "bricks.hpp"

void Show_Loading()
{
	system("clear");							// Maqrum e amboxj ekran@
	gotoxy(68,13);								// cursorr-y texapoxum enq hamapatasxan (x,y) coordinat
	std::cout << "Loading" << std::flush;		// flush-y azatum e buffer-y
	gotoxy(43,15);
	for(int i = 0; i < 55; i++)
	{
		std::cout << "\033[32;2m\u2588" << std::flush;	// sahmanum enq text-i guyn-y (32) - kanach guynn e (2) - hast shrift
		if(i < 10) usleep(80000);						
		else if(i < 20) usleep(55000);
		else usleep(37500);
	}
	system("clear");
	std::cout << "\033[0m" << std::flush;				// berum enq skzbnakan vichaki terminal-y (0) - reset
}

void Show_Game_Name()
{
	std::cout << "\t************************************************************************************************************************************\n";
	std::cout << "\t*          *           ***********     **       **            *            ****       **       **********      **    *********     *\n";
	std::cout << "\t*        ** **         **         **   **      **           ** **          ** **      **      **        **     **    **       **   *\n";
	std::cout << "\t*       **   **        **         **   **     **           **   **         **  **     **     **          **    **    **        **  *\n";
	std::cout << "\t*      **     **       ***********     ********           **     **        **   **    **     **          **    **    **        **  *\n";
	std::cout << "\t*     ***********      **  **          **    **          ***********       **    **   **     **          **    **    **        **  *\n";
	std::cout << "\t*    **         **     **    **        **     **        **         **      **     **  **     **          **    **    **        **  *\n";
	std::cout << "\t*   **           **    **      **      **      **      **           **     **      ** **      **        **     **    **       **   *\n";
	std::cout << "\t*  **             **   **        **    **       **    **             **    **       ****       **********      **    *********     *\n";
	std::cout << "\t************************************************************************************************************************************\n";
}

const std::string MENU[5] = {"Start Game", "Score", "Options", "About", "Exit"};

void Show_Game_Menu(int green_text_index = 0)
{
	const int x = 64;
	int start_y_index = 15;
	int y = green_text_index * 2 + 15;
	gotoxy(x - 4, y);
	std:: cout << "\u27A4" << std::flush;
	
	for(int i = 0; i < 5; ++i)
	{
		gotoxy(x, start_y_index);
		if(i == green_text_index)
		{
			std::cout << "\033[32;1m" << MENU[i] << "\033[0m" << std::flush;
		} else std:: cout << MENU[i] << std::flush;
		start_y_index += 2;
	}
	
	gotoxy(x - 4, y);
	std::cout << std::flush;
}

void Show_ALL_Bricks()
{
	int x = 24;
	int y = 7;
	int lvl = bricks[0];
	
	std::vector<Bricks> myVec;
	myVec.reserve(lvl);
	myVec.push_back(Bricks(1,x,y));
	for(int i = 1; i < lvl; ++i)
	{
		if(i % 5 == 0)
		{
			y += 2;
			x = 24;
			myVec.push_back(Bricks(1,x, y));
		}
		else	
			myVec.push_back(Bricks(1,myVec[i - 1].get_coord_right_pieces(), y));
	}
	
	for(auto & elem : myVec)
	{
		elem.print_bricks();
	}
	
}

void Show_Game_Board()
{
	system("clear");
	int x = 15, y = 3;
	gotoxy(x,y);
	for(int i = 0; i < 130; i++)
	{
		std::cout << "\u2588" << std::flush;
	}
	// 98 -Right
	// 16 - Left
	// 3 - Up
	// 30 - Down
	for(int i = 0; i < 27; ++i)
	{
		gotoxy(x,++y);
		std::cout << "\u2588" << std::flush;
		std::cout << "\u2588" << std::flush;
		gotoxy(x + 98,y);
		std::cout << "\u2588" << std::flush;
		std::cout << "\u2588" << std::flush;
		gotoxy(x + 128,y);
		std::cout << "\u2588" << std::flush;
		std::cout << "\u2588" << std::flush;
	}
	std::cout << std::endl;
	gotoxy(x,y);
	for(int i = 0; i < 130; i++)
	{
		std::cout << "\u2588" << std::flush;
	}
	//std::cout << "\033[0m" << std::flush;
	x = 119;
	y = 7;
	std::string myStr[4] = {"Level", "Lifes", "Bricks", "Score"};
	for(int i = 0,j = 0; i < 4; ++i)
	{
		gotoxy(x,y);
		std::cout << myStr[i] << " : \033[32;1m\t" << std::flush;
		if(i == 2)
		{
			std::cout << bricks[lvl_lifes_score[0] - 1] << std::flush;
			y += 6;
			std::cout << "\033[0m" << std::flush;
			continue;
		}
		else
		{
			std::cout << lvl_lifes_score[j] << std::flush;
			++j;
		}
		y += 6;
		std::cout << "\033[0m" << std::flush;
	}
	
	Show_ALL_Bricks();
}

void Show_Ball_Coord()
{
	ball.Print();
	ball.Modify_Ball_Coord();
}

int isLevel_speed = 8;

void Show_Platform_Coord()
{
	for(int i = 0; i < isLevel_speed; ++i)
	{
		plform.Print();
		plform.Modify_Platform_Coord();
	}
	
}

