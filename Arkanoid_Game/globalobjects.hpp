#ifndef _HEADER
#define _HEADER
#include <vector>

#include "termio.hpp"
#include "platform.hpp"
#include "bricks.hpp"

enum MAP_BOARDER {LEFT = 17, RIGHT = 112, UP = 4 , DOWN = 29};

extern keyboard keyb;
extern Plform plform;
extern std::string nick;
extern std::vector<std::pair<Bricks,bool>> bricks_vec;

extern std::vector<std::pair<int,int>> data_coords;
extern int lvl_lifes_score[3];
extern int bricks[3]; 
extern bool GameOver;

void EndGame();

#endif
