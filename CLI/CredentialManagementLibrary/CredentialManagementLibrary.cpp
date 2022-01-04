#include "CredentialManagementLibrary.h"
#include "CredentialStorage.h"
#include "StorageTxt.h"

CredentialManagementLibrary::CredentialManagementLibrary()
{
}

std::shared_ptr<CredentialStorageInterface> CredentialManagementLibrary::initCredentialsStorage(CREDENTIALS::value type, const std::string & name)
{
    auto storage = mapCredentials[type];
    if (!storage)
    {
        storage = CredentialStorage::createStorage(type);
        mapCredentials[type] = storage;
        storage->initCredentialsStorage(name);
    }

    return storage;
}

std::shared_ptr<CredentialStorageInterface> CredentialManagementLibrary::getStorage(CREDENTIALS::value type)
{
    auto storage = mapCredentials[type];
    if (!storage)
        return nullptr;

    return storage;
}

//// Método asyncrono para adicionar dados ao Storage
/// \brief CredentialManagementLibrary::addSiteCredential
/// \param type
/// \param site
/// \param user
/// \param password
/// \return
///
bool CredentialManagementLibrary::addSiteCredential(CREDENTIALS::value type, const std::string &site, const std::string &user, const std::string &password)
{
    std::future<bool> result = std::async(std::launch::async, [&]
    {
        auto storage = mapCredentials[type];
        if (!storage)
            return false;

        return storage->addSiteCredentialsAsync(site, user, password);
    });

    return result.get();
}

//// Método Asyncrono para recuperar a credencial de um usuário
/// \brief CredentialManagementLibrary::getSitePassword
/// \param site
/// \param user
/// \return
///
std::string CredentialManagementLibrary::getSitePassword(CREDENTIALS::value type, const std::string &site, const std::string &user)
{
    std::future<std::string> result = std::async(std::launch::async, [&]
    {
        std::string r;
        auto storage = mapCredentials[type];
        if (!storage)
            return r;

        return storage->getSitePasswordAsync(site, user);
    });

    return result.get();
}
