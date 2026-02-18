#ifndef RELEVANT_OBJECTS_ACC_HPP
#define RELEVANT_OBJECTS_ACC_HPP

#include "ADAS/Object.hpp"
#include "ADAS/ObjectList.hpp"
#include <optional>

class RelevantObjectsAcc
{
public:
    /// @brief Chooses the ACC target object from the detected set.  
    /// @param all_objects Detected objects.
    /// @param ego_lane Ego lane index
    /// @return The nearest relevant object in the ego lane, or a empty optional
    static std::optional<Object> getTargetObject(const ObjectList& all_objects, const LaneId ego_lane);

private:
    /// @brief returns if the given object is relevant for ACC.
    /// @param object object to check if it's relevant in ego lane
    /// @param ego_lane Ego lane index
    /// @return true if object is relevant for ACC else false.
    static bool isRelevantForAcc(const Object& object, const LaneId ego_lane);
};

#endif
