#include "ExponentialFlow.h"

ExponentialFlow::ExponentialFlow():FlowImpl(){}


ExponentialFlow::ExponentialFlow(Flow &obj) : FlowImpl(obj){}


ExponentialFlow::ExponentialFlow(const string name, System *origin, System *target) : FlowImpl(name, origin, target){};
ExponentialFlow::~ExponentialFlow() {}

double ExponentialFlow::execute()
{
    return getSource()->getValue() * 0.01;
};