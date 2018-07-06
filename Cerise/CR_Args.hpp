
#ifndef CR_ARGS_HPP
#define CR_ARGS_HPP



#include "./CR_Common.hpp"



namespace CR
{
	struct Args
	{
		union
		{
			#include "../Data/Args.hpp"
		};
	};
}



#endif
