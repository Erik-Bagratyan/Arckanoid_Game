#ifndef _GAMEINP_H
#define _GAMEINP_H

#include <fstream>
#include <string>

#include "show.hpp"
#include "termio.hpp"
#include "header.hpp"

bool game_not_started = true;
static int last_index_Menu = 0, first_index_Menu = 0;
static const int x_Text = 64;
static int first_y_Text = 15 , last_y_Text = 15;

void Print_Modify_Menu();
void Menu_KeyPress();
void Open_Menu(int);
void Open_StartGame();
void Open_Score();
void Open_Options();
void Open_About();

void Menu_Keypress()
{	
	if(keyb.kbhit())
	{	
		last_y_Text = first_y_Text;
		last_index_Menu = first_index_Menu;
		switch(keyb.getch())
		{
		
			case 10 :
			{
				Open_Menu(first_index_Menu);
				system("clear");
				Show_Game_Name();
				Show_Game_Menu(first_index_Menu);
				break;
			}
			
			case 'w': 
			{
				first_y_Text -= 2;
				if(first_y_Text < 15) {
					first_y_Text = 23;
					first_index_Menu = 4;
				}else first_index_Menu--;
				break;
			}
			
			case 's' : 
			{
				first_y_Text += 2;
				if(first_y_Text > 23)
				{
					first_y_Text = 15;
					first_index_Menu = 0;
				}else first_index_Menu++;
				break;
			}
		}
		
		if(last_index_Menu != first_index_Menu)
		{
			Print_Modify_Menu();
		}
	}
}

void Open_Menu(int index_Menu)
{
	gotoxy(0,14);
	std::cout << "\033[0J" << std::flush; // Tvyal Coord-ic sksac clear a anum nerqevi hatvac@ amboxjutyamb
	switch(index_Menu)
	{
		case 0 : Open_StartGame(); break;
		case 1 : Open_Score(); break;
		case 2 : Open_Options(); break;
		case 3 : Open_About(); break;
		case 4 : 
		{
			system("clear");
			exit(0);
		}
	}
}

void Open_StartGame()
{
	game_not_started = false;
	keyb.reset_terminal();
	constexpr int nick_size = 10;
	int score = 1900;
	std::string nick;
	std::cout << "\t\t\t\t\t\t\tNickname : " << std::flush;
	std::getline(std::cin,nick);
	keyb.new_settings_terminal();
	if(nick != "")
	{
		nick = nick.substr(0,nick_size);
	}else nick = "Player";
	std::string space_str_nick(12 - nick.size(), ' ');
	nick += space_str_nick;
	
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
		fout << "|   " << nick << "| \t" << score << "\t |\n"; 
		
	}
	fout.close();
}

void Open_Score()
{
	std::ifstream fin;
	fin.open("Files/Score.txt");
	
	if(!fin.is_open())
	{
		system("clear");
		std::cout << "!!! Error Open the File !!!\n" << std::flush;
		exit(0);
	} 
	else 
	{
		int x = 50, y = 15;
		gotoxy(x,y);
		std::string text = "";
		while(!fin.eof())
		{
			text = "";
			getline(fin,text);
			std::cout << text << std::endl << std::flush;
			gotoxy(x, ++y);
		}
		
		fin.close();
		gotoxy(x, ++y);
		std::cout << "\033[31;1mPress Key --> (ESC) <-- To Back Menu\033[0m" << std::flush;
	}
	while(keyb.getch() != 27);
}

void Open_Options()
{
	std::cout << "Open Options" << std::flush;
	while(keyb.getch() != 27);
}

void Open_About()
{
	std::ifstream fin;
	fin.open("Files/About.txt");
	
	if(!fin.is_open())
	{
		system("clear");
		std::cout << "!!! Error Open the File !!!\n" << std::flush;
		exit(0);
	} 
	else 
	{
		int x = 30, y = 15;
		gotoxy(x,y);
		std::string text = "";
		while(!fin.eof())
		{
			text = "";
			getline(fin,text);
			std::cout << text << std::flush;
			gotoxy(x, ++y);
		}
		
		fin.close();
		gotoxy(x + 25, ++y);
		std::cout << "\033[31;1mPress Key --> (ESC) <-- To Back Menu\033[0m" << std::flush;
	}
	while(keyb.getch() != 27);
}

void Print_Modify_Menu()
{
	gotoxy(x_Text - 4,last_y_Text);
	std::cout << " " << std::flush;
	gotoxy(x_Text,last_y_Text);
	std::cout << MENU[last_index_Menu] << std::flush;
			
	gotoxy(x_Text - 4, first_y_Text);
	std::cout << "\u27A4" << std::flush;
	gotoxy(x_Text,first_y_Text);
	std::cout << "\033[32;1m" << MENU[first_index_Menu] << "\033[0m" << std::flush;
			
	gotoxy(x_Text - 4, first_y_Text);
	std::cout << std::flush;
}

#endif