
#ifndef CRG_FLASH_HPP
#define CRG_FLASH_HPP



#include "./Common.hpp"



class Flash : public CR::Actor
{
	CR_PRIVATE

	CR::Sprite m_spr;

	float m_start = 0.0f;
	float m_end = 0.0f;

	uint8_t m_alpha = 0xFF;

	float m_time = 0.0f;

	CR_PUBLIC

	void Init(float x, float y);

	void Update();

	CR_PUBLIC

	inline void Render();
};



void Flash::Render()
{
	m_spr.Render();
}



#endif
