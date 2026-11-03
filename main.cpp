#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;

// CabGo: Cab Booking and Dispatch Management System
// Console-based academic prototype

class Ride {
public:
    int rideId;
    string pickup, destination, cabType, status, driver;
    double distance, fare;

    Ride(int id, string p, string d, string cab, double km, double amount) {
        rideId = id;
        pickup = p;
        destination = d;
        cabType = cab;
        distance = km;
        fare = amount;
        status = "Requested";
        driver = "Not assigned";
    }

    void display() {
        cout << "\nRide ID       : " << rideId;
        cout << "\nPickup        : " << pickup;
        cout << "\nDestination   : " << destination;
        cout << "\nCab Category  : " << cabType;
        cout << "\nDistance      : " << distance << " km";
        cout << "\nEstimated Fare: Rs. " << fixed << setprecision(2) << fare;
        cout << "\nDriver        : " << driver;
        cout << "\nRide Status   : " << status << "\n";
        cout << "------------------------------------\n";
    }
};

class CabGo {
private:
    vector<Ride> rides;
    int nextRideId = 1001;

    double getRate(string cabType) {
        if (cabType == "Mini") return 12;
        if (cabType == "Sedan") return 16;
        return 22; // SUV
    }

    int findRide(int id) {
        for (int i = 0; i < (int)rides.size(); i++) {
            if (rides[i].rideId == id) return i;
        }
        return -1;
    }

public:
    void bookCab() {
        string pickup, destination;
        int cabChoice;
        double distance;

        cout << "\n--- CUSTOMER: BOOK A CAB ---\n";
        cout << "Enter pickup location: ";
        getline(cin >> ws, pickup);

        cout << "Enter destination: ";
        getline(cin, destination);

        cout << "\nSelect cab category:\n";
        cout << "1. Mini  (Rs. 12 per km)\n";
        cout << "2. Sedan (Rs. 16 per km)\n";
        cout << "3. SUV   (Rs. 22 per km)\n";
        cout << "Enter choice: ";
        cin >> cabChoice;

        if (cabChoice < 1 || cabChoice > 3) {
            cout << "Invalid cab choice.\n";
            return;
        }

        cout << "Enter trip distance in km: ";
        cin >> distance;

        if (cin.fail() || distance <= 0) {
            cout << "Invalid distance. Please enter a positive number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return;
        }

        string cabType;
        if (cabChoice == 1) cabType = "Mini";
        else if (cabChoice == 2) cabType = "Sedan";
        else cabType = "SUV";

        double fare = distance * getRate(cabType);

        cout << "\nEstimated fare: Rs. " << fixed << setprecision(2) << fare << "\n";
        cout << "1. Confirm booking\n";
        cout << "2. Cancel\n";
        cout << "Enter choice: ";
        int confirm;
        cin >> confirm;

        if (confirm == 1) {
            rides.push_back(Ride(nextRideId, pickup, destination,
                                 cabType, distance, fare));
            cout << "\nBooking confirmed successfully!\n";
            cout << "Your Ride ID is: " << nextRideId << "\n";
            nextRideId++;
        } else {
            cout << "Booking cancelled.\n";
        }
    }

    void showRides() {
        cout << "\n--- CUSTOMER: MY RIDES / RIDE HISTORY ---\n";
        if (rides.empty()) {
            cout << "No bookings available.\n";
            return;
        }
        for (int i = 0; i < (int)rides.size(); i++) {
            rides[i].display();
        }
    }

    void dispatcherModule() {
        cout << "\n--- DISPATCHER MODULE ---\n";
        bool found = false;

        for (int i = 0; i < (int)rides.size(); i++) {
            if (rides[i].status == "Requested") {
                rides[i].display();
                found = true;
            }
        }

        if (!found) {
            cout << "No pending ride requests.\n";
            return;
        }

        int id;
        cout << "Enter Ride ID to assign a driver (0 to go back): ";
        cin >> id;
        if (id == 0) return;

        int index = findRide(id);
        if (index == -1) {
            cout << "Ride ID not found.\n";
        } else if (rides[index].status != "Requested") {
            cout << "This ride is not waiting for driver assignment.\n";
        } else {
            rides[index].driver = "Demo Driver";
            rides[index].status = "Assigned";
            cout << "Driver assigned successfully!\n";
        }
    }

    void driverModule() {
        cout << "\n--- DRIVER MODULE ---\n";
        bool found = false;

        for (int i = 0; i < (int)rides.size(); i++) {
            if (rides[i].status == "Assigned" ||
                rides[i].status == "In Progress") {
                rides[i].display();
                found = true;
            }
        }

        if (!found) {
            cout << "No active trips assigned to the driver.\n";
            return;
        }

        int id;
        cout << "Enter Ride ID to update (0 to go back): ";
        cin >> id;
        if (id == 0) return;

        int index = findRide(id);
        if (index == -1) {
            cout << "Ride ID not found.\n";
            return;
        }

        if (rides[index].status == "Assigned") {
            cout << "1. Start ride\n";
            cout << "Enter choice: ";
            int choice;
            cin >> choice;
            if (choice == 1) {
                rides[index].status = "In Progress";
                cout << "Ride started successfully!\n";
            } else {
                cout << "No status change made.\n";
            }
        } else if (rides[index].status == "In Progress") {
            cout << "1. Complete ride\n";
            cout << "Enter choice: ";
            int choice;
            cin >> choice;
            if (choice == 1) {
                rides[index].status = "Completed";
                cout << "Ride completed successfully!\n";
            } else {
                cout << "No status change made.\n";
            }
        } else {
            cout << "This ride cannot be updated at this stage.\n";
        }
    }

    void run() {
        int choice;
        do {
            cout << "\n====================================\n";
            cout << "       CABGO CAB BOOKING SYSTEM\n";
            cout << "====================================\n";
            cout << "1. Customer - Book a cab\n";
            cout << "2. Customer - View my rides\n";
            cout << "3. Dispatcher - Assign a driver\n";
            cout << "4. Driver - Start / Complete ride\n";
            cout << "5. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            if (cin.fail()) {
                cout << "Please enter a valid number.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            switch (choice) {
                case 1: bookCab(); break;
                case 2: showRides(); break;
                case 3: dispatcherModule(); break;
                case 4: driverModule(); break;
                case 5: cout << "Thank you for using CabGo!\n"; break;
                default: cout << "Invalid choice. Please try again.\n";
            }
        } while (choice != 5);
    }
};

int main() {
    CabGo system;
    system.run();
    return 0;
}
