#include <vector>
#include <map>
#include <string>
#include "ParkingSpot.hpp"

using LicensePlate = std::string;
class ParkingLot
{
public:
    ParkingLot(int numCompact, int numRegular, int numLarge);
    ~ParkingLot();
    
    int getCapacity() const;
    int getAvailableSpots() const;
    
    bool parkVehicle(Vehicle* vehicle);
    Vehicle* removeVehicle(const LicensePlate& licensePlate);
    ParkingSpot* findVehicle(const LicensePlate& licensePlate) const;

private:
    ParkingSpot* findAvailableSpot(const Vehicle* vehicle) const;

    std::vector<ParkingSpot*> spots;
    std::map<LicensePlate, ParkingSpot*> occupiedSpots;
    int capacity;
    int availableSpots;
};
