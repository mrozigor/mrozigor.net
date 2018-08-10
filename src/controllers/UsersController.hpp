#pragma once

#include "Controller.hpp"

namespace im
{
    namespace controllers
    {
        class UsersController : public Controller
        {
        public:
            UsersController();
            crow::response loginForm();
        };
    }
}

