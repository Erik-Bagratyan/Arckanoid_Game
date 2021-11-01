#include "termio.hpp"
#include <stdio.h>
#include <unistd.h> // read()

// initial_settings um pahum enq terminali default settingsner-y
// sahmanum enq nor settingsner terminali hamar     
keyboard:: keyboard() {
    tcgetattr(0, &initial_settings);
    new_settings = initial_settings;
    new_settings.c_lflag &= ~(ICANON | ECHO | ISIG);
    new_settings.c_cc[VMIN] = 1;
    new_settings.c_cc[VTIME] = 0;
    tcsetattr(0, TCSANOW, &new_settings);
    peek_character = -1;
}

// Obiekti veranalu jamanak het enq galis terminali default settingsnerin    
keyboard:: ~keyboard() {
    tcsetattr(0, TCSANOW, &initial_settings);
}

// het enq galis terminali skzbnakan settingsnerin
void keyboard :: reset_terminal()
{
	tcsetattr(0, TCSANOW, &initial_settings);
}

// sahmanum enq nor settings terminali hamar
void keyboard :: new_settings_terminal()
{
	tcsetattr(0, TCSANOW, &new_settings);
}

// funkcian naxatesvac e haskanalu hamar ardyoq event texi e unecel  
int keyboard:: kbhit() {
    unsigned char ch;
    int nread;
    if (peek_character != -1) return 1;
    new_settings.c_cc[VMIN] = 0;
    tcsetattr(0, TCSANOW, &new_settings);
    nread = read(0,&ch,1);
    new_settings.c_cc[VMIN] = 1;
    tcsetattr(0, TCSANOW, &new_settings);

    if (nread == 1) {
        peek_character = ch;
        return 1;
    }
    return 0;
}

// Funkcian naxatesvac e symbol "brnelu" hamar 
int keyboard:: getch(){
    char ch;

    if (peek_character != -1){
        ch = peek_character;
        peek_character = -1;
    }
    else read(0, &ch, 1);
    return ch;
}

// Funkcian naxatesvac e cursorr-y texapoxelu hamapatasxan (x,y) coordinat
void gotoxy(int x, int y)
{
    printf("%c[%d;%df", 0x1B, y, x);
}

