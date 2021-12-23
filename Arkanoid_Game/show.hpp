#ifndef _SHOW
#define _SHOW
#include "bricks.hpp"	

extern const std::string MENU[5];

void Show_Game_Name();

void Show_ALL_Bricks();

void Show_Loading();

void Show_Game_Menu(int = 0);

void Show_Game_Board();

std::pair<bool,Bricks> is_collision();

void remove_this_bricks(const Bricks& remove_bricks);

void Update_data();

void Show_Update_Data();

void Show_Ball_Coord();

void Show_ALL_Bricks();

void Show_Platform_Coord();

#endif

