#ifndef IM_CONTROLLERS_MAINCONTROLLER
#define IM_CONTROLLERS_MAINCONTROLLER

#include "Controller.hpp"
#include "../database/ArticleDAO.hpp"

namespace im
{
    namespace controllers
    {
        class MainController : public Controller
        {
        public:
            MainController();
            crow::response mainPage();

        private:
        };
    }
}

#endif
