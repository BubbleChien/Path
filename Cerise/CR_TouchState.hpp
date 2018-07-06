
#ifndef CR_TOUCH_STATE_HPP
#define CR_TOUCH_STATE_HPP



#include "./CR_Common.hpp"



namespace CR
{
	struct TouchState
	{
		bool down = false;
		bool held = false;
		bool up = false;
	};
}



#endif
