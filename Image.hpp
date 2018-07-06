
#ifndef CRG_IMAGE_HPP
#define CRG_IMAGE_HPP



#include "./Common.hpp"



class Image : public CR::Actor
{
	CR_PRIVATE

	CR::Sprite m_sprite;

	CR_PUBLIC

	void Init(const char* tex, uint32_t idx, float x, float y);

	CR_PUBLIC

	inline void Render();
};



void Image::Render()
{
	m_sprite.Render();
}



#endif
