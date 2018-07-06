
#include "./CR_Actor.hpp"

#include "./CR_Event.hpp"



namespace CR
{
	void Actor::Listen(const char* id)
	{
		Event::instance.Listen(id, this);
	}
}
