#ifndef CREDENTIALSTORAGEINTERFACE_H
#define CREDENTIALSTORAGEINTERFACE_H

#include "CredentialManagementLibrary_global.h"

class CredentialStorageInterface
{
public:
    struct Record
    {
        std::string site;
        std::string name;
    };

    virtual bool initCredentialsStorage(const std::string & name) = 0;

    virtual bool addSiteCredentials(const std::string & site,
                                    const std::string & user,
                                    const std::string & password) = 0;

    virtual std::string getSitePassword(const std::string & site,
                                        const std::string & user) = 0;

    virtual std::vector<Record> fetchRecords() = 0;

    virtual bool addSiteCredentialsAsync(const std::string & site,
                                         const std::string & user,
                                         const std::string & password) = 0;

    virtual std::string getSitePasswordAsync(const std::string & site,
                                             const std::string & user) = 0;
};

#endif // CREDENTIALSTORAGEINTERFACE_H
