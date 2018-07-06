
#ifndef CR_INPUT_HPP
#define CR_INPUT_HPP



#include "./CR_Common.hpp"

#include "./CR_Button.hpp"
#include "./CR_ButtonState.hpp"
#include "./CR_TouchState.hpp"
#include "./CR_Vector.hpp"



namespace CR
{
	class Input
	{
		CR_PUBLIC

		static Input instance;

		CR_PRIVATE

		ButtonState m_btn;

		Vector m_stick;
		Vector m_touch;

		TouchState m_ts;

		CR_PUBLIC

		bool Init();
		void Free();

		void Update();

		CR_PUBLIC

		inline bool IsDown(Button btn) const;
		inline bool IsHeld(Button btn) const;
		inline bool IsUp(Button btn) const;

		inline const Vector& GetStick() const;
		inline const Vector& GetTouch() const;

		inline bool IsTouchDown() const;
		inline bool IsTouchHeld() const;
		inline bool IsTouchUp() const;

		CR_PRIVATE

		void UpdateStick();
		void UpdateTouch();
	};



	bool Input::IsDown(Button btn) const
	{
		return (m_btn.down & CR_ENUM(btn));
	}



	bool Input::IsHeld(Button btn) const
	{
		return (m_btn.held & CR_ENUM(btn));
	}



	bool Input::IsUp(Button btn) const
	{
		return (m_btn.up & CR_ENUM(btn));
	}



	const Vector& Input::GetStick() const
	{
		return m_stick;
	}



	const Vector& Input::GetTouch() const
	{
		return m_touch;
	}



	bool Input::IsTouchDown() const
	{
		return m_ts.down;
	}



	bool Input::IsTouchHeld() const
	{
		return m_ts.held;
	}



	bool Input::IsTouchUp() const
	{
		return m_ts.up;
	}
}



#endif
