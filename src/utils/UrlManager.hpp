#ifndef IM_UTILS_URLMANAGER
#define IM_UTILS_URLMANAGER

#include <string>
#include <libconfig.h++>

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

#endif
