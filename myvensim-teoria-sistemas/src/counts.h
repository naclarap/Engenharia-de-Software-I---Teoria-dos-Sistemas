/**
 * @file counts.hpp
 * @brief Contadores globais para rastreamento de alocações e desalocações.
 *
 * Este arquivo define variáveis globais inline usadas para monitorar a quantidade
 * de objetos `Handle` e `Body` que foram criados e destruídos durante a execução do programa.
 * Útil para depuração, testes e verificação de vazamentos de memória.
 */

#ifndef COUNTS_H
#define COUNTS_H

/// @brief Contador de instâncias de Handle criadas.
inline int numHandleCreated = 0;

/// @brief Contador de instâncias de Handle destruídas.
inline int numHandleDeleted = 0;

/// @brief Contador de instâncias de Body criadas.
inline int numBodyCreated = 0;

/// @brief Contador de instâncias de Body destruídas.
inline int numBodyDeleted = 0;

#endif // COUNTS_H
