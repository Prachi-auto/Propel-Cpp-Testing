#ifndef OBJECT_BUILDER_HPP
#define OBJECT_BUILDER_HPP

#include "ADAS/Object.hpp"

class ObjectBuilder
{
public:
    ObjectBuilder() = default;

    ObjectBuilder& withId(ObjectId id)
    {
        m_object.m_id = id;
        return *this;
    }

    ObjectBuilder& withPosition(float x, float y = 0.0f)
    {
        m_object.m_position.m_x = x;
        m_object.m_position.m_y = y;
        return *this;
    }

    ObjectBuilder& withVelocity(float x = 0.0f, float y = 0.0f)
    {
        m_object.m_velocity.m_x = x;
        m_object.m_velocity.m_y = y;
        return *this;
    }

    ObjectBuilder& withAcceleration(float x = 0.0f, float y = 0.0f)
    {
        m_object.m_acceleration.m_x = x;
        m_object.m_acceleration.m_y = y;
        return *this;
    }

    ObjectBuilder& inLane(LaneId lane)
    {
        m_object.m_lane = lane;
        return *this;
    }

    Object build() const { return m_object; }

private:
    Object m_object{};
};

#endif
