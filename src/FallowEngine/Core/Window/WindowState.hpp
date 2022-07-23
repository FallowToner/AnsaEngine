#ifndef Window_Data_Hpp
#define Window_Data_Hpp


// clang-format off
#ifdef WIN32
	#include <GL/glew.h>
	#include <GLFW/glfw3.h>
#else
	#include <GL/glew.h>
	#include <GLFW/glfw3.h>
#endif
// clang-format on

#include <string>

namespace fallow
{
	namespace core
	{
		class WindowState
		{

		public:
			// WindowState(int width, int height, const std::string& title, GLFWmonitor* monitor, GLFWwindow* share);
		public:
			void setWindowState(int          width,
			                    int          height,
			                    std::string  title,
			                    GLFWmonitor* monitor,
			                    GLFWwindow*  shareWindow);
			void setWindowState(WindowState&& state);
			void setWindowState(const WindowState& state);

			WindowState& getWindowState();

			int                        getWidth() const;
			int                        getHeight() const;
			std::string                getTitle() const;
			[[nodiscard]] GLFWmonitor* getMonitor() const;
			[[nodiscard]] GLFWwindow*  getShareWindow() const;

			void setWidth(int width);
			void setHeight(int height);
			void setTitle(std::string title);
			void setMonitor(GLFWmonitor* monitor);
			void setShareWindow(GLFWwindow* shareWindow);

		private:
			int          mWidth{};
			int          mHeight{};
			std::string  mTitle{};
			GLFWmonitor* mMonitor{};
			GLFWwindow*  mShareWindow{};
		};
	} // namespace core
} // namespace fallow
#endif // Window_Data_Hpp
