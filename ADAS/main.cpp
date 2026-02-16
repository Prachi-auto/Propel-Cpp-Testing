#include "RelevantObjectsAeb.hpp"
#include "RelevantObjectsAcc.hpp"
#include "ObjectList.hpp"
#include <iostream>

void CreateObject(Object& object, ObjectId id, float x_position, LaneId lane)
{
    object.m_id = id;
    object.m_position.m_x = x_position;
    object.m_position.m_y = 0.0f;
    object.m_velocity.m_x = 0.0f;
    object.m_velocity.m_y = 0.0f;
    object.m_acceleration.m_x = 0.0f;
    object.m_acceleration.m_y = 0.0f;
    object.m_lane = lane;
}

ObjectList CreateObjects()
{
    ObjectList objects(5);

    CreateObject(objects[0], 1, 10.0f, LaneId::Center);
    CreateObject(objects[1], 2, 20.0f, LaneId::Left);
    CreateObject(objects[2], 3, 30.0f, LaneId::Right);
    CreateObject(objects[3], 4, 40.0f, LaneId::Center);
    CreateObject(objects[4], 5, 60.0f, LaneId::Center);

    return objects;
}

void PrintObject(const Object& object)
{
    std::cout << "Object ID: " << object.m_id 
              << ", Position: (" << object.m_position.m_x << ", " << object.m_position.m_y << ")"
              << ", Lane: " << static_cast<int>(object.m_lane) << std::endl;
}

int main()
{
    const auto allObjects = CreateObjects();

    auto targetAeb = RelevantObjectsAeb::getTargetObject(allObjects);
    auto targetAcc = RelevantObjectsAcc::getTargetObject(allObjects);

    if (targetAeb)
    {
        std::cout << "Target object for AEB:" << std::endl;
        PrintObject(*targetAeb);
    }
    if (targetAcc)
    {
        std::cout << "Target object for ACC:" << std::endl;
        PrintObject(*targetAcc);
    }

    return 0;
}