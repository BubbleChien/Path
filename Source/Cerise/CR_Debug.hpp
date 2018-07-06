
#ifndef CR_DEBUG_HPP
#define CR_DEBUG_HPP



#include "./CR_Common.hpp"

#include "./CR_Text.hpp"



namespace CR
{
	#if CR_DEV_BUILD

	class Debug
	{
		CR_PUBLIC

		static Debug instance;

		CR_PRIVATE

		uint64_t m_old_time = 0;
		bool m_time_ok = false;

		uint32_t m_frames = 0;

		Text m_fps_text;
		Text m_ram_text;
		Text m_vram_text;

		CR_PUBLIC

		bool Init();
		void Free();

		void BeginFrame();
		void EndFrame();

		void Render();

		CR_PRIVATE

		void UpdateFPS();
		void UpdateRAM();
		void UpdateVRAM();
	};

	#else

	class Debug
	{
		CR_PUBLIC

		static Debug instance;

		CR_PUBLIC

		inline bool Init() { return true; }
		inline void Free() {}

		inline void BeginFrame() {}
		inline void EndFrame() {}

		inline void Render() {}
	};

	#endif
}



#endif
