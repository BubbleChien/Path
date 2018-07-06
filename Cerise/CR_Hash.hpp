
#ifndef CR_HASH_HPP
#define CR_HASH_HPP



#include "./CR_Common.hpp"



namespace CR
{
	namespace Hash
	{
		inline const uint32_t StringFunc(const char* str)
		{
			uint32_t hash = 0x811C9DC5;

			for(uint32_t i = 0; str[i] != '\0'; ++i)
			{
				hash ^= str[i];
				hash *= 0x1000193;
			}

			return hash;
		}



		inline constexpr uint32_t String(const char* str)
		{
			return (str == nullptr ? 0x811C9DC5 : Hash::StringFunc(str));
		}
	}
}



#endif
