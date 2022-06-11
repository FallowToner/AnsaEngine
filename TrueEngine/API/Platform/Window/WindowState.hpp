#ifndef Window_Data_Hpp
#define Window_Data_Hpp

#include <GLFW/glfw3.h>

#include <string>

class WindowState
{

public:
	// WindowState(int width, int height, const std::string& title, GLFWmonitor* monitor, GLFWwindow* share);
public:
	void setWindowState(int width, int height, std::string title, GLFWmonitor* monitor, GLFWwindow* shareWindow);
	void setWindowState(WindowState&& state);
	void setWindowState(const WindowState& state);

	WindowState& getWindowState();

	int          getWidth() const;
	int          getHight() const;
	std::string  getTitle() const;
	GLFWmonitor* getMonitor() const;
	[[nodiscard]] GLFWwindow*  getShareWindow() const;

	void setWidth(int width);
	void setHight(int hight);
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
#endif // Window_Data_Hpp
