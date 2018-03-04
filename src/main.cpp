#include "crow.hpp"
#include "version.hpp"
#include "controllers/UsersController.hpp"
#include "controllers/MainController.hpp"

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
      controllers::UsersController controller;
      return controller.loginForm();
  });

  CROW_ROUTE(application, "/login").methods("POST"_method)([](){
      //TODO HANDLE LOGIN AND RETURN TO MAIN PAGE
      return "";
  });

  CROW_ROUTE(application, "/about")([](){
      return "";
  });

  // TODO TEMPORARY
  CROW_ROUTE(application, "/css/pure-min.css")([](){
      std::ifstream style("assets/css/pure-min.css", std::ios::binary);
      crow::response response = crow::response(std::string(std::istreambuf_iterator<char>(style), std::istreambuf_iterator<char>()));
      response.add_header("Content-Type", "text/css");
      response.add_header("Content-Length", std::to_string(response.body.size()));
      return response;
  });

  // TODO TEMPORARY
  CROW_ROUTE(application, "/css/grids-responsive-min.css")([](){
      std::ifstream style("assets/css/grids-responsive-min.css", std::ios::binary);
      crow::response response = crow::response(std::string(std::istreambuf_iterator<char>(style), std::istreambuf_iterator<char>()));
      response.add_header("Content-Type", "text/css");
      response.add_header("Content-Length", std::to_string(response.body.size()));
      return response;
  });

  // TODO TEMPORARY
  CROW_ROUTE(application, "/css/style.css")([](){
      std::ifstream style("assets/css/style.css", std::ios::binary);
      crow::response response = crow::response(std::string(std::istreambuf_iterator<char>(style), std::istreambuf_iterator<char>()));
      response.add_header("Content-Type", "text/css");
      response.add_header("Content-Length", std::to_string(response.body.size()));
      return response;
  });

  // TODO TEMPORARY
  CROW_ROUTE(application, "/images/header-logo.png")([](){
      std::ifstream style("assets/images/header-logo.png", std::ios::binary);
      crow::response response = crow::response(std::string(std::istreambuf_iterator<char>(style), std::istreambuf_iterator<char>()));
      response.add_header("Content-Type", "image/png");
      response.add_header("Content-Length", std::to_string(response.body.size()));
      return response;
  });

  // TODO TEMPORARY
  CROW_ROUTE(application, "/images/favicon.png")([](){
      std::ifstream style("assets/images/favicon.png", std::ios::binary);
      crow::response response = crow::response(std::string(std::istreambuf_iterator<char>(style), std::istreambuf_iterator<char>()));
      response.add_header("Content-Type", "image/png");
      response.add_header("Content-Length", std::to_string(response.body.size()));
      return response;
  });

  // TODO TEMPORARY
  CROW_ROUTE(application, "/js/script.js")([](){
      std::ifstream style("assets/js/script.js", std::ios::binary);
      crow::response response = crow::response(std::string(std::istreambuf_iterator<char>(style), std::istreambuf_iterator<char>()));
      response.add_header("Content-Type", "aplication/javascript");
      response.add_header("Content-Length", std::to_string(response.body.size()));
      return response;
  });

  // TODO TEMPORARY
  CROW_ROUTE(application, "/js/jquery.js")([](){
      std::ifstream style("assets/js/jquery.js", std::ios::binary);
      crow::response response = crow::response(std::string(std::istreambuf_iterator<char>(style), std::istreambuf_iterator<char>()));
      response.add_header("Content-Type", "aplication/javascript");
      response.add_header("Content-Length", std::to_string(response.body.size()));
      return response;
  });

  application.port(9449).multithreaded().run();
}
