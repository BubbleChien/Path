
#ifndef CR_BUTTON_HPP
#define CR_BUTTON_HPP



#include "./CR_Common.hpp"



namespace CR
{
	enum class Button : uint32_t
	{
		A = KEY_A,
		B = KEY_B,
		X = KEY_X,
		Y = KEY_Y,
		L = KEY_L,
		R = KEY_R,
		Start = KEY_START,
		Select = KEY_SELECT,
		Left = KEY_LEFT,
		Right = KEY_RIGHT,
		Up = KEY_UP,
		Down = KEY_DOWN,
		PadLeft = KEY_DLEFT,
		PadRight = KEY_DRIGHT,
		PadUp = KEY_DUP,
		PadDown = KEY_DDOWN,
		StickLeft = KEY_CPAD_LEFT,
		StickRight = KEY_CPAD_RIGHT,
		StickUp = KEY_CPAD_UP,
		StickDown = KEY_CPAD_DOWN
	};
}



#endif
