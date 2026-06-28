#ifndef FLOW_H
#define FLOW_H

#include <iostream>
#include <string>

#include "System.h"

/// @class Flow
/// @brief Representa um fluxo que transfere energia entre sistemas.
///
/// Esta classe abstrata define a interface para fluxos. Um fluxo conecta
/// dois sistemas (origem e destino) e executa uma equação para determinar
/// o valor transferido.
class Flow {
public:
    /// @brief Destrutor virtual.
    virtual ~Flow() {}

    // virtual Flow &operator=(const Flow &obj) = 0;

    /// @brief Retorna o nome do fluxo.
    /// @return Nome do fluxo como uma string.
    virtual string getName() const = 0;

    /// @brief Define o nome do fluxo.
    /// @param name Nome a ser atribuído ao fluxo.
    virtual void setName(const string name) = 0;

    /// @brief Retorna o sistema de origem do fluxo.
    /// @return Ponteiro para o sistema de origem.
    virtual System *getSource() const = 0;

    /// @brief Define o sistema de origem do fluxo.
    /// @param source Ponteiro para o sistema que será a origem.
    virtual void setSource(System *source) = 0;

    /// @brief Retorna o sistema de destino do fluxo.
    /// @return Ponteiro para o sistema de destino.
    virtual System *getTarget() const = 0;

    /// @brief Define o sistema de destino do fluxo.
    /// @param target Ponteiro para o sistema que será o destino.
    virtual void setTarget(System *target) = 0;

    /// @brief Executa a equação do fluxo.
    ///
    /// Este método deve ser implementado por subclasses para definir
    /// o comportamento específico do fluxo.
    /// @return Valor gerado pela equação do fluxo.
    virtual double execute() = 0;
};

#endif
