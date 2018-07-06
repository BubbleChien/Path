
#include "./CR_File.hpp"

#include "./CR_Error.hpp"



namespace CR
{
	bool File::OpenRead(const char* filename)
	{
		this->Close();

		m_file.open(filename, std::ios::in | std::ios::binary);

		if(m_file.fail())
		{
			Error::Show("Failed to read file.", filename);
			return false;
		}

		m_file.seekg(0, std::ios::end);
		m_size = static_cast<uint32_t>(m_file.tellg());
		m_file.seekg(0, std::ios::beg);

		return true;
	}



	bool File::OpenWrite(const char* filename)
	{
		this->Close();

		m_file.open(filename, std::ios::out | std::ios::binary | std::ios::trunc);

		if(m_file.fail())
		{
			Error::Show("Failed to write file.", filename);
			return false;
		}

		return true;
	}
}
