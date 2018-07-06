
#include "./GameUI.hpp"



GameUI* GameUI::instance = nullptr;



void GameUI::Init(uint32_t moves, uint32_t lvl)
{
	GameUI::instance = this;

	m_moves_lbl.Init(5);
	m_moves_lbl.Append("MOVES");
	m_moves_lbl.CenterAt(160.0f, 60.0f);
	m_moves_lbl.SetColor(CR::Color::RGB(97, 179, 255));

	m_moves_txt.Init(2);
	m_moves_txt.Append(CR_STR(moves));
	m_moves_txt.CenterAt(160.0f, 90.0f);
	m_moves_txt.SetColor(CR::Color::RGB(255, 199, 49));

	CR::String str;

	str.Append("Level ");
	str.Append(CR_STR(lvl));
	str.Append("/30");

	m_level_txt.Init(str.GetSize());
	m_level_txt.Append(str.GetData());
	m_level_txt.SetSize(0.5f);
	m_level_txt.CenterAt(160.0f, 170.0f);
	m_level_txt.SetColor(CR::Color::RGB(120, 120, 120));

	m_reset_txt.Init(37);
	m_reset_txt.Append("Press X to restart the current level.");
	m_reset_txt.SetSize(0.5f);
	m_reset_txt.CenterAt(160.0f, 200.0f);
	m_reset_txt.SetColor(CR::Color::RGB(120, 120, 120));
}
