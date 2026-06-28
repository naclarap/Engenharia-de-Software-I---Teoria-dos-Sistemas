#ifndef LOGISTICFLOW_H
#define LOGISTICFLOW_H

#include "../../src/FlowImpl.h"

/// @brief Classe que representa um fluxo com comportamento logístico.
///
/// Esta classe herda de FlowImpl e implementa a função execute()
/// utilizando uma equação logística.
class LogisticFlow : public FlowImpl
{
public:
    /// @brief Construtor padrão.
    LogisticFlow();

    /// @brief Construtor de cópia.
    /// @param obj Objeto Flow a ser copiado.
    LogisticFlow(Flow &obj);

    /// @brief Construtor com parâmetros.
    /// @param name Nome do fluxo.
    /// @param origin Ponteiro para o sistema de origem.
    /// @param target Ponteiro para o sistema de destino.
    LogisticFlow(const string name, System *origin, System *target);

    /// @brief Destrutor virtual.
    virtual ~LogisticFlow();

    /// @brief Executa a equação logística do fluxo.
    /// @return O resultado da equação (valor transferido).
    virtual double execute();
};

#endif
