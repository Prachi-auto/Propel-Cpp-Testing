
#ifndef RELEVANT_OBJECTS_AEB_HPP
#define RELEVANT_OBJECTS_AEB_HPP

#include "ADAS/Object.hpp"
#include "ADAS/ObjectList.hpp"
#include <optional>

class RelevantObjectsAeb
{
public:

    /// @brief Chooses the AEB target object from the detected set.  
    /// @param all_objects Detected objects.
    /// @param ego_lane Ego Lane Index.
    /// @return The nearest relevant object in the ego lane, or a empty optional
    static std::optional<Object> getTargetObject(const ObjectList& all_objects, const LaneId ego_lane);

private:
    /// @brief returns if the given object is relevant for aeb.
    /// @param object object to check if it's relevant in ego lane
    /// @param ego_lane Ego Lane Index.
    /// @return true if object is relevant for aeb else false.
    static bool isRelevantForAeb(const Object& object, const LaneId ego_lane);
};

#endif
