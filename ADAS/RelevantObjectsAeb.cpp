#include "RelevantObjectsAeb.hpp"

std::optional<Object> RelevantObjectsAeb::getTargetObject(const ObjectList& all_objects, const LaneId ego_lane)
{
    std::optional<Object> target_object{};
    // Filter objects relevant for AEB
    for (const auto& object : all_objects)
    {
        if (isRelevantForAeb(object, ego_lane))
        {
            if (!target_object || object.m_position.m_x < target_object->m_position.m_x)
            {
                target_object = object;
            }
        }
    }
    return target_object;
}

bool RelevantObjectsAeb::isRelevantForAeb(const Object& object, const LaneId ego_lane)
{
    const bool is_in_same_lane = (object.m_lane == ego_lane);
    static constexpr float kMaxLongitudinalRangeMeters = 50.0f;
    const bool is_within_range_longitudinally = (object.m_position.m_x > 0.0f) && (object.m_position.m_x < kMaxLongitudinalRangeMeters);

    return is_in_same_lane && is_within_range_longitudinally;
}