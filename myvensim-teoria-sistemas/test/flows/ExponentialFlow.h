#ifndef EXPONENTIALFLOW_H
#define EXPONENTIALFLOW_H

#include "../../src/FlowImpl.h"

/// @brief Classe que representa um fluxo com comportamento exponencial.
/// 
/// Esta classe herda de FlowImpl e implementa a função execute()
/// utilizando uma equação exponencial.
class ExponentialFlow : public FlowImpl
{
public:
    /// @brief Construtor padrão.
    ExponentialFlow();

    /// @brief Construtor de cópia.
    /// @param obj Objeto Flow a ser copiado.
    ExponentialFlow(Flow &obj);

    /// @brief Construtor com parâmetros.
    /// @param name Nome do fluxo.
    /// @param origin Ponteiro para o sistema de origem.
    /// @param target Ponteiro para o sistema de destino.
    ExponentialFlow(const string name, System *origin, System *target);

    /// @brief Destrutor virtual.
    virtual ~ExponentialFlow();

    /// @brief Executa a equação exponencial do fluxo.
    /// @return O resultado da equação (valor transferido).
    virtual double execute();
};

#endif
