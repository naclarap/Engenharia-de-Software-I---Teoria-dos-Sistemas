#ifndef UNITMODEL_H
#define UNITMODEL_H

#include <iostream>
#include <cmath>
#include <cstring>
#include <assert.h>

#include "../../src/Model.h"
#include "../flows/ExponentialFlow.h"
#include "../flows/LogisticFlow.h"
#include "../../src/ModelImpl.h"
#include "../../src/SystemImpl.h"
#include "../flows/ExponentialFlow.h"
#include "../flows/LogisticFlow.h"

/// @brief Testa a função que retorna o tamanho da lista de modelos.
void unit_Model_getModelsize();

/// @brief Testa a criação de um sistema dentro do modelo.
void unit_Model_createSystem();

/// @brief Testa a definição do sistema de origem do fluxo no modelo.
void unit_Model_setSource();

/// @brief Testa a definição do sistema de destino do fluxo no modelo.
void unit_Model_setTarget();

/// @brief Testa a criação de um modelo.
void unit_Model_createModel();

/// @brief Executa todos os testes unitários do Model.
void run_unit_test_Model();

/// @brief Testa o construtor da classe Model.
void unit_Model_constructor();

/// @brief Testa o destrutor da classe Model.
void unit_Model_destructor();

/// @brief Testa o método getName da classe Model.
void unit_Model_getName();

/// @brief Testa o método setName da classe Model.
void unit_Model_setName();

/// @brief Testa o método de adicionar elementos no modelo.
void unit_Model_add();

/// @brief Testa o método de remover elementos do modelo.
void unit_Model_remove();

/// @brief Testa o método de limpar todos os elementos do modelo.
void unit_Model_clear();

/// @brief Testa a execução do modelo através do método run.
void unit_Model_run();

#endif
