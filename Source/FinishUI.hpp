
#ifndef CRG_FINISH_UI_HPP
#define CRG_FINISH_UI_HPP



#include "./Common.hpp"



class FinishUI : public CR::Actor
{
	CR_PRIVATE

	CR::Text m_con_txt;
	CR::Text m_stats_txt;
	CR::Text m_quit_txt;
	CR::Text m_lic_txt;

	CR_PUBLIC

	void Init();

	CR_PUBLIC

	inline void Render();
};



void FinishUI::Render()
{
	m_con_txt.Render();
	m_stats_txt.Render();
	m_quit_txt.Render();
	m_lic_txt.Render();
}



#endif
