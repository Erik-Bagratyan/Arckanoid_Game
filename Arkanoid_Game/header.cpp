#include <iostream>

#include "header.hpp"
#include <fstream>

int lvl_lifes_score[3] = {1 , 3, 0};
int bricks[3] = {10, 15, 20}; 
bool GameOver = false;

void EndGame()
{
	std::ofstream fout;
	fout.open("Files/Score.txt", std::ios::out | std::ios::app);
	if(!fout.is_open())
	{
		system("clear");
		std::cout << "!!! Error Open the File !!!\n";
		exit(0);
	}
	else
	{
		fout << "|   " << nick << "| \t" << lvl_lifes_score[3] << "\t |\n"; 		
	}
	fout.close();
				
	gotoxy(59,16);
	std::cout << "\033[31;1m!!! END GAME !!!" << std::flush;
	gotoxy(0,0);
}
