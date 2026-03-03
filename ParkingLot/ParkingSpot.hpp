#include <cstdint>
#include "Vehicle.hpp"

using ParkingSpotId = std::uint8_t;

struct ParkingSpot
{
    enum class Type : std::uint8_t
    {
        Compact,
        Regular,
        Large
    };
    ParkingSpot(ParkingSpotId spotNumber, Type type);

    int getSpotNumber();
    Type getType() const;
    Vehicle* getVehicle() const;
    bool isAvailable() const;

    bool canFitVehicle(const Vehicle* vehicle) const;
    bool parkVehicle(Vehicle* vehicle);
    Vehicle* removeVehicle();

private:
    ParkingSpotId m_spotNumber;
    Vehicle* m_occupiedByVehicle{nullptr};
    Type m_spotType{Type::Regular};
};