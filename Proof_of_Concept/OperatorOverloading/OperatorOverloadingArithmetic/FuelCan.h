// Declaration / Header / Prototype of FuelCan class ??? There is no corresponding definition file ???
// From a study of the statements below it appears that the definition statements are implemented here 
#ifndef MURACH_FUEL_CAN_H
#define MURACH_FUEL_CAN_H

class FuelTank;                                     // Forward declaration of FuelTank class

class FuelCan
{
private:
    double gallons = 0;                             // Not sure why this is initialized when the constructor does same
public:
    FuelCan(double gallons_param = 0) { gallons = gallons_param; }
    double get_gallons() { return gallons; }
    friend void pour(FuelTank& tank, FuelCan& can);
};

#endif                                              // MURACH_FUEL_CAN_H