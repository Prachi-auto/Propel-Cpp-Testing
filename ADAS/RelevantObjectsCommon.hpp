
#ifndef RELEVANT_OBJECTS_COMMON_HPP
#define RELEVANT_OBJECTS_COMMON_HPP

#include "ADAS/Object.hpp"
#include "ADAS/ObjectList.hpp"
#include <optional>

class RelevantObjectsCommon
{
public:

    /// @brief Constructor for RelevantObjectsCommon.
    /// @param max_longitudinal_range_meters Maximum longitudinal range in meters to consider an object relevant.
    explicit RelevantObjectsCommon(float max_longitudinal_range_meters);

    /// @brief Chooses the AEB target object from the detected set.  
    /// @param all_objects Detected objects.
    /// @param ego_lane Ego Lane Index.
    /// @return The nearest relevant object in the ego lane, or a empty optional
    std::optional<Object> getTargetObject(const ObjectList& all_objects, const LaneId ego_lane) const;

private:
    /// @brief returns if the given object is relevant for aeb.
    /// @param object object to check if it's relevant in ego lane
    /// @param ego_lane Ego Lane Index.
    /// @return true if object is relevant for aeb else false.
    bool isRelevant(const Object& object, const LaneId ego_lane) const;

    /// @brief Maximum longitudinal range in meters to consider an object relevant.
    float m_max_longitudinal_range_meters;
};

#endif
