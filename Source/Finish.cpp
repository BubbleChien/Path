
#include "./Finish.hpp"

#include "./FinishUI.hpp"



void Finish::Init()
{
	CR::Stage::instance.AddTop<FinishUI>();
}



void Finish::Update()
{
	if(CR::Input::instance.IsDown(CR::Button::Start))
	{
		CR::Game::instance.Quit();
	}
}
