#include "ADAS/RelevantObjectsAeb.hpp"
#include "ADAS/RelevantObjectsAcc.hpp"
#include "ADAS/ObjectList.hpp"
#include "ADAS/RelevantObjectsAcc.hpp"
#include "ADAS/Constants.hpp"
#include <iostream>

Object CreateObject(ObjectId id, float x_position, LaneId lane)
{
    Object object{};
    object.m_id = id;
    object.m_position.m_x = x_position;
    object.m_lane = lane;
    return object;
}

ObjectList CreateObjects()
{
    ObjectList objects{};

    objects[0] = CreateObject(1, 10.0f, LaneId::Center);
    objects[1] = CreateObject(2, 20.0f, LaneId::Left);
    objects[2] = CreateObject(3, 30.0f, LaneId::Right);
    objects[3] = CreateObject(4, 40.0f, LaneId::Center);
    objects[4] = CreateObject(5, 60.0f, LaneId::Center);
    objects[5] = CreateObject(6, 70.0f, LaneId::Right);

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
    RelevantObjectsAcc relevant_objects_acc(ObjectSelectionConstants::m_maximum_longitudinal_range_meters);
    RelevantObjectsAeb relevant_objects_aeb(ObjectSelectionConstants::m_maximum_longitudinal_range_meters);
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
