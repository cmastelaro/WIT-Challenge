#ifndef STORAGETXT_H
#define STORAGETXT_H

#include "CredentialManagementLibrary_global.h"
#include "CredentialStorageInterface.h"

#include <string>

class StorageTXT : public CredentialStorageInterface
{
private:
    struct Record
    {
        std::string name;
        std::string username;
        std::string password;

        friend std::ostream & operator << (std::ostream& os, const Record& r)
        {
            return os << r.name << '\n'
                      << r.username << '\n'
                      << r.password << '\n';
        }

        friend std::istream & operator >> (std::istream& is, Record& r)
        {
            std::getline(is, r.name);
            std::getline(is, r.username);
            std::getline(is, r.password);
            return is;
        }
    };
public:
    StorageTXT();

    bool initCredentialsStorage(const std::string & name) override;

    bool addSiteCredentials(const std::string & site,
                            const std::string & user,
                            const std::string & password) override;

    std::string getSitePassword(const std::string & site,
                                const std::string & user) override;

    std::vector<CredentialStorageInterface::Record> fetchRecords() override;

    bool addSiteCredentialsAsync(const std::string & site,
                                 const std::string & user,
                                 const std::string & password) override;

    std::string getSitePasswordAsync(const std::string & site,
                                     const std::string & user) override;

private:
    std::vector<Record> records;
    std::mutex mutex;
};

#endif // STORAGETXT_H
