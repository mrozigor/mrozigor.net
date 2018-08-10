#pragma once

#include <string>

namespace im
{
    namespace utils
    {
        class UrlManager
        {
        public:
            UrlManager();
            std::string getBaseUrl();

        private:
            void loadBaseURL();

            std::string baseUrl;
        };
    }
}

