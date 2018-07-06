
#ifndef CR_SCREEN_HPP
#define CR_SCREEN_HPP



#include "./CR_Common.hpp"



namespace CR
{
	class State
	{
		CR_PUBLIC

		virtual ~State() = default;

		virtual void Free() {}
		
		virtual void Update() {}
	};
}



#endif
