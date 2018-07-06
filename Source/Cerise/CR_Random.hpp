
#ifndef CR_RANDOM_HPP
#define CR_RANDOM_HPP



#include "./CR_Common.hpp"



namespace CR
{
	class Random
	{
		CR_PUBLIC

		static Random instance;

		CR_PRIVATE

		std::default_random_engine m_engine;

		CR_PUBLIC

		bool Init();
		void Free();

		CR_PUBLIC

		inline void Seed(uint32_t seed);

		template<typename T>
		inline T GetInt(T min, T max);

		template<typename T>
		inline T GetFloat(T min, T max);
	};



	void Random::Seed(uint32_t seed)
	{
		m_engine.seed(seed);
	}



	template<typename T>
	T Random::GetInt(T min, T max)
	{
		return std::uniform_int_distribution<T>{min, max - 1}(m_engine);
	}



	template<typename T>
	T Random::GetFloat(T min, T max)
	{
		return std::uniform_real_distribution<T>{min, max}(m_engine);
	}
}



#endif
