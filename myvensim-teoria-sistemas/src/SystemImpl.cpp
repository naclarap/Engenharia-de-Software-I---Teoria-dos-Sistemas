#include "SystemImpl.h"

SystemImpl::SystemImpl()
{
    name = "NULL";
    value = 0;
}

SystemImpl::SystemImpl(System &rhs)
{
    name = rhs.getName();
    value = rhs.getValue();
};

SystemImpl::SystemImpl(const string name, double value) : name(name), value(value) {}

SystemImpl::SystemImpl(const string name) : name(name) {}

SystemImpl::SystemImpl(double value) : value(value) {}

string SystemImpl::getName() const
{
    return name;
};

void SystemImpl::setName(const string newName)
{
    name = newName;
}

double SystemImpl::getValue() const
{
    return value;
}

void SystemImpl::setValue(double newValue)
{
    value = newValue;
}


SystemImpl::~SystemImpl() {}