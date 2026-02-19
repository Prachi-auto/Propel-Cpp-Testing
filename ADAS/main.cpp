#include "ADAS/RelevantObjectsAeb.hpp"
#include "ADAS/RelevantObjectsAcc.hpp"
#include "ADAS/ObjectList.hpp"
#include "RelevantObjectsAcc.hpp"
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
    const auto all_objects = CreateObjects();

    const LaneId ego_lane = LaneId::Center;
    RelevantObjectsAcc relevant_objects_acc(50.0f);
    RelevantObjectsAeb relevant_objects_aeb(50.0f);
    auto target_aeb = relevant_objects_aeb.getTargetObject(all_objects, ego_lane);
    auto target_acc = relevant_objects_acc.getTargetObject(all_objects, ego_lane);

    if (target_aeb)
    {
        std::cout << "Target object for AEB:" << std::endl;
        PrintObject(*target_aeb);
    }
    if (target_acc)
    {
        std::cout << "Target object for ACC:" << std::endl;
        PrintObject(*target_acc);
    }

    return 0;
}
