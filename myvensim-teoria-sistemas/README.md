# myVensim — Simulador de Dinâmica de Sistemas

Biblioteca em C++ que implementa, do zero, os conceitos centrais da **Teoria Geral de Sistemas** e da modelagem de dinâmica de sistemas (no estilo do software Vensim): sistemas (estoques), fluxos e modelos que conectam os dois e simulam sua evolução no tempo.

Projeto desenvolvido de forma incremental ao longo de 6 sprints na disciplina de Engenharia de Software (UFOP).

## Conceito

> O projeto gira em torno da teoria de sistemas e é composto por três classes principais: `Model`, `System` e `Flow`. A classe `Model` funciona como um container para instâncias de `System` e `Flow`, e gerencia a execução de toda a simulação pelo método `run`. A classe `Flow` conecta dois sistemas e recebe funções matemáticas que definem a taxa de transferência entre eles. A classe `System` armazena e gerencia valores numéricos.

## Como usar a API

```cpp
class Exponential_Flow : public Flow {
public:
    Exponential_Flow(const string name, System *origin, System *target);
    virtual double execute();
};

double Exponential_Flow::execute() {
    return getOrigin()->getValue() * 0.05;
}

Model *model = new Model();
System *system1 = new System("s1", 50.0);
System *system2 = new System("s2", 0.0);
Flow *flow = new FlowHandle<Exponential_Flow>("Exponential", system1, system2);

model->setName("Exponential System");
model->add(system1);
model->add(system2);
model->add(flow);

model->run(1, 100); // simula 100 passos
model->clear();
```

Novos comportamentos de fluxo são adicionados criando subclasses de `Flow` e implementando o método `execute()` com a equação desejada — o projeto já inclui exemplos de crescimento **exponencial** e **logístico** (`test/flows`).

## Estrutura

```
src/        # Model, System, Flow e suas implementações
test/unit/  # testes unitários por classe
test/funcional/  # testes funcionais de ponta a ponta
test/flows/      # implementações de exemplo (Exponential, Logistic)
```

## Tecnologias

- **C++**
- Testes unitários e funcionais (suite própria)
- Documentação técnica gerada com **Doxygen**

## Metodologia

Projeto construído em sprints, com testes unitários e funcionais escritos a cada incremento e documentação Doxygen mantida e atualizada ao longo do desenvolvimento.
