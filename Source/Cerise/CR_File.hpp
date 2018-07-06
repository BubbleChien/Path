
#ifndef CR_FILE_HPP
#define CR_FILE_HPP



#include "./CR_Common.hpp"



namespace CR
{
	class File
	{
		CR_PRIVATE

		std::fstream m_file;

		uint32_t m_size = 0;

		CR_PUBLIC

		bool OpenRead(const char* filename);
		bool OpenWrite(const char* filename);

		CR_PUBLIC

		inline void Close();

		inline void Read(void* data, uint32_t size);
		inline void Write(const void* data, uint32_t size);

		inline uint32_t GetSize() const;
	};



	void File::Close()
	{
		m_file.close();
		m_file.clear();
		m_size = 0;
	}



	void File::Read(void* data, uint32_t size)
	{
		m_file.read(reinterpret_cast<char*>(data), size);
	}



	void File::Write(const void* data, uint32_t size)
	{
		m_file.write(reinterpret_cast<const char*>(data), size);
	}



	uint32_t File::GetSize() const
	{
		return m_size;
	}
}



#endif
