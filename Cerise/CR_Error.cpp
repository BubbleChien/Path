
#include "./CR_Error.hpp"

#include "./CR_Game.hpp"
#include "./CR_String.hpp"



namespace CR
{
	namespace Error
	{
		static bool shown = false;



		static void Display(const char* message)
		{
			errorConf err;

			errorInit(&err, ERROR_TEXT, CFG_LANGUAGE_EN);
			errorText(&err, message);

			errorDisp(&err);
		}



		void Show(const char* message, const char* info)
		{
			if(Error::shown) return;

			if(info != nullptr)
			{
				String str;

				str.Append(message);
				str.Append("\n\n");
				str.Append(info);

				Error::Display(str.GetData());
			}
			else
			{
				Error::Display(message);
			}

			Error::shown = true;

			Game::instance.Quit();
		}
	}
}
