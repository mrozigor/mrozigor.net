#ifndef IM_DATABASE_DATABASE
#define IM_DATABASE_DATABASE

#include <pqxx/pqxx>

namespace im
{
    namespace database
    {
        class Database
        {
        public:
            Database();

        private:
            int temp;
        };
    }
}

#endif
