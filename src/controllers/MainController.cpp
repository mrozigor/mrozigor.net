#include "MainController.hpp"
#include "../database/ArticleDAO.hpp"

im::controllers::MainController::MainController()
{
}

crow::response im::controllers::MainController::mainPage()
{
    database::ArticleDAO articleDAO(std::make_shared<database::Database>());
    std::vector<crow::mustache::context> articlesToRender;
    for (models::Article& article : articleDAO.getArticles()) {
        std::vector<crow::mustache::context> tags;
        for (const std::string& tag : article.getTags()) {
            crow::mustache::context temp;
            temp["tag"] = tag;
            tags.push_back(std::move(temp));
        }
        crow::mustache::context articleContext;
        articleContext["title"] = article.getTitle();
        articleContext["body"] = article.getBody();
        articleContext["tags"] = std::move(tags);
        articleContext["created"] = article.getCreated().substr(0, article.getCreated().find("."));
        articlesToRender.push_back(std::move(articleContext));
    }
    context["title"] = "Strona główna";
    context["articles"] = std::move(articlesToRender);
    context["body"] = crow::mustache::load("articles.mstch").render(context);

    return createResponse();
}
