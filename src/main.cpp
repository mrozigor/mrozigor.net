#include "controllers/MainController.hpp"
#include "controllers/ResourcesController.hpp"
#include "controllers/UsersController.hpp"
#include "crow.hpp"
#include "version.hpp"

int main()
{
  using namespace im;
  crow::SimpleApp application;
  crow::logger::setLogLevel(crow::LogLevel::Debug);

  CROW_ROUTE(application, "/")([](){
      controllers::MainController controller;
      return controller.mainPage();
  });

  CROW_ROUTE(application, "/login").methods("GET"_method)([](){
      controllers::UsersController controller; //TODO Maybe create all controllers/resources at application start
      return controller.loginForm();
  });

  CROW_ROUTE(application, "/login").methods("POST"_method)([](){
      //TODO HANDLE LOGIN AND RETURN TO MAIN PAGE
      return "";
  });

  CROW_ROUTE(application, "/about")([](){
      return "";
  });

  CROW_ROUTE(application, "/css/<string>")([](const std::string& stylesheetName){
      controllers::ResourcesController controller;
      return controller.loadStylesheet(stylesheetName);
  });

  CROW_ROUTE(application, "/images/<string>")([](const std::string& imageName){
      controllers::ResourcesController controller;
      return controller.loadImage(imageName);
  });

  CROW_ROUTE(application, "/js/<string>")([](const std::string& scriptName){
      controllers::ResourcesController controller;
      return controller.loadScript(scriptName);
  });

  application.port(9449).multithreaded().run();
}
