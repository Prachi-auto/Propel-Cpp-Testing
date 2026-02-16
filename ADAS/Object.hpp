#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <cstdint>
#include "ADAS/LaneId.hpp"

using ObjectId = std::uint32_t;

struct Position
{
    float m_x{};
    float m_y{};
};

struct Velocity
{
    float m_x{};
    float m_y{};
};

struct Acceleration
{
    float m_x{};
    float m_y{};
};

struct Object
{
    ObjectId m_id{};
    Position m_position{};
    Velocity m_velocity{};
    Acceleration m_acceleration{};
    LaneId m_lane{LaneId::Unknown};
};

#endif // OBJECT_HPP