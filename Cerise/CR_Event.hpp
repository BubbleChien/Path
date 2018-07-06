
#ifndef CR_EVENT_HPP
#define CR_EVENT_HPP



#include "./CR_Common.hpp"

#include "./CR_Actor.hpp"
#include "./CR_Args.hpp"
#include "./CR_Array.hpp"
#include "./CR_Hash.hpp"
#include "./CR_Map.hpp"



namespace CR
{
	class Event
	{
		CR_PUBLIC

		static Event instance;

		CR_PRIVATE

		Map<Array<Actor*>> m_events;

		Args m_args;

		CR_PUBLIC

		bool Init();
		void Free();

		void Listen(const char* id, Actor* actor);

		CR_PUBLIC

		inline void Clear();

		inline void Send(const char* id);
		inline void Send(const char* id, const Args& args);
	};



	void Event::Clear()
	{
		m_events.Clear();
	}



	void Event::Send(const char* id)
	{
		Array<Actor*>& actors = m_events[id];

		const uint32_t size = actors.GetSize();

		for(uint32_t i = 0; i < size; ++i)
		{
			actors[i]->OnEvent(Hash::String(id), m_args);
		}
	}



	void Event::Send(const char* id, const Args& args)
	{
		Array<Actor*>& actors = m_events[id];

		const uint32_t size = actors.GetSize();

		for(uint32_t i = 0; i < size; ++i)
		{
			actors[i]->OnEvent(Hash::String(id), args);
		}
	}
}



#endif
