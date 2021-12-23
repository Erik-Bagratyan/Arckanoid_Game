#include <iostream>

//#include "termio.hpp"
//#include "show.hpp"
#include "gameinp.hpp"
//#include "header.hpp"

int main()
{	
	Show_Loading();
	Show_Game_Name();
	Show_Game_Menu();
	
	while(game_not_started)	{
		Menu_Keypress();
	}
	
	
	Show_Game_Board();
	
	while(!GameOver)
	{
		Show_Platform_Coord();
		Show_Ball_Coord();
	}
	return 0;
}
