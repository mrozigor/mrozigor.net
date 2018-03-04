#ifndef IM_CONTROLLERS_USERSCONTROLLER
#define IM_CONTROLLERS_USERSCONTROLLER

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

        private:
        };
    }
}

#endif
