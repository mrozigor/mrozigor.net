#include "crow.hpp"
#include "version.hpp"

int main()
{
  crow::SimpleApp application;
  crow::mustache::set_base("views");
  crow::logger::setLogLevel(crow::LogLevel::Debug);

  CROW_ROUTE(application, "/")([](){
      crow::mustache::context context;
      context["title"] = "Strona główna";
      context["description"] = "Strona prywatna Igora Mroza.";
      context["author"] = "Igor Mróz";
      context["keywords"] = "";
      context["head"] = crow::mustache::load("head.mstch").render(context);
      context["header"] = crow::mustache::load("header.mstch").render(context);
      context["navigation"] = crow::mustache::load("navigation.mstch").render(context);
      context["footer"] = crow::mustache::load("footer.mstch").render(context);
      context["body"] = "<p>Dzień dobry podróżniku. Prace trwają!</p>";
      context["version"] = mrozigor::ApplicationVersion::get();

      crow::response response = crow::response(crow::mustache::load("main.mstch").render(context));
      response.add_header("Content-Type", "text/html; charset=utf-8");
      response.add_header("Content-Length", std::to_string(response.body.size()));
      return response;
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

  application.port(9449).multithreaded().run();
}
