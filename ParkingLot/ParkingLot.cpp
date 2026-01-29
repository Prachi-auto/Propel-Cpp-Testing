#include "ParkingLot.hpp"

ParkingLot::ParkingLot(int numCompact, int numRegular, int numLarge) 
    : capacity(numCompact + numRegular + numLarge), availableSpots(capacity) {
    
    int spotNumber = 1;
    
    // Create compact spots
    for (int i = 0; i < numCompact; i++) {
        spots.push_back(new ParkingSpot(spotNumber++, ParkingSpot::Type::Compact));
    }
    
    // Create regular spots
    for (int i = 0; i < numRegular; i++) {
        spots.push_back(new ParkingSpot(spotNumber++, ParkingSpot::Type::Regular));
    }
    
    // Create large spots
    for (int i = 0; i < numLarge; i++) {
        spots.push_back(new ParkingSpot(spotNumber++, ParkingSpot::Type::Large));
    }
}

ParkingLot::~ParkingLot() {
    for (auto spot : spots) {
        delete spot;
    }
}

int ParkingLot::getCapacity() const { return capacity; }
int ParkingLot::getAvailableSpots() const { return availableSpots; }

bool ParkingLot::parkVehicle(Vehicle* vehicle) {
    if (!vehicle) return false;
    
    // Check if vehicle is already parked
    if (occupiedSpots.find(vehicle->m_licensePlate) != occupiedSpots.end()) {
        return false;
    }
    
    ParkingSpot* spot = findAvailableSpot(vehicle);
    if (!spot) return false;
    
    if (spot->parkVehicle(vehicle)) {
        occupiedSpots[vehicle->m_licensePlate] = spot;
        availableSpots--;
        return true;
    }
    return false;
}

Vehicle* ParkingLot::removeVehicle(const std::string& licensePlate) {
    auto it = occupiedSpots.find(licensePlate);
    if (it == occupiedSpots.end()) return nullptr;
    
    ParkingSpot* spot = it->second;
    Vehicle* vehicle = spot->removeVehicle();
    if (vehicle) {
        occupiedSpots.erase(it);
        availableSpots++;
    }
    return vehicle;
}

ParkingSpot* ParkingLot::findVehicle(const std::string& licensePlate) const {
    auto it = occupiedSpots.find(licensePlate);
    return it != occupiedSpots.end() ? it->second : nullptr;
}



ParkingSpot* ParkingLot::findAvailableSpot(const Vehicle* vehicle) const {
    for (auto spot : spots) {
        if (spot->isAvailable() && spot->canFitVehicle(vehicle)) {
            return spot;
        }
    }
    return nullptr;
} 