
#include "./Tile.hpp"

#include "./Textures/Tile.hpp"



Tile::Tile(const CR::Vector& pos, TileState state)
{
	m_state = state;

	m_sprite.Init("Tile", this->GetTexIdx());
	m_sprite.SetOrigin(CR::Origin::Center);
	m_sprite.SetPosition(pos.x, pos.y);
}



uint32_t Tile::GetTexIdx() const
{
	switch(m_state)
	{
		case TileState::None: return Tile_TileNone_idx;
		case TileState::Down: return Tile_TileDown_idx;
		case TileState::Up: return Tile_TileUp_idx;
	}

	return Tile_TileNone_idx;
}
