#ifndef MODELIMPL_H
#define MODELIMPL_H

#include <cstring>
#include <ostream>
#include <vector>

#include "Model.h"
#include "handleBody.h"

/// @class ModelImpl
/// @brief Implementação concreta da classe Model.
///
/// Essa classe armazena listas de sistemas e fluxos, permitindo criar,
/// remover e simular um modelo completo.
class ModelImpl : public Body {
public:
    /// @brief Construtor padrão.
    ModelImpl();

    /// @brief Destrutor.
    virtual ~ModelImpl();

protected:
    string name;                          ///< Nome do modelo.
    vector<Flow *> flow_list;             ///< Lista de fluxos do modelo.
    vector<System *> system_list;         ///< Lista de sistemas do modelo.
    static vector<Model *> models;        ///< Lista de todos os modelos criados.

public:
    /// @brief Adiciona um sistema ao modelo.
    /// @param s Ponteiro para o sistema a ser adicionado.
    void add(System *s);

    /// @brief Adiciona um fluxo ao modelo.
    /// @param f Ponteiro para o fluxo a ser adicionado.
    void add(Flow *f);

    /// @brief Construtor com nome do modelo.
    /// @param name Nome do modelo.
    ModelImpl(const string name);

    void setSource(Flow *f, System *s);
    void setTarget(Flow *f, System *s);

    typedef typename vector<Flow *>::iterator itFlow;
    typedef typename vector<System *>::iterator itSystem;
    typedef typename vector<Model *>::iterator itModel;

    /// @brief Retorna o nome do modelo.
    string getName() const;

    /// @brief Define o nome do modelo.
    void setName(const string name);

    itFlow getFlowBegin();
    itFlow getFlowEnd();
    int getFlowSize();

    itSystem getSystemBegin();
    itSystem getSystemEnd();
    int getSystemSize();

    itModel getModelbegin();
    itModel getModelEnd();

    /// @brief Retorna o número total de modelos existentes.
    static int getModelsize();

    /// @brief Remove um modelo da lista de modelos.
    /// @param m Iterador apontando para o modelo a ser removido.
    void eraseModel(Model::itModel m);

    /// @brief Remove um sistema do modelo.
    /// @param s Ponteiro para o sistema a ser removido.
    /// @return true se removido com sucesso.
    bool remove(System *s);

    /// @brief Remove um fluxo do modelo.
    /// @param f Ponteiro para o fluxo a ser removido.
    /// @return true se removido com sucesso.
    bool remove(Flow *f);

    /// @brief Remove todos os fluxos e sistemas do modelo.
    void clear();

    /// @brief Cria um novo modelo.
    /// @param name Nome do modelo.
    /// @return Ponteiro para o novo modelo.
    static Model *createModel(string name);

    /// @brief Cria e adiciona um novo sistema ao modelo.
    /// @param name_s Nome do sistema.
    /// @param value_s Valor inicial do sistema.
    /// @return Ponteiro para o sistema criado.
    System *createSystem(string name_s, double value_s);

    /// @brief Executa a simulação do modelo.
    /// @param ini_time Tempo inicial.
    /// @param fin_time Tempo final.
    /// @return Valor inteiro de controle (por ex: sucesso/falha).
    int run(int ini_time, int fin_time);

private:
    /// @brief Construtor de cópia (privado para evitar cópia acidental).
    ModelImpl(ModelImpl &rhs);

    /// @brief Operador de atribuição (privado para evitar cópia acidental).
    ModelImpl &operator=(const ModelImpl &rhs);
};

/// @class ModelHandle
/// @brief Classe de manipulação (handle) para ModelImpl.
///
/// Essa classe utiliza o padrão Handle/Body para encapsular a lógica
/// de manipulação de objetos do tipo ModelImpl.
class ModelHandle : public Model, public Handle<ModelImpl> {
public:
    /// @brief Adiciona um fluxo ao modelo.
    void add(Flow *f) {
        pImpl_->add(f);
    }

    /// @brief Adiciona um sistema ao modelo.
    void add(System *s) {
        pImpl_->add(s);
    }

    /// @brief Construtor do handle de modelo.
    /// @param name Nome do modelo.
    ModelHandle(const string &name = "") {
        pImpl_->setName(name);
    }


    /// @brief Cria um sistema e o adiciona ao modelo.
    System *createSystem(string name, double values_s) {
        return pImpl_->createSystem(name, values_s);
    }

    /// @brief Remove um fluxo do modelo.
    bool remove(Flow *f) {
        return pImpl_->remove(f);
    }

    /// @brief Remove um sistema do modelo.
    bool remove(System *s) {
        return pImpl_->remove(s);
    }

    /// @brief Remove todos os fluxos e sistemas.
    void clear() {
        pImpl_->clear();
    }

    /// @brief Retorna o número de sistemas no modelo.
    int getSystemSize() {
        return pImpl_->getSystemSize();
    }

    itSystem getSystemBegin() {
        return pImpl_->getSystemBegin();
    }

    itSystem getSystemEnd() {
        return pImpl_->getSystemEnd();
    }

    itModel getModelEnd() {
        return pImpl_->getModelEnd();
    }

    itModel getModelbegin() {
        return pImpl_->getModelbegin();
    }

    static int getModelsize();

    itFlow getFlowBegin() {
        return pImpl_->getFlowBegin();
    }

    itFlow getFlowEnd() {
        return pImpl_->getFlowEnd();
    }

    int getFlowSize() {
        return pImpl_->getFlowSize();
    }

    /// @brief Define o nome do modelo.
    void setName(const string name) {
        pImpl_->setName(name);
    }

    /// @brief Retorna o nome do modelo.
    string getName() const {
        return pImpl_->getName();
    }

    /// @brief Define o sistema de origem de um fluxo.
    void setSource(Flow *f, System *s) {
        pImpl_->setSource(f, s);
    }

    /// @brief Define o sistema de destino de um fluxo.
    void setTarget(Flow *f1, System *t) {
        pImpl_->setTarget(f1, t);
    }

    /// @brief Executa o modelo, realizando transferências de fluxo.
    /// @param inicial Tempo inicial da simulação.
    /// @param final Tempo final da simulação.
    /// @return Código de status da execução.
    int run(int inicial, int final) {
        return pImpl_->run(inicial, final);
    }
};

#endif // MODELIMPL_H
