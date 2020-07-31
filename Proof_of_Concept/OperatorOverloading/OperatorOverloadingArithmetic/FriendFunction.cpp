#include <iostream>
#include "FuelCan.h"
#include "FuelTank.h"

using namespace std;
                                                            // Funtions take references to Fuel Tank and Fuel Can
void pour(FuelTank& tank, FuelCan& can) {                   // Uses combined Assignment operator
    tank.gallons += can.gallons;                            // Access private data members
    can.gallons = 0;                                        // Access private data memeber
}
                                                            // Stream insertion operator '<<' overloaded
ostream& operator << (ostream& out, const FuelTank& tank) { // used in statement cout << tank
    out << "   Gallons: " << tank.gallons << endl
        << "   Liters:  " << tank.get_liters() << endl
        << endl;
    return out;
}
                                                            // Stream extraction operator '>>' overloaded
istream& operator >> (istream& in, FuelTank& tank) {        // used in statement in >> tank.gallons
    cout << "Enter gallons: ";
    in >> tank.gallons;
    return in;
}