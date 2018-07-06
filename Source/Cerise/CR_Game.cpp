
#include "./CR_Game.hpp"

#include "./CR_Assets.hpp"
#include "./CR_Audio.hpp"
#include "./CR_Color.hpp"
#include "./CR_Debug.hpp"
#include "./CR_Error.hpp"
#include "./CR_Event.hpp"
#include "./CR_Graphics.hpp"
#include "./CR_Input.hpp"
#include "./CR_Random.hpp"
#include "./CR_Stage.hpp"

#include "../Main.hpp"



namespace CR
{
	Game Game::instance;



	void Game::Execute()
	{
		if(!this->Init()) return;

		while(aptMainLoop() && m_running)
		{
			Debug::instance.BeginFrame();

			Input::instance.Update();

			m_state->Update();

			Stage::instance.Update();

			Graphics::instance.BeginFrame();

			Graphics::instance.UseTopScreen();
			Stage::instance.RenderTop();

			Graphics::instance.UseBotScreen();
			Stage::instance.RenderBot();

			Time::total += Time::delta;
			Time::sine = Math::Sin(Time::total);
			Time::sinex = Math::Sin(Time::total * CR_SINEX_MUL);

			Debug::instance.EndFrame();
			Debug::instance.Render();

			Graphics::instance.EndFrame();
		}

		this->Free();
	}



	bool Game::Init()
	{
		if(romfsInit() != 0)
		{
			Error::Show("Failed to initialize RomFS.");
			return false;
		}

		if(!Random::instance.Init()) return false;
		if(!Input::instance.Init()) return false;
		if(!Audio::instance.Init()) return false;
		if(!Graphics::instance.Init()) return false;
		if(!Assets::instance.Init()) return false;
		if(!Event::instance.Init()) return false;
		if(!Debug::instance.Init()) return false;

		Main* state = new Main();

		state->Init();

		m_state = state;

		return true;
	}



	void Game::Free()
	{
		if(m_state != nullptr)
		{
			m_state->Free();
			delete m_state;
		}

		Debug::instance.Free();
		Event::instance.Free();
		Assets::instance.Free();
		Graphics::instance.Free();
		Audio::instance.Free();
		Input::instance.Free();
		Random::instance.Free();

		romfsExit();
	}



	void Game::SafeStateSetup()
	{
		Graphics::instance.BeginFrame();

		Graphics::instance.UseTopScreen();

		Graphics::instance.UseBotScreen();

		Graphics::instance.EndFrame();

		Audio::instance.Stop();
		
		Event::instance.Clear();
		Stage::instance.Clear();
		Assets::instance.Clear();
	}



	void Game::SafeStateResume()
	{
		Input::instance.Update();

		m_state->Update();
	}
}
