
#ifndef CR_SCENE_HPP
#define CR_SCENE_HPP



#include "./CR_Common.hpp"

#include "./CR_Actor.hpp"
#include "./CR_Array.hpp"



namespace CR
{
	class Scene
	{
		CR_PRIVATE

		Array<Actor*> m_actors;

		CR_PUBLIC

		void Clear();

		void Update();
		void Render();

		CR_PUBLIC

		template<typename T, typename... Args>
		inline void Add(Args... args);
	};



	template<typename T, typename... Args>
	void Scene::Add(Args... args)
	{
		T* actor = new T();

		m_actors.Add(actor);
		
		actor->Init(args...);
	}
}



#endif
