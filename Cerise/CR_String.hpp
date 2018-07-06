
#ifndef CR_STRING_HPP
#define CR_STRING_HPP



#include "./CR_Common.hpp"



namespace CR
{
	class String
	{
		CR_PRIVATE

		std::string m_str;

		CR_PUBLIC

		inline void Append(const char* str);

		inline void Clear();

		inline const char* GetData() const;

		inline uint32_t GetSize() const;

		CR_PUBLIC

		template<typename... Args>
		static inline void Print(char* buf, const char* fmt, Args... args);
	};



	void String::Append(const char* str)
	{
		m_str += str;
	}



	void String::Clear()
	{
		m_str.clear();
	}



	const char* String::GetData() const
	{
		return m_str.c_str();
	}



	uint32_t String::GetSize() const
	{
		return m_str.size();
	}



	template<typename... Args>
	void String::Print(char* buf, const char* fmt, Args... args)
	{
		std::sprintf(buf, fmt, args...);
	}
}



#endif
