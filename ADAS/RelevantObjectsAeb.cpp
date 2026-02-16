#include "RelevantObjectsAeb.hpp"

std::optional<Object> RelevantObjectsAeb::getTargetObject(const ObjectList& allObjects)
{
    std::optional<Object> targetObject{};
    // Filter objects relevant for AEB
    for (const auto& object : allObjects)
    {
        if (isRelevantForAeb(object))
        {
            if(!targetObject || object.m_position.m_x < targetObject->m_position.m_x)
            {
                targetObject = object;
            }
        }
    }
    return targetObject;
}

bool RelevantObjectsAeb::isRelevantForAeb(const Object& object)
{
    const bool is_in_same_lane = (object.m_lane == LaneId::Center);
    const bool is_within_range_longitudinally = object.m_position.m_x < 50.0f;

    return is_in_same_lane && is_within_range_longitudinally;
}