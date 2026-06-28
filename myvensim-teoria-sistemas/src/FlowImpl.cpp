#include "FlowImpl.h"

FlowImpl::FlowImpl()
{
    name = "NULL";
    source = NULL;
    target = NULL;
}

FlowImpl::FlowImpl(Flow &rhs)
{
    name = rhs.getName();
    source = rhs.getSource();
    target = rhs.getTarget();
}

FlowImpl::FlowImpl(const string name, System *Source, System *target) : name(name), source(Source), target(target){};

FlowImpl::~FlowImpl(){};

string FlowImpl::getName() const{
    return name;
}

void FlowImpl::setName(const string newName){
    name = newName;
}

System *FlowImpl::getSource() const{
    return source;
}

void FlowImpl::setSource(System *newSource){
    source = newSource;
}

System *FlowImpl::getTarget() const{
    return target;
}

void FlowImpl::setTarget(System *newTarget){
    target = newTarget;
}

