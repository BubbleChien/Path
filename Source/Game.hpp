
#ifndef CRG_GAME_HPP
#define CRG_GAME_HPP



#include "./Common.hpp"



class Game : public CR::State
{
	CR_PUBLIC

	static Game* instance;

	CR_PUBLIC

	void Init(uint32_t lvl, bool retry);
};



#endif
