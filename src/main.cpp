#include "crow.hpp"
#include "version.hpp"

int main()
{
  crow::SimpleApp app;

  CROW_ROUTE(app, "/")([](){
      return "WiP - " + mrozigor::ApplicationVersion::get();
    });

  app.port(9449).multithreaded().run();
}
