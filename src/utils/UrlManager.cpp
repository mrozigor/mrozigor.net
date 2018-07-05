#include "UrlManager.hpp"
#include <iostream>

im::utils::UrlManager::UrlManager()
{
    loadBaseURL();
}

void im::utils::UrlManager::loadBaseURL()
{
    libconfig::Config config;
    config.readFile(".config");
    baseUrl = config.lookup("baseUrl").c_str();
    if (baseUrl.length() > 0 && baseUrl[baseUrl.length() - 1] != '/') {
        baseUrl += "/";
    }
    if (config.exists("enableTLS") && config.lookup("enableTLS")) {
        baseUrl.insert(0, "https://");
    } else {
        baseUrl.insert(0, "http://");
    }
}

std::string im::utils::UrlManager::getBaseUrl()
{
    return baseUrl;
}
