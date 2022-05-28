#include "Platform/Settings/GlfwSettingData.hpp"

/**
 * @brief Loads settings from a file
 * @details Reads data from a file and sends it to a structure
 * @param path Path to the settings file
 */
void API::Platform::GlfwSettingsData::loadFromFile(std::string& path)
{
    mINI::INIFile reader(path.data());

    mINI::INIStructure ini;
    reader.read(ini);

    windowHeight = std::atoi(ini["Settings"]["WindowHeight"].c_str());
    windowWidth  = std::atoi(ini["Settings"]["WindowWidth"].c_str());
    windowTitle  = ini["Settings"]["WindowTitle"];
    frameRate    = std::atoi(ini["Settings"]["FrameRate"].c_str());
}
/**
 * @brief Loads settings from structure in file
 * @details Reads data from a structure and sends it to a file
 * @param path Path to the settings file
 *
 * @error Throws an exception if the file cannot be read/write
 */
void API::Platform::GlfwSettingsData::loadInFIle(std::string& path)
{
    mINI::INIFile writer(path);
    mINI::INIStructure ini;

    bool isSuccessRead = writer.read(ini);
    if(!isSuccessRead){ throw std::runtime_error("Failed to read settings file"); }

    ini["Settings"]["WindowHeight"] = std::to_string(windowHeight);
    ini["Settings"]["WindowWidth"]  = std::to_string(windowWidth);
    ini["Settings"]["WindowTitle"]  = windowTitle;
    ini["Settings"]["FrameRate"]    = std::to_string(frameRate);

    bool isSuccessWrite = writer.write(ini);
    if(!isSuccessWrite){ throw std::runtime_error("Failed to write settings file"); }
}
