#include <iostream>
#include <string>
#include <unistd.h>
//#include <vector>

//#include "termio.hpp"
//#include "platform.hpp"
#include "show.hpp"
#include "ball.hpp"
//#include "bricks.hpp"

#include "globalobjects.hpp"

void Show_Loading()
{
	system("clear");							// Maqrum e amboxj ekran@
	constexpr int x_loading_text = 68;
	constexpr int y_loading_text = 13;
	gotoxy(x_loading_text, y_loading_text);		// cursorr-y texapoxum enq hamapatasxan (x,y) coordinat
	std::cout << "Loading" << std::flush;		// flush-y azatum e buffer-y
	
	constexpr int x_loading_symbol = 43;
	constexpr int y_loading_symbol = 15;
	gotoxy(x_loading_symbol, y_loading_symbol);
	
	constexpr int length_loading = 55;
	for(int i = 0; i < length_loading; i++)
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

void Show_Game_Menu(int green_text_index)
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
	constexpr int star_x_coord = 22;
	int x = star_x_coord;
	int y = 7;
	int lvl = bricks[0];
	bricks_vec.reserve(lvl);
	bricks_vec.push_back(std::make_pair(Bricks(1,x,y),true));
	for(int i = 1; i < lvl; ++i)
	{
		if(i % 5 == 0)
		{
			y += 2;
			x = star_x_coord;
			bricks_vec.push_back(std::make_pair(Bricks(1,x, y),true));
		}
		else	
			bricks_vec.push_back(std::make_pair(Bricks(1,bricks_vec[i - 1].first.get_coord_right_pieces(), y),true));
	}
	
	for(auto & elem : bricks_vec)
	{
		elem.first.print_bricks();
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
	constexpr int data_length = 4;
	data_coords.reserve(data_length);
	x = 119;
	y = 7;
	std::string myStr[data_length] = {"Level :  ", "Lifes :  ", "Bricks :  ", "Score :  "};
	for(int i = 0,j = 0; i < 4; ++i)
	{
		gotoxy(x,y);
		std::cout << myStr[i] << "\033[32;1m" << std::flush;
		if(i == 2)
		{
			std::cout << bricks[lvl_lifes_score[0] - 1] << std::flush;
		}
		else
		{
			std::cout << lvl_lifes_score[j] << std::flush;
			++j;
		}
		data_coords.push_back(std::make_pair(x + myStr[i].length(),y));
		y += 6;
		std::cout << "\033[0m" << std::flush;
	}
	
	Show_ALL_Bricks();
}

std::pair<bool,Bricks> is_collision()
{
	for(int i = 0; i < bricks_vec.size(); ++i)
	{
		if(bricks_vec[i].second && ball.is_collide(bricks_vec[i].first))
		{
			bricks_vec[i].second = false;
			return std::make_pair(true,bricks_vec[i].first);
		}
	}
	return std::make_pair(false,Bricks(1,1,1));
}

void remove_this_bricks(const Bricks& remove_bricks)
{
	gotoxy(remove_bricks.get_coord_left_pieces(),remove_bricks.get_y_coord());
	std::cout << std::flush;
	for(int i = 0; i < remove_bricks.len(); ++i)
	{
		std::cout << " " << std::flush;
	}
}

void Show_Update_Data()
{
	constexpr int bricks_index = 2;
	constexpr int score_index = 3;
	std::pair<int,int> data_bricks_coord = data_coords[bricks_index];
	std::pair<int,int> data_score_coord = data_coords[score_index];
	
	keyb.reset_terminal();
	
	gotoxy(data_bricks_coord.first,data_bricks_coord.second);
	std::cout << "\033[32;1m" << bricks[0] << " \033[0m" << std::flush;
	gotoxy(data_score_coord.first,data_score_coord.second);
	std::cout << "\033[32;1m" << lvl_lifes_score[2] << " \033[0m" << std::flush;
}

void Update_Data()
{
	lvl_lifes_score[2] += 10;
	--bricks[0];
	Show_Update_Data();
	if(bricks[0] == 0)
	{
		GameOver = true;
		system("clear");
		std::cout << "!!! YOU WINS !!!" << std::flush;
	}
}

void Show_Ball_Coord()
{
	ball.Print();
	ball.Modify_Ball_Coord();
	std::pair<bool,Bricks> event = is_collision();
	if(event.first)
	{
		remove_this_bricks(event.second);
		ball.Inverse_Move();
		Update_Data();
	}
}

int isLevel_speed = 8;

void Show_Platform_Coord()
{
	for(int i = 0; i < isLevel_speed; ++i)
	{
		plform.print();
		plform.change_coord();
	}
	
}

