#include "ResourcesController.hpp"

im::controllers::ResourcesController::ResourcesController()
{
}

crow::response im::controllers::ResourcesController::loadStylesheet(const std::string& stylesheetName)
{
    crow::response response = loadFile("assets/css/" + stylesheetName);
    response.add_header("Content-Type", "text/css");
    context["title"] = stylesheetName;
    return response;
}

crow::response im::controllers::ResourcesController::loadImage(const std::string& imageName)
{
    crow::response response = loadFile("assets/images/" + imageName);
    response.add_header("Content-Type", "image/png");
    context["title"] = imageName;
    return response;
}

crow::response im::controllers::ResourcesController::loadScript(const std::string& scriptName)
{
    crow::response response = loadFile("assets/js/" + scriptName); //TODO Load only on beginning. Load only files with given extension(?)
    response.add_header("Content-Type", "aplication/javascript");
    context["title"] = scriptName;
    return response;
}

crow::response im::controllers::ResourcesController::loadFile(const std::string& filePath)
{
    std::ifstream fileContent(filePath, std::ios::binary);
    crow::response response = crow::response(std::string(std::istreambuf_iterator<char>(fileContent), std::istreambuf_iterator<char>()));
    response.add_header("Content-Length", std::to_string(response.body.size()));
    return response;
}

