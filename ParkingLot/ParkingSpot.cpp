#include "ParkingSpot.hpp"
ParkingSpot::ParkingSpot(int spotNumber, Type type)
    : m_spotNumber(spotNumber), m_spotType(type)
{
}

int ParkingSpot::getSpotNumber() const
{
    return m_spotNumber;
}

ParkingSpot::Type ParkingSpot::getType() const
{
    return m_spotType;
}

Vehicle* ParkingSpot::getVehicle() const
{
    if (m_occupiedByVehicle)
    {
        return m_occupiedByVehicle;
    }
    return nullptr;
}

bool ParkingSpot::isAvailable() const
{
    return m_occupiedByVehicle == nullptr;
}

bool ParkingSpot::canFitVehicle(const Vehicle* vehicle) const
{
    if (!vehicle)
    {
        return false;
    }

    switch (vehicle->m_type)
    {
    case Vehicle::Type::Car:
        return m_spotType == Type::Regular;
    case Vehicle::Type::Motorcycle:
        return m_spotType == Type::Compact;
    case Vehicle::Type::Truck:
        return m_spotType == Type::Large;
    }
    return false;
}

bool ParkingSpot::parkVehicle(Vehicle* vehicle)
{
    if (canFitVehicle(vehicle) && isAvailable())
    {
        m_occupiedByVehicle = vehicle;
        return true;
    }
    return false;
}

Vehicle* ParkingSpot::removeVehicle()
{
    if (m_occupiedByVehicle)
    {
        Vehicle* vehicle = m_occupiedByVehicle;
        m_occupiedByVehicle = nullptr;
        return vehicle;
    }
    return nullptr;
}