//
// Created by sakhil on 29.05.22.
//

#ifndef WINDOWDATA_HPP
#define WINDOWDATA_HPP

#include <string>


namespace TrueEngine
{
	namespace Platform
	{
		class WindowData
		{
		public:
			int getWidth() const;
			void setWidth(int width);

			int getHeight() const;
			void setHeight(int height);

			std::string     getTitle() const;
			void            setTitle(std::string title);

		private:
			int             mWindowWidth;
			int             mWindowHeight;
			std::string     mTitle; //!< The title of the window.
		};
	} // namespace Platform
} // namespace TrueEngine
#endif // WINDOWDATA_HPP
