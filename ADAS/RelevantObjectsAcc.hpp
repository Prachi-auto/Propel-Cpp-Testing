#ifndef RELEVANT_OBJECTS_ACC_HPP
#define RELEVANT_OBJECTS_ACC_HPP

#include "Object.hpp"
#include <vector>

class RelevantObjectsAcc
{
public:
    using ObjectList = std::vector<Object>;
    
    Object getTargetObject(const ObjectList& allObjects);

private:
    bool isRelevantForAcc(const Object& object);
};

#endif