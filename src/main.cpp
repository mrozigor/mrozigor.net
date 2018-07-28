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
  CROW_ROUTE(application, "/css/normalize.css")([](){
      std::ifstream style("assets/css/normalize.css", std::ios::binary);
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
  CROW_ROUTE(application, "/images/github-logo.png")([](){
      std::ifstream style("assets/images/github-logo.png", std::ios::binary);
      crow::response response = crow::response(std::string(std::istreambuf_iterator<char>(style), std::istreambuf_iterator<char>()));
      response.add_header("Content-Type", "image/png");
      response.add_header("Content-Length", std::to_string(response.body.size()));
      return response;
    });

  // TODO TEMPORARY
  CROW_ROUTE(application, "/images/khanacademy-logo.png")([](){
      std::ifstream style("assets/images/khanacademy-logo.png", std::ios::binary);
      crow::response response = crow::response(std::string(std::istreambuf_iterator<char>(style), std::istreambuf_iterator<char>()));
      response.add_header("Content-Type", "image/png");
      response.add_header("Content-Length", std::to_string(response.body.size()));
      return response;
    });

  // TODO TEMPORARY
  CROW_ROUTE(application, "/images/linkedin-logo.png")([](){
      std::ifstream style("assets/images/linkedin-logo.png", std::ios::binary);
      crow::response response = crow::response(std::string(std::istreambuf_iterator<char>(style), std::istreambuf_iterator<char>()));
      response.add_header("Content-Type", "image/png");
      response.add_header("Content-Length", std::to_string(response.body.size()));
      return response;
    });

  // TODO TEMPORARY
  CROW_ROUTE(application, "/images/twitter-logo.png")([](){
      std::ifstream style("assets/images/twitter-logo.png", std::ios::binary);
      crow::response response = crow::response(std::string(std::istreambuf_iterator<char>(style), std::istreambuf_iterator<char>()));
      response.add_header("Content-Type", "image/png");
      response.add_header("Content-Length", std::to_string(response.body.size()));
      return response;
    });

  // TODO TEMPORARY
  CROW_ROUTE(application, "/images/stackexchange-logo.png")([](){
      std::ifstream style("assets/images/stackexchange-logo.png", std::ios::binary);
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
