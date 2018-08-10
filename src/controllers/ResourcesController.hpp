#pragma once

#include "Controller.hpp"

namespace im
{
    namespace controllers
    {
        class ResourcesController : public Controller
        {
        public:
            ResourcesController();
            crow::response loadStylesheet(const std::string& stylesheetName);
            crow::response loadImage(const std::string& imageName);
            crow::response loadScript(const std::string& scriptName);

        private:
            crow::response loadFile(const std::string& filePath);
        };
    }
}
