
#ifndef CR_TEXTURE_HPP
#define CR_TEXTURE_HPP



#include "./CR_Common.hpp"

#include "./CR_Error.hpp"



namespace CR
{
	class Texture
	{
		CR_PRIVATE

		C2D_SpriteSheet m_tex = nullptr;

		CR_PUBLIC

		bool Load(const char* filename);
		void Free();

		CR_PUBLIC

		inline ~Texture();

		inline void InitSprite(C2D_Sprite& spr, uint32_t idx);
		inline void SwitchSprite(C2D_Sprite& spr, uint32_t idx);
	};



	Texture::~Texture()
	{
		this->Free();
	}



	void Texture::InitSprite(C2D_Sprite& spr, uint32_t idx)
	{
		#if CR_DEV_BUILD

		if(m_tex == nullptr)
		{
			Error::Show("Texture has not been loaded.");
			return;
		}

		#endif

		C2D_SpriteFromSheet(&spr, m_tex, idx);
	}



	void Texture::SwitchSprite(C2D_Sprite& spr, uint32_t idx)
	{
		#if CR_DEV_BUILD

		if(m_tex == nullptr)
		{
			Error::Show("Texture has not been loaded.");
			return;
		}

		#endif

		spr.image = C2D_SpriteSheetGetImage(m_tex, idx);
	}
}



#endif
