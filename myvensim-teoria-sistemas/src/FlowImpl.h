#ifndef FLOWIMPL_H
#define FLOWIMPL_H

#include <iostream>
#include <string>
#include "Flow.h"
#include "handleBody.h"

/// @class FlowImpl
/// @brief Implementação da interface Flow.
///
/// Classe base abstrata para a implementação de fluxos. Armazena os
/// atributos comuns como nome, sistema de origem e sistema de destino.
/// A função execute deve ser implementada por classes derivadas.
class FlowImpl : public Body {
protected:
    string name;          ///< Nome do fluxo.
    System *source;       ///< Ponteiro para o sistema de origem.
    System *target;       ///< Ponteiro para o sistema de destino.

public:
    /// @brief Construtor padrão.
    FlowImpl();

    /// @brief Destrutor virtual.
    virtual ~FlowImpl();

    /// @brief Construtor com parâmetros.
    /// @param name Nome do fluxo.
    /// @param source Ponteiro para o sistema de origem.
    /// @param target Ponteiro para o sistema de destino.
    FlowImpl(const string name, System *source, System *target);

    /// @brief Construtor de cópia a partir de um objeto Flow.
    /// @param obj Referência para o objeto Flow.
    FlowImpl(Flow &rhs);

    /// @brief Operador de atribuição.
    /// @param obj Referência para o objeto Flow.
    /// @return Referência para o objeto Flow atribuído.
    Flow &operator=(const Flow &rhs);

    /// @brief Retorna o nome do fluxo.
    /// @return Nome do fluxo.
    string getName() const;

    /// @brief Define o nome do fluxo.
    /// @param name Novo nome para o fluxo.
    void setName(const string name);

    /// @brief Retorna o sistema de origem.
    /// @return Ponteiro para o sistema de origem.
    System *getSource() const;

    /// @brief Define o sistema de origem.
    /// @param source Ponteiro para o novo sistema de origem.
    void setSource(System *source);

    /// @brief Retorna o sistema de destino.
    /// @return Ponteiro para o sistema de destino.
    System *getTarget() const;

    /// @brief Define o sistema de destino.
    /// @param target Ponteiro para o novo sistema de destino.
    void setTarget(System *target);

    /// @brief Executa a equação do fluxo.
    ///
    /// Método virtual puro que deve ser implementado pelas classes concretas.
    /// @return Valor calculado pela equação do fluxo.
    virtual double execute() = 0;
};

/// @class FlowHandle
/// @brief Classe template que gerencia objetos FlowImpl utilizando Handle/Body.
///
/// Essa classe fornece encapsulamento e gerenciamento de memória utilizando
/// o padrão Handle/Body. Encaminha todas as chamadas para a implementação.
template <class T>
class FlowHandle : public Flow, public Handle<T> {
public:
    /// @brief Construtor padrão.
    ///
    /// Inicializa o fluxo com nome vazio e ponteiros nulos.
    FlowHandle() {
        Handle<T>::pImpl_->setSource(NULL);
        Handle<T>::pImpl_->setTarget(NULL);
        Handle<T>::pImpl_->setName("");
    }

    /// @brief Construtor com parâmetros.
    /// @param name Nome do fluxo.
    /// @param source Ponteiro para o sistema de origem.
    /// @param target Ponteiro para o sistema de destino.
    FlowHandle(const string name, System *source, System *target) {
        Handle<T>::pImpl_->setSource(source);
        Handle<T>::pImpl_->setTarget(target);
        Handle<T>::pImpl_->setName(name);
    }

    /// @brief Construtor de cópia a partir de um Flow.
    /// @param f Referência para o objeto Flow.
    FlowHandle(const Flow &f) {
        Handle<T>::pImpl_->setSource(f.getSource());
        Handle<T>::pImpl_->setTarget(f.getTarget());
    }

    /// @brief Retorna o nome do fluxo.
    /// @return Nome do fluxo.
    string getName() const {
        return Handle<T>::pImpl_->getName();
    }

    /// @brief Define o nome do fluxo.
    /// @param name Novo nome.
    void setName(const string name) {
        Handle<T>::pImpl_->setName(name);
    }

    /// @brief Define o sistema de origem.
    /// @param s Ponteiro para o sistema de origem.
    void setSource(System *s) {
        Handle<T>::pImpl_->setSource(s);
    }

    /// @brief Retorna o sistema de origem.
    /// @return Ponteiro para o sistema de origem.
    System *getSource() const {
        return Handle<T>::pImpl_->getSource();
    }

    /// @brief Define o sistema de destino.
    /// @param s Ponteiro para o sistema de destino.
    void setTarget(System *s) {
        Handle<T>::pImpl_->setTarget(s);
    }

    /// @brief Retorna o sistema de destino.
    /// @return Ponteiro para o sistema de destino.
    System *getTarget() const {
        return Handle<T>::pImpl_->getTarget();
    }

    /// @brief Executa a equação do fluxo.
    /// @return Valor calculado pela equação.
    double execute() {
        return Handle<T>::pImpl_->execute();
    }

};

#endif
