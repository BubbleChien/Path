
#ifndef CRG_TILE_HPP
#define CRG_TILE_HPP



#include "./Common.hpp"

#include "./TileState.hpp"



class Tile
{
	CR_PRIVATE

	CR::Sprite m_sprite;

	TileState m_state = TileState::None;

	CR_PUBLIC

	Tile(const CR::Vector& pos, TileState state);

	CR_PUBLIC

	inline void Render();

	inline TileState GetState() const;

	inline void UpdateState(TileState state);

	CR_PRIVATE

	uint32_t GetTexIdx() const;
};



void Tile::Render()
{
	m_sprite.Render();
}



TileState Tile::GetState() const
{
	return m_state;
}



void Tile::UpdateState(TileState state)
{
	m_state = state;
	m_sprite.Switch(this->GetTexIdx());
}



#endif
