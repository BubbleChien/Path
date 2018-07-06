
#include "./CR_Event.hpp"

#include "./CR_Error.hpp"



namespace CR
{
	Event Event::instance;



	bool Event::Init()
	{
		return true;
	}



	void Event::Free()
	{
		this->Clear();
	}



	void Event::Listen(const char* id, Actor* actor)
	{
		Array<Actor*>& actors = m_events[id];

		#if CR_DEV_BUILD

		const uint32_t size = actors.GetSize();

		for(uint32_t i = 0; i < size; ++i)
		{
			if(actors[i] == actor)
			{
				Error::Show("Node already listening to event.", id);
				return;
			}
		}

		#endif

		actors.Add(actor);
	}
}
