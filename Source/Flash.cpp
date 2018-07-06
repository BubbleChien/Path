
#include "./Flash.hpp"

#include "./Textures/Tile.hpp"



void Flash::Init(float x, float y)
{
	m_spr.Init("Tile", Tile_TileFlash_idx);
	m_spr.SetOrigin(CR::Origin::Center);
	m_spr.SetPosition(x, y);

	m_start = 0.1f;
	m_end = 1.0f;
}



void Flash::Update()
{
	if(m_alpha > 0)
	{
		m_alpha -= 17;
	}

	const float scale = CR::Math::EaseOut(m_start, m_end, m_time);

	m_spr.SetScale(scale, scale);
	m_spr.SetAlpha(m_alpha);

	m_time += CR::Time::delta * 2.0f;
}
