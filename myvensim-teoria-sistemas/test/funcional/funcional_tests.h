#ifndef FUNCIONAL_TESTS_HPP
#define FUNCIONAL_TESTS_HPP

/**
 * @file funcional_tests.hpp
 * @brief Contém declarações dos testes funcionais do sistema.
 */

#include "../../src/Model.h"
#include "../flows/ExponentialFlow.h"
#include "../flows/LogisticFlow.h"

#include <assert.h>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <cstring>

/**
 * @class Complex
 * @brief Representa um fluxo complexo que aplica uma equação personalizada.
 *
 * Esta classe herda de FlowImpl e define uma equação personalizada
 * que será aplicada entre dois sistemas.
 */
class Complex : public FlowImpl {
public:
    /**
     * @brief Construtor padrão.
     */
    Complex() : FlowImpl() {}

    /**
     * @brief Construtor que recebe ponteiros para os sistemas de origem e destino.
     * @param source Ponteiro para o sistema de origem do fluxo.
     * @param target Ponteiro para o sistema de destino do fluxo.
     */
    Complex(System* source, System* target) : FlowImpl("", source, target) {}

    /**
     * @brief Construtor de cópia.
     * @param f Objeto Flow a ser copiado.
     */
    Complex(Flow& f) : FlowImpl(f) {}

    /**
     * @brief Executa a equação do fluxo complexo.
     * @return Valor resultante da equação aplicada ao sistema de origem.
     */
    double execute() {
        return source->getValue() * 0.01;
    }
};

/**
 * @brief Executa o teste funcional para o fluxo exponencial.
 */
void exponentialFuncionalTest();

/**
 * @brief Executa o teste funcional para o fluxo logístico.
 */
void logisticalFuncionalTest();

/**
 * @brief Executa o teste funcional para um cenário de fluxo complexo.
 */
void complexFuncionalTest();

#endif
