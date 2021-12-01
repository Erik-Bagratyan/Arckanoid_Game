#ifndef _HEADER
#define _HEADER

#include "termio.hpp"
#include "platform.hpp"

static keyboard keyb;
static Plform plform;
static std::string nick;

extern int lvl_lifes_score[3];
extern int bricks[3]; 
extern bool GameOver;

void EndGame();
#endif
