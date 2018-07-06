
#include "./Level.hpp"

#include "./Cursor.hpp"
#include "./Finish.hpp"
#include "./Game.hpp"
#include "./GameUI.hpp"
#include "./Stats.hpp"



void Level::Init(uint32_t idx)
{
	CR::File in;

	if(!this->OpenFile(in, idx)) return;

	in.Read(&m_size, sizeof(uint32_t));
	in.Read(&m_moves, sizeof(uint32_t));

	in.Read(&m_cx, sizeof(uint32_t));
	in.Read(&m_cy, sizeof(uint32_t));

	this->ReadTiles(in);

	in.Close();

	m_lvl = idx;

	CR::Stage::instance.AddBot<GameUI>(m_moves, idx);
}



void Level::Update()
{
	switch(m_state)
	{
		case LevelState::Playing:
		{
			this->CheckMotion();
		}
		break;
		case LevelState::Won:
		{
			this->UpdateWon();
		}
		break;
		case LevelState::Lost:
		{
			this->UpdateLost();
		}
		break;
	}
}



void Level::Render()
{
	const uint32_t size = m_tiles.GetSize();

	for(uint32_t i = 0; i < size; ++i)
	{
		m_tiles[i].Render();
	}
}



bool Level::OpenFile(CR::File& in, uint32_t idx)
{
	CR::String filename;

	filename.Append("romfs:/Data/LV");

	if(idx < 10)
	{
		filename.Append("0");
	}

	filename.Append(CR_STR(idx));
	filename.Append(".dat");

	return in.OpenRead(filename.GetData());
}



void Level::ReadTiles(CR::File& in)
{
	uint8_t state = 0;

	const CR::Vector offset(
		200.0f - (static_cast<float>(m_size * 21) - 20.0f),
		120.0f - (static_cast<float>(m_size * 21) - 20.0f)
	);

	for(uint32_t y = 0; y < m_size; ++y)
	{
		for(uint32_t x = 0; x < m_size; ++x)
		{
			const CR::Vector position(
				offset.x + (static_cast<float>(x) * 42.0f),
				offset.y + (static_cast<float>(y) * 42.0f)
			);

			in.Read(&state, sizeof(uint8_t));

			m_tiles.Add(position, this->ToTileState(state));

			if(this->ToTileState(state) == TileState::Up)
			{
				++m_up;
			}
		}
	}

	CR::Stage::instance.AddTop<Cursor>(
		offset.x + (static_cast<float>(m_cx * 42)),
		offset.y + (static_cast<float>(m_cy * 42))
	);
}



TileState Level::ToTileState(uint8_t state) const
{
	switch(state)
	{
		case 0: return TileState::None;
		case 1: return TileState::Down;
		case 2: return TileState::Up;
	}

	return TileState::None;
}



void Level::CheckMotion()
{
	if(CR::Input::instance.IsDown(CR::Button::Left))
	{
		if(m_cx == 0) return;
		if(!this->IsTileWalkable(m_cx - 1, m_cy)) return;

		--m_cx;

		Cursor::instance->Move(-42.0f, 0.0f);
	}
	else if(CR::Input::instance.IsDown(CR::Button::Right))
	{
		if(m_cx >= m_size - 1) return;
		if(!this->IsTileWalkable(m_cx + 1, m_cy)) return;

		++m_cx;

		Cursor::instance->Move(42.0f, 0.0f);
	}
	else if(CR::Input::instance.IsDown(CR::Button::Up))
	{
		if(m_cy == 0) return;
		if(!this->IsTileWalkable(m_cx, m_cy - 1)) return;

		--m_cy;

		Cursor::instance->Move(0.0f, -42.0f);
	}
	else if(CR::Input::instance.IsDown(CR::Button::Down))
	{
		if(m_cy >= m_size - 1) return;
		if(!this->IsTileWalkable(m_cx, m_cy + 1)) return;

		++m_cy;

		Cursor::instance->Move(0.0f, 42.0f);
	}
	else if(CR::Input::instance.IsDown(CR::Button::X))
	{
		++Stats::retries;
		CR::Game::instance.SetState<Game>(m_lvl, true);
		return;
	}
	else return;

	this->UpdateTile();
}



void Level::UpdateTile()
{
	Tile& tile = m_tiles[m_cx + (m_cy * m_size)];

	if(tile.GetState() == TileState::Up)
	{
		--m_up;
		tile.UpdateState(TileState::Down);
	}
	else
	{
		++m_up;
		tile.UpdateState(TileState::Up);
	}

	--m_moves;

	++Stats::moves;

	GameUI::instance->UpdateMoves(m_moves);

	if(m_up == 0)
	{
		m_state = LevelState::Won;
		Cursor::instance->AddFlash();
		CR::Assets::instance.GetSound("Won").Play();
		return;
	}

	if(m_moves == 0)
	{
		++Stats::retries;
		m_state = LevelState::Lost;
		CR::Assets::instance.GetSound("Lost").Play();
	}
}



void Level::UpdateWon()
{
	m_time += CR::Time::delta;

	if(m_time < 1.5f) return;

	if(m_lvl == 30)
	{
		CR::Game::instance.SetState<Finish>();
		return;
	}

	CR::Game::instance.SetState<Game>(m_lvl + 1, false);
}



void Level::UpdateLost()
{
	m_time += CR::Time::delta;

	if(m_time < 1.0f) return;

	CR::Game::instance.SetState<Game>(m_lvl, true);
}
