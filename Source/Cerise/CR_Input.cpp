
#include "./CR_Input.hpp"

#include "./CR_Game.hpp"
#include "./CR_Math.hpp"



namespace CR
{
	Input Input::instance;



	bool Input::Init()
	{
		return true;
	}



	void Input::Free()
	{
	}



	void Input::Update()
	{
		hidScanInput();

		m_btn.down = hidKeysDown();
		m_btn.held = hidKeysHeld();
		m_btn.up = hidKeysUp();

		this->UpdateStick();
		this->UpdateTouch();

		#if CR_DEV_BUILD

		if(this->IsDown(Button::Select))
		{
			Game::instance.Quit();
		}

		#endif
	}



	void Input::UpdateStick()
	{
		circlePosition stick;

		hidCircleRead(&stick);

		m_stick.x = static_cast<float>(stick.dx) * CR_STICK_RATIO;
		m_stick.y = static_cast<float>(stick.dy) * CR_STICK_RATIO;

		if(Math::Abs(m_stick.x) < CR_STICK_DEADZONE)
		{
			m_stick.x = 0.0f;
		}

		if(Math::Abs(m_stick.y) < CR_STICK_DEADZONE)
		{
			m_stick.y = 0.0f;
		}

		m_stick.x = Math::Clamp(m_stick.x, -1.0f, 1.0f);
		m_stick.y = Math::Clamp(m_stick.y, -1.0f, 1.0f);
	}



	void Input::UpdateTouch()
	{
		touchPosition touch;

		hidTouchRead(&touch);

		m_touch.x = static_cast<float>(touch.px);
		m_touch.y = static_cast<float>(touch.py);

		m_ts.down = false;
		m_ts.up = false;

		if(m_touch.x != 0.0f || m_touch.y != 0.0f)
		{
			if(!m_ts.held)
			{
				m_ts.down = true;
				m_ts.held = true;
			}
		}
		else
		{
			if(m_ts.held)
			{
				m_ts.held = false;
				m_ts.up = true;
			}
		}
	}
}
