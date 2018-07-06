
#ifndef CR_ACTOR_HPP
#define CR_ACTOR_HPP



#include "./CR_Common.hpp"

#include "./CR_Args.hpp"



namespace CR
{
	class Actor
	{
		CR_PRIVATE

		bool m_active = true;

		CR_PUBLIC

		virtual ~Actor() = default;

		virtual void Update() {}
		virtual void Render() {}

		virtual void OnEvent(uint32_t e, const Args& args) {}

		CR_PUBLIC

		void Listen(const char* id);

		CR_PUBLIC

		inline void SetActive(bool active);
		inline bool IsActive() const;
	};



	void Actor::SetActive(bool active)
	{
		m_active = active;
	}



	bool Actor::IsActive() const
	{
		return m_active;
	}
}



#endif
