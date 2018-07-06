
#include "./CR_Text.hpp"



namespace CR
{
	void Text::Init(uint32_t size)
	{
		this->Free();

		m_buffer = C2D_TextBufNew(size);
	}



	void Text::Free()
	{
		if(m_buffer == nullptr) return;

		C2D_TextBufDelete(m_buffer);

		m_buffer = nullptr;
	}



	void Text::CenterAt(float x, float y)
	{
		float w = 0.0f;

		C2D_TextGetDimensions(&m_text, m_size, m_size, &w, nullptr);

		this->SetPosition(x - Math::Pixel(w * 0.5f), Math::Pixel(y));
	}
}
