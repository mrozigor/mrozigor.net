#include "Article.hpp"

im::models::Article::Article(const uint32_t& id, const std::string& title, const std::string& body, const std::vector<std::string>& tags, const std::string& created, const std::string& edited) : id(id), title(title), body(body), tags(tags), created(created), edited(edited)
{
}

uint32_t im::models::Article::getId()
{
    return id;
}

std::string im::models::Article::getTitle()
{
    return title;
}

std::string im::models::Article::getBody()
{
    return body;
}

std::vector<std::string> im::models::Article::getTags()
{
    return tags;
}

std::string im::models::Article::getCreated()
{
    return created;
}

std::string im::models::Article::getEdited()
{
    return edited;
}
