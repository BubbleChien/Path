
#include "./CR_Random.hpp"



namespace CR
{
	Random Random::instance;



	bool Random::Init()
	{
		uint64_t time = osGetTime();

		m_engine.seed(static_cast<uint32_t>((time >> 32) ^ time));

		return true;
	}



	void Random::Free()
	{
	}
}
