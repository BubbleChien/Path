
#include "./Game.hpp"

#include "./Level.hpp"



void Game::Init(uint32_t lvl, bool retry)
{
	if(lvl == 1 && !retry)
	{
		CR::Audio::instance.LoadMusic("romfs:/Audio/Music.cau");
		CR::Audio::instance.SetMusicVolume(0.4f);
		CR::Audio::instance.PlayMusic();
	}

	CR::Assets::instance.LoadTexture("romfs:/Textures/Tile.ctx", "Tile");

	CR::Assets::instance.LoadSound("romfs:/Audio/Move.cau", "Move");
	CR::Assets::instance.LoadSound("romfs:/Audio/Won.cau", "Won");
	CR::Assets::instance.LoadSound("romfs:/Audio/Lost.cau", "Lost");

	CR::Stage::instance.AddTop<Level>(lvl);

	if(retry)
	{
		CR::Assets::instance.LoadSound("romfs:/Audio/Retry.cau", "Retry");
		CR::Assets::instance.GetSound("Retry").Play();
	}
}
