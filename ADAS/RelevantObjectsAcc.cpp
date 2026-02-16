#include "RelevantObjectsAcc.hpp"

Object RelevantObjectsAcc::getTargetObject(const ObjectList& allObjects)
{
    const Object* targetObject = nullptr;
    // Filter objects relevant for ACC
    for (const auto& object : allObjects)
    {
        if (isRelevantForAcc(object))
        {
            if(targetObject == nullptr || object.m_position.m_x < targetObject->m_position.m_x)
            {
                targetObject = &object;
            }
        }
    }
    return targetObject ? *targetObject : Object{};
}

bool RelevantObjectsAcc::isRelevantForAcc(const Object& object)
{
    const bool is_in_same_lane = (object.m_lane == LaneId::Center);
    const bool is_within_range_longitudinally = object.m_position.m_x < 50.0f;

    return is_in_same_lane && is_within_range_longitudinally;
}
