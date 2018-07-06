
#include "./CR_Debug.hpp"

#include "./CR_Color.hpp"
#include "./CR_String.hpp"



namespace CR
{
	Debug Debug::instance;



	#if CR_DEV_BUILD

	bool Debug::Init()
	{
		m_fps_text.Init(5);
		m_fps_text.SetSize(0.5f);
		m_fps_text.SetPosition(5.0f, 15.0f);
		m_fps_text.Append(CR_FRAME_TEXT);

		m_ram_text.Init(6);
		m_ram_text.SetSize(0.5f);
		m_ram_text.SetPosition(5.0f, 45.0f);
		m_ram_text.SetColor(Color::RGB(255, 255, 0));
		m_ram_text.Append("???");

		m_vram_text.Init(6);
		m_vram_text.SetSize(0.5f);
		m_vram_text.SetPosition(5.0f, 60.0f);
		m_vram_text.SetColor(Color::RGB(0, 255, 255));
		m_vram_text.Append("???");

		return true;
	}



	void Debug::Free()
	{
	}



	void Debug::BeginFrame()
	{
		m_old_time = osGetTime();
	}



	void Debug::EndFrame()
	{
		this->UpdateFPS();

		++m_frames;

		if(m_frames < CR_FRAME_SECOND * 2) return;

		this->UpdateRAM();
		this->UpdateVRAM();

		m_frames = 0;
	}



	void Debug::Render()
	{
		m_fps_text.Render();
		m_ram_text.Render();
		m_vram_text.Render();
	}



	void Debug::UpdateFPS()
	{
		const uint64_t delta = osGetTime() - m_old_time;

		if(delta <= CR_FRAME_TIME)
		{
			if(!m_time_ok)
			{
				m_fps_text.SetColor(Color::RGB(0, 255, 0));
				m_time_ok = true;
			}
		}
		else
		{
			if(m_time_ok)
			{
				m_fps_text.SetColor(Color::RGB(255, 0, 0));
				m_time_ok = false;
			}
		}

		m_old_time += delta;
	}



	void Debug::UpdateRAM()
	{
		const double ram = static_cast<double>(mappableSpaceFree()) / CR_MEGABYTE;

		char buffer[7];

		CR::String::Print(buffer, "%.2lf", ram);

		m_ram_text.Clear();
		m_ram_text.Append(buffer);
	}



	void Debug::UpdateVRAM()
	{
		const double vram = static_cast<double>(vramSpaceFree()) / CR_MEGABYTE;

		char buffer[7];

		CR::String::Print(buffer, "%.2lf", vram);

		m_vram_text.Clear();
		m_vram_text.Append(buffer);
	}

	#endif
}
