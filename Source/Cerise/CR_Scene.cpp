
#include "./CR_Scene.hpp"



namespace CR
{
	void Scene::Clear()
	{
		const uint32_t size = m_actors.GetSize();

		for(uint32_t i = 0; i < size; ++i)
		{
			delete m_actors[i];
		}

		m_actors.Clear();
	}



	void Scene::Update()
	{
		for(uint32_t i = 0; i < m_actors.GetSize(); ++i)
		{
			m_actors[i]->Update();
		}
	}



	void Scene::Render()
	{
		const uint32_t size = m_actors.GetSize();

		for(uint32_t i = 0; i < size; ++i)
		{
			m_actors[i]->Render();
		}
	}
}
