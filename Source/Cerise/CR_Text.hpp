
#ifndef CR_TEXT_HPP
#define CR_TEXT_HPP



#include "./CR_Common.hpp"

#include "./CR_Error.hpp"
#include "./CR_Math.hpp"
#include "./CR_Vector.hpp"



namespace CR
{
	class Text
	{
		CR_PRIVATE

		C2D_TextBuf m_buffer = nullptr;
		C2D_Text m_text;

		Vector m_pos;

		uint32_t m_color = 0xFFFFFFFF;

		float m_size = 1.0f;

		CR_PUBLIC

		void Init(uint32_t size);
		void Free();

		void CenterAt(float x, float y);

		CR_PUBLIC

		inline ~Text();

		inline void Clear();
		inline void Append(const char* str);

		inline void SetPosition(float x, float y);
		inline void Move(float x, float y);

		inline void SetColor(uint32_t color);
		inline void SetSize(float s);

		inline void Render();
	};



	Text::~Text()
	{
		this->Free();
	}



	void Text::Clear()
	{
		#if CR_DEV_BUILD

		if(m_buffer == nullptr)
		{
			Error::Show("Text has not been initialized.");
			return;
		}

		#endif

		C2D_TextBufClear(m_buffer);
	}



	void Text::Append(const char* str)
	{
		#if CR_DEV_BUILD

		if(m_buffer == nullptr)
		{
			Error::Show("Text has not been initialized.");
			return;
		}

		#endif

		C2D_TextParse(&m_text, m_buffer, str);
	}



	void Text::SetPosition(float x, float y)
	{
		m_pos.Set(Math::Pixel(x), Math::Pixel(y));
	}



	void Text::Move(float x, float y)
	{
		m_pos.Move(x, y);
	}



	void Text::SetColor(uint32_t color)
	{
		m_color = color;
	}



	void Text::SetSize(float s)
	{
		m_size = s;
	}



	void Text::Render()
	{
		#if CR_DEV_BUILD

		if(m_buffer == nullptr)
		{
			Error::Show("Text has not been initialized.");
			return;
		}

		#endif

		C2D_DrawText(&m_text, CR_TEXT_FLAGS, m_pos.x, m_pos.y, 0.5f, m_size, m_size, m_color);
	}
}



#endif
