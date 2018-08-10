#pragma once

#include "../crow.hpp"
#include "../utils/UrlManager.hpp"

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
            utils::UrlManager urlManager;
        };
    }
}

