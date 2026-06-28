#include "ModelImpl.h"
#include "SystemImpl.h"
#include "FlowImpl.h"
vector<Model *> ModelImpl::models;
ModelImpl::ModelImpl()
{
    name = "NULL";
    flow_list.clear();
    system_list.clear();
}

ModelImpl::ModelImpl(const string name) : name(name) {}

ModelImpl::ModelImpl(ModelImpl &rhs)
{
    if (&rhs == this)
        return;

    name = rhs.getName();
}

ModelImpl::~ModelImpl()
{
    for(Model::itSystem it = getSystemBegin(); it < getSystemEnd(); it++)
        delete *it;

    for(Model::itFlow it = getFlowBegin(); it < getFlowEnd(); it++)
        delete *it;

}

string ModelImpl::getName() const
{
    return name;
}

void ModelImpl::setName(const string newName)
{
    name = newName;
}

void ModelImpl :: eraseModel(Model::itModel m){
    models.erase(m);
}
void ModelImpl::setSource(Flow* flow, System* system)
{
    flow->setSource(system);
}

void ModelImpl::setTarget(Flow* flow, System* system)
{
    flow->setTarget(system);
}

ModelImpl::itFlow ModelImpl::getFlowBegin()
{
    return flow_list.begin();
}

ModelImpl::itFlow ModelImpl::getFlowEnd()
{
    return flow_list.end();
}

int ModelImpl::getFlowSize()
{
    return flow_list.size();
}

ModelImpl::itSystem ModelImpl::getSystemBegin()
{
    return system_list.begin();
}

ModelImpl::itSystem ModelImpl::getSystemEnd()
{
    return system_list.end();
}

int ModelImpl::getSystemSize()
{
    return system_list.size();
}

ModelImpl::itModel ModelImpl::getModelbegin(){
    return models.begin();
}

ModelImpl::itModel ModelImpl::getModelEnd(){
    return models.end();
}

int Model :: getModelsize(){
    return ModelImpl::getModelsize();
}

int ModelImpl :: getModelsize(){
    return models.size();
}
void ModelImpl::add(System *subSystem)
{
    system_list.push_back(subSystem);
}

void ModelImpl::add(Flow *flow)
{
    flow_list.push_back(flow);
}

bool ModelImpl::remove(System *obj)
{
    for (auto thisystem = system_list.begin(); thisystem != system_list.end(); thisystem++)
    {
        if (*thisystem == obj)
        {
            system_list.erase(thisystem);
            return true;
        }
    }
    return false;
}

bool ModelImpl::remove(Flow *obj)
{
    for (auto thisFlows = flow_list.begin(); thisFlows != flow_list.end(); thisFlows++)
    {
        if (*thisFlows == obj)
        {
            flow_list.erase(thisFlows);
            return true;
        }
    }
    return false;
}

ModelImpl& ModelImpl::operator=(const ModelImpl &rhs)
{
    if (this != &rhs)
    {
        this->flow_list.clear();
        this->system_list.clear();
        this->flow_list.insert(this->flow_list.begin(), rhs.flow_list.begin(), rhs.flow_list.end());
        this->system_list.insert(this->system_list.begin(), rhs.system_list.begin(), rhs.system_list.end());
    }
    return *this;
}

void ModelImpl::clear()
{
    name = "NULL";
    flow_list.clear();
    system_list.clear();
}

int ModelImpl::run(int ini_time, int fin_time)
{
    vector<Flow *>::iterator flow_iterator;

    System *source_system;
    System *target_system;

    vector<double> flow_values;
    const double flow_init_value = 0.0;

    for (int i = 0; i < int(flow_list.size()); i++)
        flow_values.push_back(flow_init_value);
    
    int i, j;
    for (int time_count = ini_time; time_count < fin_time; time_count++)
    {
        i = 0;
        flow_iterator = flow_list.begin();
        while (i < int(flow_list.size()))
        {
            flow_values[i] = (*flow_iterator)->execute();
            flow_iterator++;
            i++;
        }

        j = 0;
        while (j < int(flow_list.size()))
        {
            source_system = flow_list[j]->getSource();
            source_system->setValue(source_system->getValue() - flow_values[j]);

            target_system = flow_list[j]->getTarget();
            target_system->setValue(target_system->getValue() + flow_values[j]);
            j++;
        }
    }
    return 1;
}

Model* ModelImpl :: createModel(string name){
    Model * model = new ModelHandle(name);
    models.push_back(model);
    return model;
}

Model* Model :: createModel(string name_m)
{
    return ModelImpl::createModel(name_m);
}

System *ModelImpl::createSystem(string name_s, double value_s)
{
    System *sys = new SystemHandle(name_s, value_s);
    add(sys);
    return sys;
}