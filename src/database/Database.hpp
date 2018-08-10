#pragma once

#include <pqxx/pqxx>

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

