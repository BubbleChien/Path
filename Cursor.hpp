
#ifndef CRG_CURSOR_HPP
#define CRG_CURSOR_HPP



#include "./Common.hpp"

#include "./Flash.hpp"



class Cursor : public CR::Actor
{
	CR_PUBLIC

	static Cursor* instance;

	CR_PRIVATE

	CR::Sprite m_shadow;
	CR::Sprite m_cursor;

	CR::Vector m_start;
	CR::Vector m_target;

	float m_time = 0.0f;

	CR::Sound* m_snd = nullptr;

	CR_PUBLIC

	void Init(float x, float y);

	void Update();

	CR_PUBLIC

	inline void Render();

	inline void Move(float x, float y);

	inline void AddFlash();
};



void Cursor::Render()
{
	m_shadow.Render();
	m_cursor.Render();
}



void Cursor::Move(float x, float y)
{
	m_start.Set(m_target.x, m_target.y);
	m_target.Move(x, y);
	m_time = 0.0f;
	m_snd->Play();
}



void Cursor::AddFlash()
{
	CR::Stage::instance.AddTop<Flash>(m_target.x, m_target.y);
}



#endif
