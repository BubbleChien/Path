
#include "./CR_Audio.hpp"

#include "./CR_Error.hpp"



namespace CR
{
	Audio Audio::instance;



	bool Audio::Init()
	{
		if(ndspInit() != 0) return false;

		ndspSetOutputMode(NDSP_OUTPUT_MONO);
		ndspSetOutputCount(1);

		for(uint32_t i = 0; i < CR_AUDIO_CHANNELS; ++i)
		{
			ndspChnReset(i);
			ndspChnSetInterp(i, NDSP_INTERP_NONE);
			ndspChnSetRate(i, 22050);
			ndspChnSetFormat(i, NDSP_FORMAT_MONO_PCM8);
		}

		return true;
	}



	void Audio::Free()
	{
		this->StopMusic();
		this->Stop();

		ndspExit();
	}



	void Audio::Stop()
	{
		for(uint32_t i = 1; i < CR_AUDIO_CHANNELS; ++i)
		{
			ndspChnWaveBufClear(i);
		}
	}
}
