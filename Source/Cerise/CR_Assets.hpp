
#ifndef CR_ASSETS_HPP
#define CR_ASSETS_HPP



#include "./CR_Common.hpp"

#include "./CR_Map.hpp"
#include "./CR_Sound.hpp"
#include "./CR_Texture.hpp"



namespace CR
{
	class Assets
	{
		CR_PUBLIC

		static Assets instance;

		CR_PRIVATE

		Map<Sound> m_sounds;
		Map<Texture> m_textures;

		CR_PUBLIC

		bool Init();
		void Free();

		CR_PUBLIC

		inline bool LoadSound(const char* filename, const char* id);
		inline bool LoadTexture(const char* filename, const char* id);

		inline Sound& GetSound(const char* id);
		inline Texture& GetTexture(const char* id);

		inline void Clear();
	};



	bool Assets::LoadSound(const char* filename, const char* id)
	{
		return m_sounds[id].Load(filename);
	}



	bool Assets::LoadTexture(const char* filename, const char* id)
	{
		return m_textures[id].Load(filename);
	}



	Sound& Assets::GetSound(const char* id)
	{
		return m_sounds[id];
	}



	Texture& Assets::GetTexture(const char* id)
	{
		return m_textures[id];
	}



	void Assets::Clear()
	{
		m_sounds.Clear();
		m_textures.Clear();
	}
}



#endif
