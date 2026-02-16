#ifndef RELEVANT_OBJECTS_ACC_HPP
#define RELEVANT_OBJECTS_ACC_HPP

#include "Object.hpp"
#include <vector>
#include <optional>

class RelevantObjectsAcc
{
public:
    /// @brief Chooses the ACC target object from the detected set.  
    /// @param allObjects Detected objects.
    /// @return The nearest relevant object in the ego lane, or a empty optional
    static std::optional<Object> getTargetObject(const ObjectList& allObjects);

private:
    /// @brief returns if the given object is relevant for ACC.
    /// @param object object to check if it's relevant in ego lane
    /// @return true if object is relevant for ACC else false.
    static bool isRelevantForAcc(const Object& object);
};

#endif