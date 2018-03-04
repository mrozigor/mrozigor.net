#ifndef IM_CONTROLLERS_CONTROLLER
#define IM_CONTROLLERS_CONTROLLER

#include "../crow.hpp"
#include "../version.hpp"

namespace im
{
    namespace controllers
    {
        class Controller
        {
        public:
            Controller();
            virtual ~Controller();

        protected:
            crow::response createResponse();

            crow::mustache::context context;
        };
    }
}

#endif
