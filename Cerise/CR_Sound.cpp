
#include "./CR_Sound.hpp"



namespace CR
{
	uint8_t Sound::channel = 0;



	bool Sound::Load(const char* filename)
	{
		this->Free();

		std::ifstream in(filename, std::ios::binary);

		if(in.fail())
		{
			Error::Show("Failed to load sound.", filename);
			return false;
		}

		in.seekg(0, std::ios::end);
		const uint32_t size = static_cast<uint32_t>(in.tellg());
		in.seekg(0, std::ios::beg);

		m_data = static_cast<int8_t*>(linearAlloc(size));

		in.read(CR_IOPTR(m_data), size);

		in.close();

		m_buffer.data_vaddr = m_data;
		m_buffer.nsamples = size;
		m_buffer.looping = false;
		m_buffer.status = NDSP_WBUF_FREE;

		DSP_FlushDataCache(m_data, size);

		return true;
	}



	void Sound::Free()
	{
		if(m_data == nullptr) return;

		if(m_channel != 0)
		{
			ndspChnWaveBufClear(m_channel);

			m_channel = 0;
		}

		linearFree(m_data);

		m_data = nullptr;
	}



	uint8_t Sound::GetChannel()
	{
		++Sound::channel;

		if(Sound::channel >= CR_AUDIO_CHANNELS)
		{
			Sound::channel = 1;
		}

		return Sound::channel;
	}
}
