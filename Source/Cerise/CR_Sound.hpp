
#ifndef CR_SOUND_HPP
#define CR_SOUND_HPP



#include "./CR_Common.hpp"

#include "./CR_Error.hpp"



namespace CR
{
	class Sound
	{
		CR_PRIVATE

		static uint8_t channel;

		CR_PRIVATE

		int8_t* m_data = nullptr;

		ndspWaveBuf m_buffer;

		uint8_t m_channel = 0;

		CR_PUBLIC

		bool Load(const char* filename);
		void Free();

		CR_PUBLIC

		inline ~Sound();

		inline void Play();
		inline void PlayMusic(bool loop);
		inline void Stop();

		inline bool IsPlaying() const;

		CR_PUBLIC

		static uint8_t GetChannel();
	};



	Sound::~Sound()
	{
		this->Free();
	}



	void Sound::Play()
	{
		#if CR_DEV_BUILD

		if(m_data == nullptr)
		{
			Error::Show("Sound has not been loaded.");
			return;
		}

		#endif

		if(this->IsPlaying()) return;

		m_channel = Sound::GetChannel();

		ndspChnWaveBufAdd(m_channel, &m_buffer);
	}



	void Sound::PlayMusic(bool loop)
	{
		#if CR_DEV_BUILD

		if(m_data == nullptr)
		{
			Error::Show("Music has not been loaded.");
			return;
		}

		#endif

		if(this->IsPlaying()) return;

		m_channel = 0;

		ndspChnWaveBufClear(0);

		m_buffer.looping = loop;
		
		ndspChnWaveBufAdd(0, &m_buffer);
	}



	void Sound::Stop()
	{
		if(!this->IsPlaying()) return;

		ndspChnWaveBufClear(m_channel);

		m_buffer.status = NDSP_WBUF_FREE;
	}



	bool Sound::IsPlaying() const
	{
		return (m_buffer.status == NDSP_WBUF_PLAYING);
	}
}



#endif
