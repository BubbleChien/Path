
#ifndef CR_SPRITE_HPP
#define CR_SPRITE_HPP



#include "./CR_Common.hpp"

#include "./CR_Color.hpp"
#include "./CR_Error.hpp"
#include "./CR_Math.hpp"
#include "./CR_Origin.hpp"
#include "./CR_Texture.hpp"
#include "./CR_Vector.hpp"



namespace CR
{
	class Sprite
	{
		CR_PRIVATE

		C2D_Sprite m_spr;
		C2D_ImageTint m_tint;

		bool m_init = false;

		Texture* m_tex = nullptr;

		CR_PUBLIC

		void Init(Texture& tex, uint32_t idx);
		void Init(const char* tex, uint32_t idx);

		void SetOrigin(Origin o);

		CR_PUBLIC

		inline void Switch(uint32_t idx);

		inline void SetPosition(float x, float y);
		inline void SetRotation(float z);
		inline void SetScale(float x, float y);

		inline void Translate(float x, float y);
		inline void Rotate(float z);
		inline void Scale(float x, float y);

		inline void SetAlpha(uint8_t a);

		inline void Render();

		inline void SetX(float x);
		inline void SetY(float y);

		inline float GetX() const;
		inline float GetY() const;

		inline Vector GetPosition() const;

		CR_PRIVATE

		inline bool DevCheck() const;
	};



	void Sprite::Switch(uint32_t idx)
	{
		#if CR_DEV_BUILD

		if(!m_init)
		{
			Error::Show("Sprite has not been initialized.");
			return;
		}

		#endif

		m_tex->SwitchSprite(m_spr, idx);
	}



	void Sprite::SetPosition(float x, float y)
	{
		C2D_SpriteSetPos(&m_spr, Math::Pixel(x), Math::Pixel(y));
	}



	void Sprite::SetRotation(float z)
	{
		C2D_SpriteSetRotationDegrees(&m_spr, z);
	}



	void Sprite::SetScale(float x, float y)
	{
		C2D_SpriteSetScale(&m_spr, x, y);
	}



	void Sprite::Translate(float x, float y)
	{
		C2D_SpriteMove(&m_spr, x, y);
	}



	void Sprite::Rotate(float z)
	{
		C2D_SpriteRotateDegrees(&m_spr, z);
	}



	void Sprite::Scale(float x, float y)
	{
		C2D_SpriteScale(&m_spr, x, y);
	}



	void Sprite::SetAlpha(uint8_t a)
	{
		C2D_PlainImageTint(&m_tint, Color::Alpha(a), 0.0f);
	}



	void Sprite::Render()
	{
		#if CR_DEV_BUILD

		if(!m_init)
		{
			Error::Show("Sprite has not been initialized.");
			return;
		}

		#endif
		
		C2D_DrawSpriteTinted(&m_spr, &m_tint);
	}



	void Sprite::SetX(float x)
	{
		m_spr.params.pos.x = x;
	}



	void Sprite::SetY(float y)
	{
		m_spr.params.pos.y = y;
	}



	float Sprite::GetX() const
	{
		return m_spr.params.pos.x;
	}



	float Sprite::GetY() const
	{
		return m_spr.params.pos.y;
	}



	Vector Sprite::GetPosition() const
	{
		return Vector(m_spr.params.pos.x, m_spr.params.pos.y);
	}
}



#endif
