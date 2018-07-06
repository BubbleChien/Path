
#include "./Cursor.hpp"

#include "./Textures/Tile.hpp"



Cursor* Cursor::instance = nullptr;



void Cursor::Init(float x, float y)
{
	Cursor::instance = this;

	m_shadow.Init("Tile", Tile_TileShadow_idx);
	m_shadow.SetOrigin(CR::Origin::Center);
	m_shadow.SetPosition(x, y);
	m_shadow.SetAlpha(80);

	m_cursor.Init("Tile", Tile_TileCursor_idx);
	m_cursor.SetOrigin(CR::Origin::Center);
	m_cursor.SetPosition(x, y - 2.0f);

	m_start.Set(x, y);
	m_target.Set(x, y);

	m_snd = &(CR::Assets::instance.GetSound("Move"));
}



void Cursor::Update()
{
	m_shadow.SetPosition(CR::Math::Lerp(m_start.x, m_target.x, m_time), CR::Math::Lerp(m_start.y, m_target.y, m_time));
	m_cursor.SetPosition(m_shadow.GetX(), m_shadow.GetY() - 6.0f + (CR::Time::sinex * 4.0f));

	m_time += CR::Time::delta * 5.0f;
}
