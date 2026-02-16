
#ifndef RELEVANT_OBJECTS_AEB_HPP
#define RELEVANT_OBJECTS_AEB_HPP

#include "Object.hpp"
#include <vector>
#include <optional>

class RelevantObjectsAeb
{
public:

    /// @brief Chooses the AEB target object from the detected set.  
    /// @param allObjects Detected objects.
    /// @return The nearest relevant object in the ego lane, or a empty optional
    static std::optional<Object> getTargetObject(const ObjectList& allObjects);

private:
    /// @brief returns if the given object is relevant for aeb.
    /// @param object object to check if it's relevant in ego lane
    /// @return true if object is relevant for aeb else false.
    static bool isRelevantForAeb(const Object& object);
};

#endif
