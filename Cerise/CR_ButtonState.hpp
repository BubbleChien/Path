
#ifndef CR_BUTTON_STATE_HPP
#define CR_BUTTON_STATE_HPP



#include "./CR_Common.hpp"



namespace CR
{
	struct ButtonState
	{
		uint32_t down = 0x0;
		uint32_t held = 0x0;
		uint32_t up = 0x0;
	};
}



#endif
