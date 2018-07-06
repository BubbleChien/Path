
#include "./CR_Texture.hpp"



namespace CR
{
	bool Texture::Load(const char* filename)
	{
		this->Free();

		m_tex = C2D_SpriteSheetLoad(filename);

		if(m_tex == nullptr)
		{
			Error::Show("Failed to load texture.", filename);
			return false;
		}

		return true;
	}



	void Texture::Free()
	{
		if(m_tex == nullptr) return;

		C2D_SpriteSheetFree(m_tex);

		m_tex = nullptr;
	}
}
