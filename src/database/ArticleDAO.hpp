#ifndef IM_DATABASE_ARTICLEDAO
#define IM_DATABASE_ARTICLEDAO

#include <pqxx/pqxx>

#include "Database.hpp"

namespace im
{
    namespace database
    {
        class ArticleDAO : public Database
        {
        public:
            ArticleDAO();

        private:
            int temp;
        };
    }
}

#endif
