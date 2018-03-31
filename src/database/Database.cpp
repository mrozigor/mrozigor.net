#include "Database.hpp"

im::database::Database::Database()
{
    libconfig::Config config;
    config.readFile(".dbconfig");
    std::string dbName = config.lookup("dbName");
    std::string dbUser = config.lookup("dbUser");
    std::string dbPassword = config.lookup("dbPassword");
    std::string dbHost = config.lookup("dbHost");
    std::string dbPort = config.lookup("dbPort");
    std::string connectionStatement("dbname=" + dbName + " user=" + dbUser + " hostaddr=" + dbHost + " port=" + dbPort + " password=" + dbPassword);
    connection = std::make_unique<pqxx::connection>(connectionStatement);
}

im::database::Database::~Database()
{
    if (connection != nullptr && connection->is_open()) {
        connection->disconnect();
    }
}

pqxx::result im::database::Database::executeSQL(const std::string& sqlStatement)
{
    if (connection == nullptr || !connection->is_open()) {
        throw NotConnectedException();
    }

    pqxx::nontransaction executeObject(*connection);

    return executeObject.exec(sqlStatement);
}
