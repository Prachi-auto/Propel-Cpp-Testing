#include <string>
#include <cstdint>

struct Vehicle
{
    enum Type
    {
        Car,
        Motorcycle,
        Truck,
        unknown
    };

    Vehicle(const std::string& licensePlate, Type type)
        : m_licensePlate(licensePlate), m_type(type) {} 

    Type m_type;
    std::string m_licensePlate; 
};