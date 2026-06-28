#ifndef UNITFLOW_H
#define UNITFLOW_H

#include <iostream>
#include <cmath>
#include <cstring>
#include <assert.h>

#include "../flows/ExponentialFlow.h"
#include "../flows/LogisticFlow.h"
#include "../../src/SystemImpl.h"
#include "../../src/ModelImpl.h"

/// @brief Executa todos os testes unitários dos métodos da classe Flow.
void run_unit_test_Flow();

/// @brief Testa o construtor da classe Flow.
void unit_Flow_constructor();

/// @brief Testa o destrutor da classe Flow.
void unit_Flow_destructor();

/// @brief Testa o método getName da classe Flow.
void unit_Flow_getName();

/// @brief Testa o método setName da classe Flow.
void unit_Flow_setName();

/// @brief Testa o método getSource (origem) da classe Flow.
void unit_Flow_getOrigin();

/// @brief Testa o método setSource (origem) da classe Flow.
void unit_Flow_setOrigin();

/// @brief Testa o método getTarget (destino) da classe Flow.
void unit_Flow_getTarget();

/// @brief Testa o método setTarget (destino) da classe Flow.
void unit_Flow_setTarget();

#endif
