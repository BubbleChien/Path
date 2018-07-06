
#include "./CR_Stage.hpp"



namespace CR
{
	Stage Stage::instance;



	bool Stage::Init()
	{
		return true;
	}



	void Stage::Free()
	{
		this->Clear();
	}
}
