
#ifndef CR_GRAPHICS_HPP
#define CR_GRAPHICS_HPP



#include "./CR_Common.hpp"



namespace CR
{
	class Graphics
	{
		CR_PUBLIC

		static Graphics instance;

		CR_PRIVATE

		C3D_RenderTarget* m_top = nullptr;
		C3D_RenderTarget* m_bot = nullptr;

		uint32_t m_top_clear = 0x0;
		uint32_t m_bot_clear = 0x0;

		CR_PUBLIC

		bool Init();
		void Free();

		CR_PUBLIC

		inline void BeginFrame();
		inline void EndFrame();

		inline void UseTopScreen();
		inline void UseBotScreen();

		inline void SetTopClear(uint32_t color);
		inline void SetBotClear(uint32_t color);
	};



	void Graphics::BeginFrame()
	{
		C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
	}



	void Graphics::EndFrame()
	{
		C3D_FrameEnd(0);

		#if CR_SECOND_VBLANK

		gspWaitForVBlank();

		#endif
	}



	void Graphics::UseTopScreen()
	{
		C2D_SceneBegin(m_top);

		if(m_top_clear != 0x0)
		{
			C2D_TargetClear(m_top, m_top_clear);
		}
	}



	void Graphics::UseBotScreen()
	{
		C2D_SceneBegin(m_bot);

		if(m_bot_clear != 0x0)
		{
			C2D_TargetClear(m_bot, m_bot_clear);
		}
	}



	void Graphics::SetTopClear(uint32_t color)
	{
		m_top_clear = color;
	}



	void Graphics::SetBotClear(uint32_t color)
	{
		m_bot_clear = color;
	}
}



#endif
