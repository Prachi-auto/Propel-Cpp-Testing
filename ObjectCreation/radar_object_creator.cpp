#include <iostream>
#include <string>

#include "ObjectFusion/radar_object.pb.h"

int main()
{
    RadarObject object;
    object.set_object_id(1);
    object.set_position_x(50.0);
    object.set_position_y(0.0);
    object.set_velocity_x(10.0);
    object.set_velocity_z(0.0);
    object.set_length(4.5);
    object.set_width(2.0);
    object.set_object_type(ObjectType::BIKE);

    // Serialize the RadarObject message to a binary format.
    std::string serialized_object;
    object.SerializeToString(&serialized_object);

    // Deserialize the RadarObject message from the binary format.
    RadarObject deserialized_object;
    deserialized_object.ParseFromString(serialized_object);

    // Print the deserialized RadarObject message.
    std::cout << "Object ID: " << deserialized_object.object_id() << std::endl;
    std::cout << "Position X: " << deserialized_object.position_x() << std::endl;
    std::cout << "Position Y: " << deserialized_object.position_y() << std::endl;
    std::cout << "Velocity X: " << deserialized_object.velocity_x() << std::endl;
    std::cout << "Velocity Y: " << deserialized_object.velocity_y() << std::endl;
    std::cout << "Length: " << deserialized_object.length() << std::endl;
    std::cout << "Width: " << deserialized_object.width() << std::endl;
    std::cout << "Object Type: " << deserialized_object.object_type() << std::endl;
    std::cout << "Serialized size: " << serialized_object.size() << " bytes" << std::endl;
    
    return 0;
}