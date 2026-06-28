#ifndef SYSTEMIMPL_H
#define SYSTEMIMPL_H

#include <string>
#include <ostream>

#include "System.h"
#include "handleBody.h"

using namespace std;

/// @brief Implementação concreta da interface `System`.
///
/// Representa um sistema que armazena uma quantidade de energia (valor).
/// Esta classe herda de `Body` para usar o padrão Handle/Body.
class SystemImpl : public Body
{
public:
    /// @brief Construtor padrão.
    SystemImpl();

    /// @brief Destrutor virtual.
    virtual ~SystemImpl();

protected:
    string name;     ///< Nome do sistema.
    double value;    ///< Energia armazenada no sistema.

public:
    /// @brief Construtor que inicializa apenas o nome.
    /// @param name Nome do sistema.
    SystemImpl(const string name);

    /// @brief Construtor que inicializa apenas o valor.
    /// @param value Valor (energia) do sistema.
    SystemImpl(double value);

    /// @brief Construtor que inicializa nome e valor.
    /// @param name Nome do sistema.
    /// @param value Valor (energia) do sistema.
    SystemImpl(const string name, double value);

    /// @brief Construtor de cópia.
    /// @param obj Objeto `System` a ser copiado.
    SystemImpl(System &rhs);

    /// @brief Sobrecarga do operador de atribuição.
    /// @param obj Objeto `System` a ser copiado.
    /// @return Referência para o objeto atual.
    System &operator=(const System &rhs);

    /// @brief Retorna o nome do sistema.
    /// @return Nome como `string`.
    string getName() const;

    /// @brief Define o nome do sistema.
    /// @param name Nome a ser atribuído.
    void setName(const string name);

    /// @brief Retorna o valor do sistema.
    /// @return Valor como `double`.
    double getValue() const;

    /// @brief Define o valor do sistema.
    /// @param value Valor a ser atribuído.
    void setValue(double value);
};

/// @brief Classe de manipulação (handle) para `SystemImpl`.
///
/// Implementa a interface `System` e usa um ponteiro interno (`pImpl_`)
/// para acessar a implementação concreta (`SystemImpl`).
class SystemHandle : public System, public Handle<SystemImpl>
{
public:
    /// @brief Construtor padrão.
    SystemHandle()
    {
        pImpl_->setName("");
        pImpl_->setValue(0.0);
    }

    /// @brief Construtor com nome e valor.
    /// @param name Nome do sistema.
    /// @param value Valor do sistema.
    SystemHandle(const string name, double value)
    {
        pImpl_->setName(name);
        pImpl_->setValue(value);
    }

    /// @brief Construtor com apenas o valor.
    /// @param value Valor inicial.
    SystemHandle(double value)
    {
        pImpl_->setValue(value);
        pImpl_->setName("");
    }

    /// @brief Construtor com apenas o nome.
    /// @param name Nome do sistema.
    SystemHandle(const string name)
    {
        pImpl_->setName(name);
        pImpl_->setValue(0);
    }

    /// @brief Construtor de cópia a partir de outro `System`.
    /// @param obj Objeto `System` a ser copiado.
    SystemHandle(System &rhs)
    {
        pImpl_->setName(rhs.getName());
        pImpl_->setValue(rhs.getValue());
    }

    /// @brief Define o nome do sistema.
    /// @param name Nome a ser atribuído.
    void setName(const string name)
    {
        pImpl_->setName(name);
    }

    /// @brief Retorna o nome do sistema.
    /// @return Nome como `string`.
    string getName() const
    {
        return pImpl_->getName();
    }

    /// @brief Retorna o valor do sistema.
    /// @return Valor como `double`.
    double getValue() const
    {
        return pImpl_->getValue();
    }

    /// @brief Define o valor do sistema.
    /// @param value Valor a ser atribuído.
    void setValue(double value)
    {
        pImpl_->setValue(value);
    }

};

#endif // SYSTEMIMPL_H
