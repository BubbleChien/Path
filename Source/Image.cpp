
#include "./Image.hpp"



void Image::Init(const char* tex, uint32_t idx, float x, float y)
{
	m_sprite.Init(tex, idx);
	m_sprite.SetOrigin(CR::Origin::Center);
	m_sprite.SetPosition(x, y);
}
