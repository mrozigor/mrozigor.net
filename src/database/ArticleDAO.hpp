#ifndef IM_DATABASE_ARTICLEDAO
#define IM_DATABASE_ARTICLEDAO

#include <pqxx/pqxx>

#include "Database.hpp"
#include "../models/Article.hpp"

namespace im
{
    namespace database
    {
        class ArticleDAO : public Database
        {
        public:
            ArticleDAO(std::shared_ptr<Database> database);
            std::vector<models::Article> getArticles();

        private:
            std::shared_ptr<Database> database;
        };
    }
}

#endif
