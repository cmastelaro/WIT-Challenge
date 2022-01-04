#include "StorageTxt.h"
#include <fstream>

StorageTXT::StorageTXT()
{
}

bool StorageTXT::initCredentialsStorage(const std::string & name)
{
    std::ifstream is("storage.dat");
    Record r;
    while (is >> r) {
        records.push_back(r);
    }

    return true;
}

bool StorageTXT::addSiteCredentials(const std::string & site,
                                    const std::string & user,
                                    const std::string & password)
{
    Record r;
    r.name = site;
    r.username = user;
    r.password = password;
    records.push_back(r);

    std::ofstream os("storage.dat", std::ios::app);
    os << r;
    return true;
}

std::string StorageTXT::getSitePassword(const std::string & site,
                                        const std::string & user)
{
    auto it = std::find_if(records.begin(), records.end(), [&](const Record & r){
       return r.name == site && r.username == user;
    });

    return it->password;
}

std::vector<CredentialStorageInterface::Record> StorageTXT::fetchRecords()
{
    std::vector<CredentialStorageInterface::Record> v;
    for (auto it : records)
    {
        CredentialStorageInterface::Record r;
        r.name = it.username;
        r.site = it.name;
        v.push_back(r);
    }
    return v;
}

////////////////////////////////////////////////////////////////////////////////////////////
/// Aqui começam a construção dos métodos ASYNC
////////////////////////////////////////////////////////////////////////////////////////////
bool StorageTXT::addSiteCredentialsAsync(const std::string & site,
                                         const std::string & user,
                                         const std::string & password)
{
    std::lock_guard<std::mutex> lk(mutex);

    Record r;
    r.name = site;
    r.username = user;
    r.password = password;
    records.push_back(r);

    std::ofstream os("storage.dat", std::ios::app);
    os << r;

    return true;
}

std::string StorageTXT::getSitePasswordAsync(const std::string & site,
                                             const std::string & user)
{
    std::lock_guard<std::mutex> lk(mutex);

    auto it = std::find_if(records.begin(), records.end(), [&](const Record & r){
       return r.name == site && r.username == user;
    });

    return it->password;
}
