
#include "./CR_Graphics.hpp"

#include "./CR_Error.hpp"



namespace CR
{
	Graphics Graphics::instance;



	bool Graphics::Init()
	{
		gfxInitDefault();

		C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
		C2D_Init(C2D_DEFAULT_MAX_OBJECTS);

		C2D_Prepare();

		m_top = C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT);

		if(m_top == nullptr)
		{
			Error::Show("Failed to initialize top screen.");
			return false;
		}

		m_bot = C2D_CreateScreenTarget(GFX_BOTTOM, GFX_LEFT);

		if(m_bot == nullptr)
		{
			Error::Show("Failed to initialize bottom screen.");
			return false;
		}

		return true;
	}



	void Graphics::Free()
	{
		if(m_top != nullptr)
		{
			C3D_RenderTargetDelete(m_top);
		}

		if(m_bot != nullptr)
		{
			C3D_RenderTargetDelete(m_bot);
		}

		C2D_Fini();
		C3D_Fini();

		gfxExit();
	}
}
