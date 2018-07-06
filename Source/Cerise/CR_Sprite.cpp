
#include "./CR_Sprite.hpp"

#include "./CR_Assets.hpp"



namespace CR
{
	void Sprite::Init(Texture& tex, uint32_t idx)
	{
		tex.InitSprite(m_spr, idx);

		m_init = true;

		this->SetAlpha(0xFF);

		m_tex = &tex;
	}



	void Sprite::Init(const char* tex, uint32_t idx)
	{
		this->Init(Assets::instance.GetTexture(tex), idx);
	}



	void Sprite::SetOrigin(Origin o)
	{
		switch(o)
		{
			case Origin::Center:
			{
				C2D_SpriteSetCenter(&m_spr, 0.5f, 0.5f);
			}
			break;
			case Origin::TopLeft:
			{
				C2D_SpriteSetCenter(&m_spr, 0.0f, 0.0f);
			}
			break;
			case Origin::TopRight:
			{
				C2D_SpriteSetCenter(&m_spr, 1.0f, 0.0f);
			}
			break;
			case Origin::BotLeft:
			{
				C2D_SpriteSetCenter(&m_spr, 0.0f, 1.0f);
			}
			break;
			case Origin::BotRight:
			{
				C2D_SpriteSetCenter(&m_spr, 1.0f, 1.0f);
			}
			break;
		}
	}
}
