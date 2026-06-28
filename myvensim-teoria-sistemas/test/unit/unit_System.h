#ifndef UNITSYSTEM_H
#define UNITSYSTEM_H

#include <iostream>
#include <cmath>
#include <cstring>
#include <assert.h>

#include "../../src/SystemImpl.h"
#include "../../src/System.h"

/// @brief Executa todos os testes unitários da classe System.
void run_unit_test_System();

/// @brief Testa o construtor da classe System.
void unit_System_constructor();

/// @brief Testa o destrutor da classe System.
void unit_System_destructor();

/// @brief Testa o método getValue da classe System.
void unit_System_getValue();

/// @brief Testa o método setValue da classe System.
void unit_System_setValue();

/// @brief Testa o método getName da classe System.
void unit_System_getName();

/// @brief Testa o método setName da classe System.
void unit_System_setName();

#endif
