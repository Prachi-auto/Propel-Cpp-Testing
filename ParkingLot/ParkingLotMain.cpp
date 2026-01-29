#include "ParkingLot.hpp"
#include <iostream>

int main() {
    // Create parking lot with different types of spots
    ParkingLot parkingLot(2, 3, 2);  // 2 compact, 3 regular, 2 large spots
    
    // Create vehicles
    Vehicle* car1 = new Vehicle("CAR001", Vehicle::Type::Car);
    Vehicle* car2 = new Vehicle("CAR002", Vehicle::Type::Car);
    Vehicle* motorcycle = new Vehicle("MOTO001", Vehicle::Type::Motorcycle);
    Vehicle* truck = new Vehicle("TRUCK001", Vehicle::Type::Truck);
    
    if (parkingLot.parkVehicle(car1)) {
        std::cout << "CAR001 - Parked successfully: ";
    }
    
    if (parkingLot.parkVehicle(motorcycle)) {
        std::cout << "MOTO001 - Parked successfully: ";
    }
    
    if (parkingLot.parkVehicle(truck)) {
        std::cout << "TRUCK001 - Parked successfully: ";
    }
    
    // Remove a vehicle
    std::cout << "\nRemoving vehicle CAR001..." << std::endl;
    Vehicle* removed = parkingLot.removeVehicle("CAR001");
    if (removed) {
        std::cout << "CAR001 Removed successfully: ";
        delete removed;
    }
    
    // Try to park another car
    if (parkingLot.parkVehicle(car2)) {
        std::cout << "CAR002 Parked successfully: ";
    }
    
    // Cleanup remaining vehicles
    delete car2;
    delete motorcycle;
    delete truck;
    
    return 0;
} 
