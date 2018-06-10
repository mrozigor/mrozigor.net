#include "UrlManager.hpp"
#include <iostream>

im::utils::UrlManager::UrlManager()
{
    libconfig::Config config;
    config.readFile(".config");
    baseUrl = config.lookup("baseUrl").c_str();
    if (baseUrl.length() > 0 && baseUrl[baseUrl.length() - 1] != '/') {
        baseUrl += "/";
    }
}

std::string im::utils::UrlManager::getBaseUrl()
{
    return baseUrl;
}
