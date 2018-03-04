#include "UsersController.hpp"

im::controllers::UsersController::UsersController()
{
}

crow::response im::controllers::UsersController::loginForm()
{
    //TODO Add CSRF and other safety things
    context["title"] = "Logowanie";
    context["body"] = crow::mustache::load("login_form.mstch").render(context);

    return createResponse();
}
