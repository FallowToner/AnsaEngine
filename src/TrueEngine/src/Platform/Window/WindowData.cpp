//
// Created by sakhil on 29.05.22.
//

#include "Platform/Window/WindowData.hpp"
namespace TrueEngine
{
	namespace Platform
	{
		/**
		 * @details Get the width of the window.
		 * @return The current width of the window.
		 * @ingroup Platform
		 */
		int  WindowData::getWidth() const { return mWindowWidth; }
		/**
		 * @details Set the width of the window.
		 * @param[in] width The new width of the window.
		 * @ingroup Platform
		 */
		void WindowData::setWidth(int width) { mWindowWidth = width; }

		/**
		 * @details Get the height of the window.
		 * @return The current height of the window.
		 * @ingroup Platform
		 */
		int  WindowData::getHeight() const { return mWindowHeight; }
		/**
		 * @details Set the height of the window.
		 * @param[in] height The new height of the window.
		 * @ingroup Platform
		 */
		void WindowData::setHeight(int height) { mWindowHeight = height; }

		/**
		 * @details Get the title of the window.
		 * @return The current title of the window.
		 * @note The title of the window is the name of the window.
		 * @ingroup Platform
		 */
		std::string WindowData::getTitle() const { return mTitle; }
		/**
		 * @details Set the title of the window.
		 * @param[in] title The title of the window.
		 * @note The title of the window is the name of the window.
		 * @ingroup Platform
		 */
		void        WindowData::setTitle(std::string title) { mTitle = std::move(title); }
	} // namespace Platform
} // namespace TrueEngine