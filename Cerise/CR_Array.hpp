
#ifndef CR_ARRAY_HPP
#define CR_ARRAY_HPP



#include "./CR_Common.hpp"



namespace CR
{
	template<typename T>
	class Array
	{
		CR_PUBLIC

		static const uint32_t npos;

		CR_PRIVATE

		std::vector<T> m_vec;

		CR_PUBLIC

		inline void Clear();

		template<typename... Args>
		inline void Add(Args... args);

		inline void Remove(uint32_t i);
		inline void RemovePtr(uint32_t i);

		inline uint32_t Find(T o) const;

		inline void Reserve(uint32_t size);
		inline void Resize(uint32_t size);

		inline uint32_t GetSize() const;

		inline T& GetLast();

		inline bool IsEmpty() const;

		inline T& operator[](uint32_t i);
		inline const T& operator[](uint32_t i) const;
	};



	template<typename T>
	const uint32_t Array<T>::npos = 0xFFFFFFFF;



	template<typename T>
	void Array<T>::Clear()
	{
		m_vec.clear();
	}



	template<typename T>
	template<typename... Args>
	void Array<T>::Add(Args... args)
	{
		m_vec.emplace_back(args...);
	}



	template<typename T>
	void Array<T>::Remove(uint32_t i)
	{
		std::swap(m_vec[i], m_vec.back());
		m_vec.pop_back();
	}



	template<typename T>
	void Array<T>::RemovePtr(uint32_t i)
	{
		delete m_vec[i];
		m_vec[i] = m_vec.back();
		m_vec.pop_back();
	}



	template<typename T>
	uint32_t Array<T>::Find(T o) const
	{
		const uint32_t size = m_vec.size();

		for(uint32_t i = 0; i < size; ++i)
		{
			if(m_vec[i] == o) return i;
		}

		return Array<T>::npos;
	}



	template<typename T>
	void Array<T>::Reserve(uint32_t size)
	{
		m_vec.reserve(size);
	}



	template<typename T>
	void Array<T>::Resize(uint32_t size)
	{
		m_vec.resize(size);
	}



	template<typename T>
	uint32_t Array<T>::GetSize() const
	{
		return m_vec.size();
	}

	template<typename T>
	T& Array<T>::GetLast()
	{
		return m_vec.back();
	}



	template<typename T>
	bool Array<T>::IsEmpty() const
	{
		return (m_vec.size() == 0);
	}



	template<typename T>
	T& Array<T>::operator[](uint32_t i)
	{
		return m_vec[i];
	}



	template<typename T>
	const T& Array<T>::operator[](uint32_t i) const
	{
		return m_vec[i];
	}
}



#endif
