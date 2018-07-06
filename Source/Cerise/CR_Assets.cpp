
#include "./CR_Assets.hpp"



namespace CR
{
	Assets Assets::instance;



	bool Assets::Init()
	{
		return true;
	}



	void Assets::Free()
	{
		this->Clear();
	}
}
