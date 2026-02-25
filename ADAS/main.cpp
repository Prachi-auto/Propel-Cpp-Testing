#include "ADAS/RelevantObjectsAeb.hpp"
#include "ADAS/RelevantObjectsAcc.hpp"
#include "ADAS/ObjectList.hpp"
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

    objects[0] = ObjectBuilder().withId(1).withPosition(10.0f).inLane(LaneId::Center).build();
    objects[1] = ObjectBuilder().withId(2).withPosition(20.0f).inLane(LaneId::Left).build();
    objects[2] = ObjectBuilder().withId(3).withPosition(30.0f).inLane(LaneId::Right).build();
    objects[3] = ObjectBuilder().withId(4).withPosition(40.0f).inLane(LaneId::Center).build();
    objects[4] = ObjectBuilder().withId(5).withPosition(60.0f).inLane(LaneId::Center).build();
    objects[5] = ObjectBuilder().withId(6).withPosition(70.0f).inLane(LaneId::Right).build();

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
