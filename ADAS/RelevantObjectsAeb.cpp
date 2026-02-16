#include "RelevantObjectsAeb.hpp"

Object RelevantObjectsAeb::getTargetObject(const ObjectList& allObjects)
{
    Object* targetObject = nullptr;
    // Filter objects relevant for AEB
    for (const auto& object : allObjects)
    {
        if (isRelevantForAeb(object))
        {
            if(targetObject == nullptr || object.m_position.m_x < targetObject->m_position.m_x)
            {
                targetObject = const_cast<Object*>(&object);
            }
        }
    }
    return targetObject ? *targetObject : Object{};
}

bool RelevantObjectsAeb::isRelevantForAeb(const Object& object)
{
    const bool is_in_same_lane = (object.m_lane == LaneId::Center);
    const bool is_within_range_longitudinally = object.m_position.m_x < 50.0f;

    return is_in_same_lane && is_within_range_longitudinally;
}