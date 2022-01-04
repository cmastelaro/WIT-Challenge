# WIT-Challenge
Teste de avaliação da empresa WIT Software

Aplicação Composta por:

1 - Uma biblioteca CredentialManagementLibrary
  * Contém métodos para gerenciar diversos storages
  * Métodos asincronos e thread safe se quiser utilizar em modo multithread
  * Extensível para outros formatos de storage
  * Uso de C++17
  * Multi-plataforma
  * Makefile

2 - Uma aplicação Windows para o usuário utilizar a biblioteca
  * Contém janela principal com um treeView exibindo os storages e usuários credenciados nos sites
  * Chamadas para criar storage / adicionar credenciais e recuperar credenciais
  * Utilização de biblioteca de terceiros QT
  * Uso de C++17
  * Makefile

NOTA: a aplicação está bem simples e prática, espero ter atendido aos requisitos funcionais e não funcionais.
Tentei sei o mais simples possível e demonstrar uma variedade de técnicas e conceitos de programação como
métodos asincronos, thread-safe, lambda expressions, factory methods entre outros.
