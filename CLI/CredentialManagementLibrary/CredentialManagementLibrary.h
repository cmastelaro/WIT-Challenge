#ifndef CREDENTIALMANAGEMENTLIBRARY_H
#define CREDENTIALMANAGEMENTLIBRARY_H

#include "CredentialStorageInterface.h"

class CREDENTIALMANAGEMENTLIBRARY_EXPORT CredentialManagementLibrary
{
private:
    std::map<uint8_t, std::shared_ptr<CredentialStorageInterface>> mapCredentials;

public:
    struct CREDENTIALS
    {
        typedef uint8_t value;
        static const value TXT = 0;
        static const value DATABASE = 1;
        static const value CLOUD = 2;
    };

public:
    CredentialManagementLibrary();
    virtual ~CredentialManagementLibrary() {}

    std::shared_ptr<CredentialStorageInterface> initCredentialsStorage(CREDENTIALS::value type,
                                                                       const std::string & name);

    // Pode-se utilizar o CredentialStorage diretamente fornecido pelo CredentialManagement
    std::shared_ptr<CredentialStorageInterface> getStorage(CREDENTIALS::value type);

    // Ou então pode-se utilizar os metodos asyncronos da API
    bool addSiteCredential(CREDENTIALS::value type,
                           const std::string & site,
                           const std::string & user,
                           const std::string & password);

    std::string getSitePassword(CREDENTIALS::value type,
                                const std::string & site,
                                const std::string & user);

};

#endif // CREDENTIALMANAGEMENTLIBRARY_H
