#ifndef MODEL_H
#define MODEL_H

#include <cstring>
#include <ostream>
#include <vector>

#include "FlowImpl.h"
#include "Flow.h"
#include "System.h"

/// @class Model
/// @brief Representa um modelo que integra fluxos e sistemas.
///
/// O modelo é responsável por armazenar sistemas e fluxos, 
/// executar simulações e fornecer mecanismos de criação e gerenciamento 
/// desses componentes.
class Model {
public:
    /// @brief Destrutor virtual.
    virtual ~Model() {}

    /// @brief Iterador para contêiner de fluxos.
    typedef typename vector<Flow *>::iterator itFlow;
    /// @brief Iterador para contêiner de sistemas.
    typedef typename vector<System *>::iterator itSystem;
    /// @brief Iterador para contêiner de modelos.
    typedef typename vector<Model *>::iterator itModel;

    /// @brief Define o sistema de origem de um fluxo.
    /// @param fluxo Ponteiro para o fluxo.
    /// @param sistema Ponteiro para o sistema de origem.
    virtual void setSource(Flow *flow, System *system) = 0;

    /// @brief Define o sistema de destino de um fluxo.
    /// @param fluxo Ponteiro para o fluxo.
    /// @param sistema Ponteiro para o sistema de destino.
    virtual void setTarget(Flow *flow, System *system) = 0;

    /// @brief Retorna o nome do modelo.
    /// @return Nome do modelo.
    virtual string getName() const = 0;

    /// @brief Define o nome do modelo.
    /// @param name Novo nome do modelo.
    virtual void setName(const string name) = 0;

    /// @brief Retorna o iterador para o início do vetor de fluxos.
    virtual itFlow getFlowBegin() = 0;

    /// @brief Retorna o iterador para o fim do vetor de fluxos.
    virtual itFlow getFlowEnd() = 0;

    /// @brief Retorna o número de fluxos no modelo.
    virtual int getFlowSize() = 0;

    /// @brief Retorna o iterador para o início do vetor de sistemas.
    virtual itSystem getSystemBegin() = 0;

    /// @brief Retorna o iterador para o fim do vetor de sistemas.
    virtual itSystem getSystemEnd() = 0;

    /// @brief Retorna o número de sistemas no modelo.
    virtual int getSystemSize() = 0;

    /// @brief Retorna o iterador para o início do vetor de modelos.
    virtual itModel getModelbegin() = 0;

    /// @brief Retorna o iterador para o fim do vetor de modelos.
    virtual itModel getModelEnd() = 0;

    /// @brief Retorna o número total de modelos criados.
    static int getModelsize();

    /// @brief Remove um sistema do modelo.
    /// @param s Ponteiro para o sistema a ser removido.
    /// @return true se removido com sucesso.
    virtual bool remove(System *s) = 0;

    /// @brief Remove um fluxo do modelo.
    /// @param f Ponteiro para o fluxo a ser removido.
    /// @return true se removido com sucesso.
    virtual bool remove(Flow *f) = 0;

    /// @brief Remove todos os sistemas e fluxos do modelo.
    virtual void clear() = 0;

    /// @brief Cria uma instância de modelo com o nome especificado.
    /// @param name Nome do novo modelo.
    /// @return Ponteiro para o modelo criado.
    static Model *createModel(string name);

    /// @brief Cria um sistema e o adiciona ao modelo.
    /// @param name_s Nome do sistema.
    /// @param value_s Valor inicial do sistema.
    /// @return Ponteiro para o sistema criado.
    virtual System *createSystem(string name_s, double value_s) = 0;

    /// @brief Cria um fluxo do tipo especificado e o adiciona ao modelo.
    /// @tparam T Tipo de fluxo a ser criado.
    /// @param name_f Nome do fluxo.
    /// @param source_f Sistema de origem.
    /// @param destiny_f Sistema de destino.
    /// @return Ponteiro para o fluxo criado.
    template <typename T>
    Flow *createFlow(string name_f, System *source_f, System *target_f) {
        Flow *f = new FlowHandle<T>(name_f, source_f, target_f);
        add(f);
        return f;
    }

    /// @brief Executa a simulação do modelo em um intervalo de tempo.
    /// @param ini_time Tempo inicial da simulação.
    /// @param fin_time Tempo final da simulação.
    /// @return Código de status da simulação.
    virtual int run(int ini_time, int fin_time) = 0;

    /// @brief Adiciona um sistema ao modelo.
    /// @param s Ponteiro para o sistema a ser adicionado.
    virtual void add(System *s) = 0;

    /// @brief Adiciona um fluxo ao modelo.
    /// @param f Ponteiro para o fluxo a ser adicionado.
    virtual void add(Flow *f) = 0;
};

#endif // MODEL_H
