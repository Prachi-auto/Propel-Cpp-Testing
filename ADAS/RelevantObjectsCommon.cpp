#include "ADAS/RelevantObjectsCommon.hpp"

RelevantObjectsCommon::RelevantObjectsCommon(float max_longitudinal_range_meters)
    : m_max_longitudinal_range_meters(max_longitudinal_range_meters)
{
}

std::optional<Object> RelevantObjectsCommon::getTargetObject(const ObjectList& all_objects, const LaneId ego_lane) const
{
    std::optional<Object> target_object{};
    // Filter objects relevant for AEB
    for (const auto& object : all_objects)
    {
        if (isRelevant(object, ego_lane))
        {
            if (!target_object || object.m_position.m_x < target_object->m_position.m_x)
            {
                target_object = object;
            }
        }
    }
    return target_object;
}

bool RelevantObjectsCommon::isRelevant(const Object& object, const LaneId ego_lane) const
{
    const bool is_in_same_lane = (object.m_lane == ego_lane);

    const bool is_within_range_longitudinally = (object.m_position.m_x > 0.0f) && (object.m_position.m_x < m_max_longitudinal_range_meters);

    return is_in_same_lane && is_within_range_longitudinally;
}
