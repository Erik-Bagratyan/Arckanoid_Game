#ifndef _PLATFORM
#define _PLATFORM

#include <vector>

class Plform
{
public:
	Plform();
	void change_coord();
	void print() const;
	int get_length() const;
	std::vector<int> get_pform() const;
		
	std::vector<int> pform_position;	
private:
	int pl_left_x;
	int pl_right_x;
	const int pl_y;
	const int platform_length;
	
	void Move_Platform_Left();
	void Move_Platform_Right();
};


#endif
