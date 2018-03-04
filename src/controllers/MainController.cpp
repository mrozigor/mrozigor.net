#include "MainController.hpp"

im::controllers::MainController::MainController()
{
}

crow::response im::controllers::MainController::mainPage()
{
    context["title"] = "Strona główna";
    context["body"] = "<p>Dzień dobry podróżniku. Prace trwają!</p>";

    return createResponse();
}
