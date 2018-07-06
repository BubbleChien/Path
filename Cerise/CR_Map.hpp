
#ifndef CR_MAP_HPP
#define CR_MAP_HPP



#include "./CR_Common.hpp"

#include "./CR_Hash.hpp"



namespace CR
{
	template<typename T>
	class Map
	{
		CR_PRIVATE

		std::unordered_map<uint32_t, T> m_map;

		CR_PUBLIC

		inline void Clear();

		inline bool Exists(const char* key) const;

		inline T& operator[](const char* key);
	};



	template<typename T>
	void Map<T>::Clear()
	{
		m_map.clear();
	}



	template<typename T>
	bool Map<T>::Exists(const char* key) const
	{
		return (m_map.find(Hash::String(key)) != m_map.end());
	}



	template<typename T>
	T& Map<T>::operator[](const char* key)
	{
		return m_map[Hash::String(key)];
	}
}



#endif
