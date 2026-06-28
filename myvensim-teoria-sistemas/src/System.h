#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>
#include <ostream>

using namespace std;

/// @brief Representa um sistema, que é um estoque de energia ou recurso.
/// 
/// A classe `System` é uma interface abstrata que define os métodos fundamentais
/// que qualquer sistema concreto deve implementar, como nome, valor atual e operações básicas.
class System
{
public:
    /// @brief Destrutor virtual da classe `System`.
    virtual ~System() {}

    /// @brief Sobrecarga do operador de atribuição.
    /// @param obj Objeto do tipo `System` a ser copiado.
    /// @return Referência para o objeto atual após a cópia.
    //virtual System &operator=(const System &obj) = 0;

    /// @brief Retorna o nome do sistema.
    /// @return Nome do sistema como uma `string`.
    virtual string getName() const = 0;

    /// @brief Define o nome do sistema.
    /// @param name Novo nome para o sistema.
    virtual void setName(const string name) = 0;

    /// @brief Retorna o valor armazenado no sistema.
    /// @return Valor atual como `double`.
    virtual double getValue() const = 0;

    /// @brief Define o valor armazenado no sistema.
    /// @param value Novo valor como `double`.
    virtual void setValue(double value) = 0;
};

#endif
