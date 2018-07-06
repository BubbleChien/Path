
#include "./Main.hpp"

#include "./Game.hpp"
#include "./Splash.hpp"



void Main::Init()
{
	CR::Graphics::instance.SetTopClear(CR::Color::RGB(30, 30, 30));
	CR::Graphics::instance.SetBotClear(CR::Color::RGB(30, 30, 30));
}



void Main::Update()
{
	#if CR_DEV_BUILD

	CR::Game::instance.SetState<Game>(1, false);

	#else

	CR::Game::instance.SetState<Splash>();

	#endif
}
