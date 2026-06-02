// Create two classes DM and DB which store the value of distances (metric vs imperial). Use friend function to carry out the addition operation.

#include <iostream>

class DB;
class DM; 

class DM {
private:
    double distanceInMeters;
public:
    DM(double meters) : distanceInMeters(meters) {}
    double getDistanceInMeters() const {
        return distanceInMeters;
    }
    friend double addDistances(const DM& dm, const DB& db);
};

class DB {
private:
    double distanceInFeet;
public:
    DB(double feet) : distanceInFeet(feet) {}
    double getDistanceInFeet() const {
        return distanceInFeet;
    }
    friend double addDistances(const DM& dm, const DB& db);
};

double addDistances(const DM& dm, const DB& db) {
    // Convert feet to meters (1 foot = 0.3048 meters)
    double distanceInMetersFromDB = db.getDistanceInFeet() * 0.3048;
    return dm.getDistanceInMeters() + distanceInMetersFromDB;
}

int main() {
    DM distance1(100.0); // 100 meters
    DB distance2(328.084); // 328.084 feet (approximately 100 meters)

    double totalDistance = addDistances(distance1, distance2);
    std::cout << "Total Distance in Meters: " << totalDistance << " meters" << std::endl;

    return 0;
}