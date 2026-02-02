#include <string>

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

    std::string m_licensePlate; 
    Type m_type;
};