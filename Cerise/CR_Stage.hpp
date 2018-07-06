
#ifndef CR_STAGE_HPP
#define CR_STAGE_HPP



#include "./CR_Common.hpp"

#include "./CR_Scene.hpp"



namespace CR
{
	class Stage
	{
		CR_PUBLIC

		static Stage instance;

		CR_PRIVATE

		Scene m_top;
		Scene m_bot;

		CR_PUBLIC

		bool Init();
		void Free();

		CR_PUBLIC

		template<typename T, typename... Args>
		inline void AddTop(Args... args);

		template<typename T, typename... Args>
		inline void AddBot(Args... args);

		inline void Update();

		inline void RenderTop();
		inline void RenderBot();

		inline void Clear();
	};



	template<typename T, typename... Args>
	void Stage::AddTop(Args... args)
	{
		m_top.Add<T>(args...);
	}



	template<typename T, typename... Args>
	void Stage::AddBot(Args... args)
	{
		m_bot.Add<T>(args...);
	}



	void Stage::Update()
	{
		m_top.Update();
		m_bot.Update();
	}



	void Stage::RenderTop()
	{
		m_top.Render();
	}



	void Stage::RenderBot()
	{
		m_bot.Render();
	}



	void Stage::Clear()
	{
		m_top.Clear();
		m_bot.Clear();
	}
}



#endif
