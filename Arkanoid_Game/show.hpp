#ifndef _SHOW
#define _SHOW

#include <iostream>
#include <unistd.h>
#include <string>

#include "termio.hpp"
#include "platform.hpp"
#include "ball.hpp"
#include "header.hpp"

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
}

void Show_Ball_Coord()
{
	ball.Print();
	ball.Modify_Ball_Coord();
}

////////////////////////////
//	Level : isLevel_speed //
////////////////////////////

int isLevel_speed = 8;

void Show_Platform_Coord()
{
	for(int i = 0; i < isLevel_speed; ++i)
	{
		plform.Print();
		plform.Modify_Platform_Coord();
	}
	
}

#endif
