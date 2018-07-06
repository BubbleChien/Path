
#ifndef CRG_SPLASH_HPP
#define CRG_SPLASH_HPP



#include "./Common.hpp"



class Splash : public CR::State
{
	CR_PRIVATE

	float m_time = 0.0f;

	CR_PUBLIC

	void Init();

	void Update();
};



#endif
