#ifndef IM_DATABASE_DATABASE
#define IM_DATABASE_DATABASE

#include <pqxx/pqxx>
#include <libconfig.h++>

#include "NotConnectedException.hpp"

namespace im
{
    namespace database
    {
        class Database
        {
        public:
            Database();
            ~Database();
            pqxx::result executeSQL(const std::string& sqlStatement);

        private:
            std::unique_ptr<pqxx::connection> connection;
        };
    }
}

#endif
