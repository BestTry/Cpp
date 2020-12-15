// Declaration / Header / Protoype FuelTank class file
// Keeps track of amount of fuel stored in the tank.
// Value is stored in gallons but has liter conversion function
// Adds friend attribute so other classes can access funtions
// 'pour', and Operator Overloading declarations ' >> ', and ' << ' that
// is implemented in the independent outside of any class 'friendfunction' 

#ifndef MURACH_FUEL_TANK_H
#define MURACH_FUEL_TANK_H

#include "FuelCan.h"

class FuelTank {
private:
    double gallons;
public:
    FuelTank(double gallons_param = 0) {
        gallons = gallons_param;
    }

    void set_gallons(double gallons_param) { 
        gallons = gallons_param;
    }

    double get_gallons() const {
        return gallons;
    }

    double get_liters() const;

    FuelTank operator+ (const FuelTank& right);             // Plus  '+' overload operator
    FuelTank operator- (const FuelTank& right);             // Minus '-' overload operator

    FuelTank& operator++ ();                                // Prefix   plus '++' overload operator
    FuelTank operator++ (int unused_param);                 // Postfix  plus '++' overload operator

    bool operator< (const FuelTank& right);                 // Relational Boolean '<'  overload operator
    bool operator> (const FuelTank& right);                 // Relational Boolean '>'  overload operator
    bool operator== (const FuelTank& right);                // Relational Boolean '==' overload operator

    friend void pour(FuelTank& tank, FuelCan& can);         // Uses references to fuel tank and fuel can
    friend std::ostream& operator<< (std::ostream&, const FuelTank&); // Output stream operator overloaded '<<'
    friend std::istream& operator>> (std::istream&, FuelTank&);       // Input stream operator overloaded '>>'
};

#endif                                                      // MURACH_FUEL_TANK_H