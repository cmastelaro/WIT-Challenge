#ifndef CREDENTIALSTORAGE_H
#define CREDENTIALSTORAGE_H

#include "CredentialManagementLibrary_global.h"
#include "CredentialManagementLibrary.h"
#include "StorageTxt.h"

class CredentialStorage
{
public:
    /// Neste Factory Method você pode especializar o tipo de storage que desejar implementar
    /// Basta especializar a classe e instanciar no factory abaixo
    /// \brief createStorage
    /// \param type
    /// \return
    ///
    static std::shared_ptr<CredentialStorageInterface> createStorage(CredentialManagementLibrary::CREDENTIALS::value type)
    {
        switch(type)
        {
        case CredentialManagementLibrary::CREDENTIALS::TXT:
            return std::make_shared<StorageTXT>();
        case CredentialManagementLibrary::CREDENTIALS::DATABASE:
        case CredentialManagementLibrary::CREDENTIALS::CLOUD:
            return nullptr;
        default:
            return nullptr;
        }
    }
};

#endif // CREDENTIALSTORAGE_H
