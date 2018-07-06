
#ifndef CR_AUDIO_HPP
#define CR_AUDIO_HPP



#include "./CR_Common.hpp"

#include "./CR_Sound.hpp"



namespace CR
{
	class Audio
	{
		CR_PUBLIC

		static Audio instance;

		CR_PRIVATE

		Sound m_music;

		CR_PUBLIC

		bool Init();
		void Free();

		void Stop();

		CR_PUBLIC

		inline bool LoadMusic(const char* filename);

		inline void PlayMusic(bool loop = true);
		inline void StopMusic();

		inline bool IsMusicPlaying() const;

		inline void SetMusicVolume(float vol);
	};



	bool Audio::LoadMusic(const char* filename)
	{
		return m_music.Load(filename);
	}



	void Audio::PlayMusic(bool loop)
	{
		m_music.PlayMusic(loop);
	}



	void Audio::StopMusic()
	{
		m_music.Stop();
	}



	bool Audio::IsMusicPlaying() const
	{
		return m_music.IsPlaying();
	}



	void Audio::SetMusicVolume(float vol)
	{
		float mix[12] = { vol, vol };

		ndspChnSetMix(0, mix);
	}
}



#endif
