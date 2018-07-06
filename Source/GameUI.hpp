
#ifndef CRG_GAME_UI_HPP
#define CRG_GAME_UI_HPP



#include "./Common.hpp"



class GameUI : public CR::Actor
{
	CR_PUBLIC

	static GameUI* instance;

	CR_PRIVATE

	CR::Text m_moves_lbl;
	CR::Text m_moves_txt;
	CR::Text m_level_txt;
	CR::Text m_reset_txt;

	CR_PUBLIC

	void Init(uint32_t moves, uint32_t lvl);

	CR_PUBLIC

	inline void Render();

	inline void UpdateMoves(uint32_t moves);
};



void GameUI::Render()
{
	m_moves_lbl.Render();
	m_moves_txt.Render();
	m_level_txt.Render();
	m_reset_txt.Render();
}



void GameUI::UpdateMoves(uint32_t moves)
{
	m_moves_txt.Clear();
	m_moves_txt.Append(CR_STR(moves));
	m_moves_txt.CenterAt(160.0f, 90.0f);
}



#endif
