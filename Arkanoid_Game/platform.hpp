#ifndef _PLATFORM
#define _PLATFORM

class Plform
{
	public:
	int pform_x_coord[14];
	const int y_coord = 28;
	int temp_x_coord_left, temp_x_coord_right;
		

		Plform();
		
		void Modify_Platform_Coord();
		
		void Print();
		
		private:
			void Move_Platform_Left();
			void Move_Platform_Right();
};


#endif
