// Code was copied from textbook 'Murach's C++ Programming' - Chapter 16 - 
// Working with friend functions and operator overloading
// Many examples of operator overloading including " + - ++ < > << >> //
//
//
#include <iostream>
#include "FuelTank.h"
#include "FuelCan.h"

using namespace std;

int main()
{
    FuelTank tank(500);
    FuelCan can(2);
    cout << "Fuel TANK contains: " << tank.get_gallons() << endl;
    cout << "Fuel CAN cantains: " << can.get_gallons() << endl;
    cout << "Can is poured into the tank using friend funtion 'pour' that\n"
         << "is located outside both 'FuelTank' and 'FuelCan' classes" << endl;
    pour(tank, can);
    cout << "TANK contains after pour: " << tank.get_gallons() << endl;
    cout << "CAN contains after pour: " << can.get_gallons() << endl << endl;

    FuelTank tank1(100);                                                // Object tank1 created and intialized
    cout << "TANK 1 contains" << endl
            << "  Gallons: " << tank1.get_gallons() << endl
            << "  Liters:  " << tank1.get_liters() << endl << endl;

    FuelTank tank2(200);                                                // Object tank2 created and initialized
    cout << "TANK 2 contains" << endl
        << "  Gallons: " << tank2.get_gallons() << endl
        << "  Liters:  " << tank2.get_liters() << endl << endl;
                                                                        // Object tank 3 initialized using operator overloading
    FuelTank tank3 = tank2 + tank1;                                     // FuelTank tank3 = tank2.operator+(tank1);  - // alternate syntax
                                                

    cout << "TANK 3 contains" << endl
        << "  Gallons: " << tank3.get_gallons() << endl
        << "  Liters:  " << tank3.get_liters() << endl << endl;
    cout << "TANK3 was created using Operator Overloading of the '+'\n"
         << "operator in the statement: tank3 = tank2 + tank1 \n\n"<< endl;

    cout << "Demonstrating Overload Opterator pre-increment '++' " << endl;
    cout << "Tank 1 pre  increment status: " << tank1++.get_gallons() << endl;// Value before increment
    cout << "Tank 1 post increment status: " << tank1.get_gallons() << "\n" << endl;

    cout << "Demonstrating boolean relational Overload Opterators:\n"
         << "less than '<', greater than '>', or is equal to '=='" << endl;
    if (tank1 < tank2) {
        cout << "Tank 1 has less fuel than tank 2.\n\n";
    }
    else if (tank1 > tank2) {
        cout << "Tank 1 has more fuel than tank 2.\n\n";
    }
    else if (tank1 == tank2) {
        cout << "Tank 1 has the same amount of fuel as tank 2.\n\n";
    }

    FuelTank tank4, tank5;                                              // Instantiating two tanks on same line
    tank4.set_gallons(400);
    tank5.set_gallons(500);
     
                                                                        // cin >> tank4 >> tank5; // uncomment to test extraction operator
    cout << "Demostrating the stream Overload Operators: the\n"
         << "insertion operator '<<' and the extraction operator'>>' " << endl;
    cout << "TANK 4\n" << tank4;                                        // Overload Operator '<<' invoked because operand is from class tank
    cout << "TANK 5\n" << tank5;                                        // It is implemented in the 'friendfunction.cpp' file

    return 0;
}