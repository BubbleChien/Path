
#include "./FinishUI.hpp"

#include "./Stats.hpp"



void FinishUI::Init()
{
	m_con_txt.Init(16);
	m_con_txt.Append("CONGRATULATIONS!");
	m_con_txt.CenterAt(200.0f, 60.0f);
	m_con_txt.SetColor(CR::Color::RGB(97, 179, 255));

	CR::String str;

	str.Append("You finished with ");
	str.Append(CR_STR(Stats::moves));
	str.Append(" moves and ");
	str.Append(CR_STR(Stats::retries));

	if(Stats::retries == 1)
	{
		str.Append(" retry.");
	}
	else
	{
		str.Append(" retries.");
	}

	m_stats_txt.Init(str.GetSize());
	m_stats_txt.Append(str.GetData());
	m_stats_txt.SetSize(0.5f);
	m_stats_txt.CenterAt(200.0f, 90.0f);
	m_stats_txt.SetColor(CR::Color::RGB(255, 199, 49));

	m_quit_txt.Init(29);
	m_quit_txt.Append("Press START to quit the game.");
	m_quit_txt.SetSize(0.5f);
	m_quit_txt.CenterAt(200.0f, 170.0f);
	m_quit_txt.SetColor(CR::Color::RGB(120, 120, 120));

	m_lic_txt.Init(30);
	m_lic_txt.Append("Music - CC BY 4.0 - PlayOnLoop");
	m_lic_txt.SetSize(0.5f);
	m_lic_txt.CenterAt(200.0f, 200.0f);
	m_lic_txt.SetColor(CR::Color::RGB(120, 120, 120));
}
