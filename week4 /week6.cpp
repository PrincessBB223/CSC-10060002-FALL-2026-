//
// Created by Princess B on 09/25/26.
//
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

int main()
{
    // Constants
    const int MAX_CAPACITY = 40;
    const int FORECAST_DAYS = 7;

    const double CAR_RATE = 18.00;
    const double TRUCK_RATE = 25.00;
    const double EV_RATE = 15.00;
    const double EV_FEE = 5.00;

    // Variables
    int numVehicles;

    // Display program heading
    cout << "============================================" << endl;
    cout << "       AIRPORT PARKING MANAGEMENT" << endl;
    cout << "============================================" << endl;
    cout << "Total Parking Capacity: " << MAX_CAPACITY << endl;

    // Validate number of arriving vehicles
    do
    {
        cout << "Enter the number of arriving vehicles: ";
        cin >> numVehicles;

        if (numVehicles < 1 || numVehicles > MAX_CAPACITY)
        {
            cout << "Invalid entry." << endl;
            cout << "The parking facility can accommodate a maximum of "
                 << MAX_CAPACITY << " vehicles." << endl;
        }

    } while (numVehicles < 1 || numVehicles > MAX_CAPACITY);

    // Vectors to store vehicle information
    vector<string> licensePlates;
    vector<char> vehicleTypes;
    vector<int> parkingDays;
    vector<double> finalCharges;

    // Process each vehicle
    for (int i = 0; i < numVehicles; i++)
    {
        cout << endl;
        cout << "--------------------------------------------" << endl;
        cout << "VEHICLE " << i + 1 << endl;
        cout << "--------------------------------------------" << endl;

        string plate;
        char type;
        int days;

        // Get license plate
        cout << "License Plate: ";
        cin >> plate;

        // Validate vehicle type
        do
        {
            cout << "Vehicle Type (C/T/E): ";
            cin >> type;

            // Convert loweRcase input to uppercase
            if (type >= 'a' && type <= 'z')
            {
                type = type - 'a' + 'A';
            }

            if (type != 'C' && type != 'T' && type != 'E')
            {
                cout << "Invalid vehicle type." << endl;
                cout << "Enter C for Car, T for Truck, or E for Electric Vehicle."
                     << endl;
            }

        } while (type != 'C' && type != 'T' && type != 'E');

        // Validate parking days
        do
        {
            cout << "Number of Parking Days: ";
            cin >> days;

            if (days < 1 || days > 30)
            {
                cout << "Invalid number of parking days." << endl;
                cout << "Parking duration must be between 1 and 30 days."
                     << endl;
            }

        } while (days < 1 || days > 30);

        // Determine daily rate
        double dailyRate;

        if (type == 'C')
        {
            dailyRate = CAR_RATE;
        }
        else if (type == 'T')
        {
            dailyRate = TRUCK_RATE;
        }
        else
        {
            dailyRate = EV_RATE;
        }

        // Calculate base parking charge
        double baseCharge = dailyRate * days;

        // Determine discount
        double discountRate;

        if (days >= 14)
        {
            discountRate = 0.20;
        }
        else if (days >= 7)
        {
            discountRate = 0.10;
        }
        else
        {
            discountRate = 0.00;
        }

        double discount = baseCharge * discountRate;

        // Determine additional fee
        double additionalFee = 0.00;

        if (type == 'E')
        {
            additionalFee = EV_FEE;
        }

        // Calculate final charge
        double finalCharge = baseCharge - discount + additionalFee;

        // Store information in vectors
        licensePlates.push_back(plate);
        vehicleTypes.push_back(type);
        parkingDays.push_back(days);
        finalCharges.push_back(finalCharge);

        // Display vehicle summary
        cout << endl;
        cout << "--------------------------------------------" << endl;
        cout << "VEHICLE SUMMARY" << endl;
        cout << "--------------------------------------------" << endl;

        cout << fixed << setprecision(2);

        cout << "License Plate: " << plate << endl;

        cout << "Vehicle Type: ";

        if (type == 'C')
        {
            cout << "Car" << endl;
        }
        else if (type == 'T')
        {
            cout << "Truck" << endl;
        }
        else
        {
            cout << "Electric Vehicle" << endl;
        }

        cout << "Parking Days: " << days << endl;
        cout << "Daily Rate: $" << dailyRate << endl;
        cout << "Base Parking Charge: $" << baseCharge << endl;
        cout << "Discount: $" << discount << endl;
        cout << "Additional Fee: $" << additionalFee << endl;
        cout << "Final Parking Charge: $" << finalCharge << endl;
    }

    // Display parking assignments
    cout << endl;
    cout << "--------------------------------------------" << endl;
    cout << "PARKING ASSIGNMENTS" << endl;
    cout << "--------------------------------------------" << endl;

    for (int i = 0; i < numVehicles; i++)
    {
        cout << licensePlates[i]
             << " Space " << i + 1 << endl;
    }

    // Seven-day parking occupancy forecast
    cout << endl;
    cout << "--------------------------------------------" << endl;
    cout << "7-DAY PARKING OCCUPANCY FORECAST" << endl;
    cout << "--------------------------------------------" << endl;

    for (int day = 1; day <= FORECAST_DAYS; day++)
    {
        int occupiedSpaces = 0;

        // Nested loop:
        // Examine every vehicle for each forecast day
        for (int i = 0; i < numVehicles; i++)
        {
            if (parkingDays[i] >= day)
            {
                occupiedSpaces++;
            }
        }

        // Determine parking status
        string status;

        if (occupiedSpaces == 0)
        {
            status = "EMPTY";
        }
        else if (occupiedSpaces <= 20)
        {
            status = "NORMAL";
        }
        else if (occupiedSpaces <= 30)
        {
            status = "BUSY";
        }
        else if (occupiedSpaces <= 35)
        {
            status = "VERY BUSY";
        }
        else
        {
            status = "NEAR CAPACITY";
        }

        cout << "Day " << day << ": "
             << occupiedSpaces << " vehicles "
             << status << endl;
    }

    // Vehicle search
    cout << endl;
    cout << "--------------------------------------------" << endl;
    cout << "VEHICLE SEARCH" << endl;
    cout << "--------------------------------------------" << endl;

    string searchPlate;
    cout << "Enter License Plate: ";
    cin >> searchPlate;

    bool found = false;

    // Search through the license plate vector
    for (int i = 0; i < numVehicles; i++)
    {
        if (licensePlates[i] == searchPlate)
        {
            found = true;

            cout << endl;
            cout << "Vehicle Found!" << endl;
            cout << "License Plate: " << licensePlates[i] << endl;

            cout << "Vehicle Type: ";

            if (vehicleTypes[i] == 'C')
            {
                cout << "Car" << endl;
            }
            else if (vehicleTypes[i] == 'T')
            {
                cout << "Truck" << endl;
            }
            else
            {
                cout << "Electric Vehicle" << endl;
            }

            cout << "Parking Days: " << parkingDays[i] << endl;
            cout << "Parking Space: " << i + 1 << endl;
            cout << "Final Parking Charge: $"
                 << finalCharges[i] << endl;

            break;
        }
    }

    if (!found)
    {
        cout << "Vehicle not found." << endl;
    }

    // End-of-shift management report
    int cars = 0;
    int trucks = 0;
    int electricVehicles = 0;
    int totalParkingDays = 0;
    int vehiclesStaying7Plus = 0;

    double totalRevenue = 0.00;
    double highestCharge = finalCharges[0];
    double lowestCharge = finalCharges[0];

    // Calculate report information using vectors
    for (int i = 0; i < numVehicles; i++)
    {
        // Count vehicle types
        if (vehicleTypes[i] == 'C')
        {
            cars++;
        }
        else if (vehicleTypes[i] == 'T')
        {
            trucks++;
        }
        else
        {
            electricVehicles++;
        }

        // Add parking days
        totalParkingDays += parkingDays[i];

        // Count vehicles staying 7 or more days
        if (parkingDays[i] >= 7)
        {
            vehiclesStaying7Plus++;
        }

        // Add revenue
        totalRevenue += finalCharges[i];

        // Find highest charge
        if (finalCharges[i] > highestCharge)
        {
            highestCharge = finalCharges[i];
        }

        // Find lowest charge
        if (finalCharges[i] < lowestCharge)
        {
            lowestCharge = finalCharges[i];
        }
    }

    // Calculate avera
    double averageParkingStay =
        static_cast<double>(totalParkingDays) / numVehicles;

    double averageCharge =
        totalRevenue / numVehicles;

    int availableSpaces = MAX_CAPACITY - numVehicles;

    // Display end-of-shift report
    cout << endl;
    cout << "================================================" << endl;
    cout << "        END-OF-SHIFT MANAGEMENT REPORT" << endl;
    cout << "================================================" << endl;

    cout << "Total Arriving Vehicles: " << numVehicles << endl;
    cout << endl;

    cout << "Available Parking Spaces: " << availableSpaces << endl;
    cout << "Cars: " << cars << endl;
    cout << "Trucks: " << trucks << endl;
    cout << "Electric Vehicles: " << electricVehicles << endl;

    cout << "Total Parking Days: " << totalParkingDays << endl;

    cout << fixed << setprecision(2);

    cout << "Average Parking Stay: "
         << averageParkingStay << " days" << endl;

    cout << "Vehicles Staying 7+ Days: "
         << vehiclesStaying7Plus << endl;

    cout << "Total Expected Revenue: $"
         << totalRevenue << endl;

    cout << "Average Charge per Vehicle: $"
         << averageCharge << endl;

    cout << "Highest Parking Charge: $"
         << highestCharge << endl;

    cout << "Lowest Parking Charge: $"
         << lowestCharge << endl;

    cout << "================================================" << endl;

    return 0;
}