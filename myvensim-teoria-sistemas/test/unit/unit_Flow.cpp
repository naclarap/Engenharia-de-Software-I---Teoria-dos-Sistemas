#include "unit_Flow.h"

void unit_Flow_constructor()
{
    System *system1 = new SystemHandle();
    System *system2 = new SystemHandle();

    // exponential
    Flow *flowExp1 = new FlowHandle<ExponentialFlow>();
    assert(flowExp1->getName() == "");
    assert(flowExp1->getSource() == NULL);
    assert(flowExp1->getTarget() == NULL);

    Flow *flowExp2 = new FlowHandle<ExponentialFlow>("test", system1, system2);
    assert(flowExp2->getName() == "test");
    assert(flowExp2->getSource() == system1);
    assert(flowExp2->getTarget() == system2);

    Flow *flowExp3 = new FlowHandle<ExponentialFlow>(*flowExp2);

    // logistic
    Flow *flowLogist1 = new FlowHandle<LogisticFlow>();
    assert(flowLogist1->getName() == "");
    assert(flowLogist1->getSource() == NULL);
    assert(flowLogist1->getTarget() == NULL);

    Flow *flowLogist2 = new FlowHandle<LogisticFlow>("test", system1, system2);
    assert(flowLogist2->getName() == "test");
    assert(flowLogist2->getSource() == system1);
    assert(flowLogist2->getTarget() == system2);

    Flow *flowLogist3 = new FlowHandle<LogisticFlow>(*flowLogist2);

    delete system1;
    delete system2;
    delete flowExp1;
    delete flowExp2;
    delete flowExp3;
    delete flowLogist1;
    delete flowLogist2;
    delete flowLogist3;
}

void unit_Flow_destructor() {}

void unit_Flow_getName()
{
    System *system1 = new SystemHandle();
    System *system2 = new SystemHandle();

    // exponential
    Flow *flowExp1 = new FlowHandle<ExponentialFlow>("test", system1, system2);
    assert(flowExp1->getName() == "test");

    // logistic
    Flow *flowLogist1 = new FlowHandle<LogisticFlow>("test", system1, system2);
    assert(flowLogist1->getName() == "test");

    delete system1;
    delete system2;
    delete flowExp1;
    delete flowLogist1;
}

void unit_Flow_setName()
{
    // exponential
    Flow *flowExp1 = new FlowHandle<ExponentialFlow>();
    flowExp1->setName("test");
    assert(flowExp1->getName() == "test");

    // logistic
    Flow *flowLogist1 = new FlowHandle<LogisticFlow>();
    flowLogist1->setName("test");
    assert(flowLogist1->getName() == "test");

    delete (ExponentialFlow *)flowExp1;
    delete (LogisticFlow *)flowLogist1;
}

void unit_Flow_getSource()
{
    System *system1 = new SystemHandle();
    System *system2 = new SystemHandle();

    // exponential
    Flow *flowExp1 = new FlowHandle<ExponentialFlow>("test", system1, system2);
    assert(flowExp1->getSource() == system1);

    // logistic
    Flow *flowLogist1 = new FlowHandle<LogisticFlow>("test", system1, system2);
    assert(flowLogist1->getSource() == system1);

    delete system1;
    delete system2;
    delete flowExp1;
    delete flowLogist1;
}

void unit_Flow_setSource()
{
    System *system1 = new SystemHandle();
    System *system2 = new SystemHandle();
    System *system3 = new SystemHandle();

    // exponential
    Flow *flowExp1 = new FlowHandle<ExponentialFlow>("teste", system1, system2);
    flowExp1->setSource(system3);
    assert(flowExp1->getSource() == system3);

    // logistic
    Flow *flowLogist1 = new FlowHandle<LogisticFlow>("teste", system1, system2);
    flowLogist1->setSource(system3);
    assert(flowLogist1->getSource() == system3);

    delete system1;
    delete system2;
    delete flowExp1;
    delete flowLogist1;
}

void unit_Flow_getTarget()
{
    System *system1 = new SystemHandle();
    System *system2 = new SystemHandle();

    // exponential
    Flow *flowExp1 = new FlowHandle<ExponentialFlow>("teste", system1, system2);
    assert(flowExp1->getTarget() == system2);

    // logistic
    Flow *flowLogist1 = new FlowHandle<LogisticFlow>("teste", system1, system2);
    assert(flowLogist1->getTarget() == system2);

    delete system1;
    delete system2;
    delete flowExp1;
    delete flowLogist1;
}

void unit_Flow_setTarget()
{
    System *system1 = new SystemHandle();
    System *system2 = new SystemHandle();
    System *system3 = new SystemHandle();

    // exponential
    Flow *flowExp1 = new FlowHandle<ExponentialFlow>("test", system1, system2);
    flowExp1->setTarget(system3);
    assert(flowExp1->getTarget() == system3);

    // logistic
    Flow *flowLogist1 = new FlowHandle<LogisticFlow>("test", system1, system2);
    flowLogist1->setTarget(system3);
    assert(flowLogist1->getTarget() == system3);

    delete system1;
    delete system2;
    delete flowExp1;
    delete flowLogist1;
}

void run_unit_test_Flow()
{
    unit_Flow_constructor();
    unit_Flow_destructor();
    unit_Flow_getName();
    unit_Flow_setName();
    unit_Flow_getSource();
    unit_Flow_setSource();
    unit_Flow_getTarget();
    unit_Flow_setTarget();
}