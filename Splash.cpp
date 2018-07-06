
#include "./Splash.hpp"

#include "./Game.hpp"
#include "./Image.hpp"

#include "./Textures/Bone.hpp"



void Splash::Init()
{
	CR::Assets::instance.LoadTexture("romfs:/Textures/Bone.ctx", "Bone");

	CR::Assets::instance.LoadSound("romfs:/Audio/Bark.cau", "Bark");

	CR::Stage::instance.AddTop<Image>("Bone", Bone_Bone_idx, 200.0f, 120.0f);

	CR::Assets::instance.GetSound("Bark").Play();
}



void Splash::Update()
{
	m_time += CR::Time::delta;

	if(m_time > 3.0f)
	{
		CR::Game::instance.SetState<Game>(1, false);
	}
}
