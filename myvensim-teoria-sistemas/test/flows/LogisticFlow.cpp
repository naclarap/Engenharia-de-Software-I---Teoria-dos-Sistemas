#include "LogisticFlow.h"

LogisticFlow::LogisticFlow() : FlowImpl(){}


LogisticFlow::LogisticFlow(Flow &obj) : FlowImpl(obj){}


LogisticFlow::LogisticFlow(const string name, System *origin, System *target) : FlowImpl(name, origin, target){};
LogisticFlow::~LogisticFlow() {}

double LogisticFlow::execute()
{
    return ((0.01 * getTarget()->getValue()) * (1 - getTarget()->getValue() / 70));
};