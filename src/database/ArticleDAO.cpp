#include <pqxx/pqxx>

#include "ArticleDAO.hpp"

im::database::ArticleDAO::ArticleDAO(std::shared_ptr<Database> database) : database(database)
{
}

std::vector<im::models::Article> im::database::ArticleDAO::getArticles()
{
    pqxx::result result = database->executeSQL("SELECT * FROM articles ORDER BY created DESC");
    std::vector<models::Article> articles;

    for (pqxx::result::const_iterator c = result.begin(); c != result.end(); ++c) {
        std::vector<std::string> tags;
        std::stringstream ss(c[4].as<std::string>().substr(1, c[4].as<std::string>().length() - 2)); // TODO Move to some utils class
        std::string item;
        while (std::getline(ss, item, ',')) {
            tags.push_back(item);
        }
        articles.push_back(models::Article(c[0].as<uint32_t>(), c[1].as<std::string>(), c[3].as<std::string>(), tags, c[5].as<std::string>(), c[6].as<std::string>()));
    }

    return articles;
}
