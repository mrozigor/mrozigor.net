#include <libconfig.h++>

#include "Database.hpp"
#include "NotConnectedException.hpp"

im::database::Database::Database()
{
    libconfig::Config config;
    config.readFile(".config");
    std::string dbName = config.lookup("db.name");
    std::string dbUser = config.lookup("db.user");
    std::string dbPassword = config.lookup("db.password");
    std::string dbHost = config.lookup("db.host");
    std::string dbPort = config.lookup("db.port");
    std::string connectionStatement("dbname=" + dbName + " user=" + dbUser + " hostaddr=" + dbHost + " port=" + dbPort + " password=" + dbPassword);
    connection = std::make_unique<pqxx::connection>(connectionStatement);
}

im::database::Database::~Database()
{
}

pqxx::result im::database::Database::executeSQL(const std::string& sqlStatement)
{
    if (connection == nullptr || !connection->is_open()) {
        throw NotConnectedException();
    }

    pqxx::nontransaction executeObject(*connection);

    return executeObject.exec(sqlStatement);
}
