#ifndef RELEVANT_OBJECTS_AEB_HPP
#define RELEVANT_OBJECTS_AEB_HPP

#include "Object.hpp"
#include <vector>

class RelevantObjectsAeb
{
public:
    using ObjectList = std::vector<Object>;
    
    Object getTargetObject(const ObjectList& allObjects);

private:
    bool isRelevantForAeb(const Object& object);
};

#endif