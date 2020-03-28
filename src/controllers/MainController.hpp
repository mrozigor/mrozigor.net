#pragma once

#include "Controller.hpp"

namespace im
{
    namespace controllers
    {
        class MainController : public Controller
        {
        public:
            MainController();
            crow::response mainPage();
            crow::response aboutMePage();
        };
    }
}

