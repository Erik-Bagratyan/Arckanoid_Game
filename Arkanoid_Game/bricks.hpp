#ifndef _BRICKS_
#define _BRICKS_

#include <vector>

class Bricks
{
public:
		enum bricksColor {
				BLUE = 1,
				YELLOW = 2,
				RED = 3 
		};

		int lvl;
		std::vector<std::pair<int,int>> bricks_pieces;
		bricksColor bricks_color;
		static int bricks_length;
		
public:
		Bricks(int, int, int);
		int len() const;
		void print_bricks() const;
		void bricks_change_of_state();
		int get_coord_right_pieces() const; 
		int get_coord_left_pieces() const;
		int get_y_coord() const;
};

#endif // bricks.hpp

