//
// Created by sakhil on 29.05.22.
//

#include "WindowState.hpp"

namespace fallow
{
	namespace core
	{

		void WindowState::setWindowState(int          width,
		                                 int          height,
		                                 std::string  title,
		                                 GLFWmonitor* monitor,
		                                 GLFWwindow*  shareWindow)
		{
			mWidth       = width;
			mHeight      = height;
			mTitle       = std::move(title);
			mMonitor     = monitor;
			mShareWindow = shareWindow;
		}

		void WindowState::setWindowState(const WindowState& state) { *this = state; }
		void WindowState::setWindowState(WindowState&& state) { *this = std::move(state); }

		WindowState& WindowState::getWindowState() { return *this; }

		/**
		 * @details Get the width of the window.
		 * @return The current width of the window.
		 * @ingroup Core
		 */
		int          WindowState::getWidth() const { return mWidth; }
		/**
		 * @details Get the height of the window.
		 * @return The current height of the window.
		 * @ingroup Core
		 */
		int          WindowState::getHeight() const { return mHeight; }
		/**
		 * @details Get the title of the window.
		 * @return The current title of the window.
		 * @ingroup Core
		 */
		std::string  WindowState::getTitle() const { return mTitle; }
		/*!
		 * @brief  Get the current monitor.
		 * @return The current monitor.
		 * @note The monitor is the monitor the window is currently on.
		 * @ingroup Core
		 */
		GLFWmonitor* WindowState::getMonitor() const { return mMonitor; }

		/*!
		 * @brief  Get the current share window.
		 * @return The current share window.
		 * @note The share window is the window that is shared with the current window.
		 * @ingroup Core
		 */
		GLFWwindow* WindowState::getShareWindow() const { return mShareWindow; }
		/**
		 * @details Set the width of the window.
		 * @param[in] width The new width of the window.
		 * @ingroup Core
		 */
		void        WindowState::setWidth(int width) { mWidth = width; }
		/**
		 * @details Set the height of the window.
		 * @param[in] height The new height of the window.
		 * @ingroup Core
		 */
		void        WindowState::setHeight(int height) { mHeight = height; }
		/**
		 * @details Set the title of the window.
		 * @param[in] title The title of the window.
		 * @ingroup Core
		 */
		void        WindowState::setTitle(std::string title) { mTitle = std::move(title); }
		/*!
		 * @brief  Set the current monitor.
		 * @param[in] monitor The current monitor.
		 * @ingroup Core
		 */
		void        WindowState::setMonitor(GLFWmonitor* monitor) { mMonitor = monitor; }
		/*!
		 * @brief Set for current window shareWindow new value.
		 * @param[in] shareWindow new value.
		 * @ingroup Core
		 */
		void        WindowState::setShareWindow(GLFWwindow* shareWindow) { mShareWindow = shareWindow; }
	} // namespace core
} // namespace fallow