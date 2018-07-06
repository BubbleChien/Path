
#ifndef CRG_LEVEL_HPP
#define CRG_LEVEL_HPP



#include "./Common.hpp"

#include "./Cursor.hpp"
#include "./LevelState.hpp"
#include "./Tile.hpp"
#include "./TileState.hpp"



class Level : public CR::Actor
{
	CR_PRIVATE

	uint32_t m_lvl = 0;

	uint32_t m_size = 0;
	uint32_t m_moves = 0;

	uint32_t m_cx = 0;
	uint32_t m_cy = 0;

	CR::Array<Tile> m_tiles;

	uint32_t m_up = 0;

	LevelState m_state = LevelState::Playing;

	float m_time = 0.0f;

	CR_PUBLIC

	void Init(uint32_t idx);

	void Update();

	void Render();

	CR_PRIVATE

	bool OpenFile(CR::File& in, uint32_t idx);

	void ReadTiles(CR::File& in);

	TileState ToTileState(uint8_t state) const;

	void CheckMotion();
	void UpdateTile();

	void UpdateWon();
	void UpdateLost();

	CR_PRIVATE

	inline Tile& GetTile(uint32_t x, uint32_t y);

	inline bool IsTileWalkable(uint32_t x, uint32_t y) const;
};



Tile& Level::GetTile(uint32_t x, uint32_t y)
{
	return m_tiles[x + y * m_size];
}



bool Level::IsTileWalkable(uint32_t x, uint32_t y) const
{
	return (m_tiles[x + y * m_size].GetState() != TileState::None);
}



#endif
