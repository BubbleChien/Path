
#ifndef CR_GAME_HPP
#define CR_GAME_HPP



#include "./CR_Common.hpp"

#include "./CR_State.hpp"



namespace CR
{
	class Game
	{
		CR_PUBLIC

		static Game instance;

		CR_PRIVATE

		bool m_running = true;

		State* m_state = nullptr;

		CR_PUBLIC

		void Execute();

		CR_PUBLIC

		inline void Quit();

		template<typename T, typename... Args>
		inline void SetState(Args... args);

		CR_PRIVATE

		bool Init();
		void Free();

		void SafeStateSetup();
		void SafeStateResume();
	};



	void Game::Quit()
	{
		m_running = false;
	}



	template<typename T, typename... Args>
	void Game::SetState(Args... args)
	{
		this->SafeStateSetup();

		if(m_state != nullptr)
		{
			m_state->Free();
			delete m_state;
		}

		T* state = new T();

		state->Init(args...);

		m_state = state;

		this->SafeStateResume();
	}
}



#endif
