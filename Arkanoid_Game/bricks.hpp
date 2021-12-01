#ifndef _BRICKS_
#define _BRICKS_

#include <vector>

enum bricksColor {BLUE = 1, YELLOW = 2, RED = 3};

class Bricks
{
	private:
		int lvl;
		std::vector<std::pair<int,int>> bricks_pieces;
		bricksColor bricks_color;
		static int bricks_length;
		
	public:
		Bricks(int, int, int);
		void print_bricks() const;
		bool is_collide();
		void bricks_change_of_state();
		int get_coord_right_pieces() const; 	
};

#endif // bricks.hpp
