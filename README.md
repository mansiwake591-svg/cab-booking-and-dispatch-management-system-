# Cab Booking and Dispatch Management System

## Project Overview

**CabGo -- Cab Booking and Dispatch Management System** is a
console-based prototype developed in **C++**. It demonstrates the basic
workflow of a cab booking service, from creating a ride request to
assigning a driver, starting the trip, and marking it as completed.

The project is designed as a beginner-friendly first-year programming
project. It uses fundamental C++ concepts such as structures, arrays,
functions, conditional statements, loops, switch statements, and
strings.

## Objectives

-   Allow customers to book a cab by entering pickup and destination
    locations.
-   Offer three cab categories: Mini, Sedan, and SUV.
-   Calculate an estimated fare based on the selected cab type and trip
    distance.
-   Allow a dispatcher to view booking requests and assign a driver.
-   Allow a driver to view assigned trips, start rides, and complete
    rides.
-   Maintain a simple ride history during the program session.


## Roles in the System

### 1. Customer

-   Book a cab.
-   Enter pickup and destination locations.
-   Select a cab category.
-   Enter the estimated trip distance.
-   View the estimated fare.
-   Confirm or cancel the booking.
-   View ride history.

### 2. Dispatcher

-   View all bookings.
-   View pending ride requests.
-   Assign the demo driver to a requested ride.

### 3. Driver

-   View assigned and running trips.
-   Start an assigned ride.
-   Complete a ride that is in progress.

## Cab Categories and Sample Fare Rates

The program uses the following sample rates. These are assumptions for
the prototype and are not actual market prices.

  Cab category     Sample rate per kilometre
  -------------- ---------------------------
  Mini                                Rs. 10
  Sedan                               Rs. 14
  SUV                                 Rs. 18

**Fare formula:**

`Estimated Fare = Rate per km × Trip Distance`

For example, a 10 km Mini ride costs:

`Rs. 10 × 10 = Rs. 100`

## Ride Status Workflow

Every confirmed booking moves through the following statuses:

1.  **Requested** -- The customer has confirmed the booking.
2.  **Driver assigned** -- The dispatcher has assigned the demo driver.
3.  **In progress** -- The driver has started the ride.
4.  **Completed** -- The driver has completed the ride.

The program checks the current status before allowing a ride to move to
the next stage.

## Main Features

-   Role-based menus for Customer, Dispatcher, and Driver.
-   Booking with pickup and destination details.
-   Selection of Mini, Sedan, or SUV.
-   Estimated fare calculation.
-   Booking confirmation or cancellation.
-   Automatic ride ID assignment.
-   Display of all rides and ride history.
-   Driver assignment by ride ID.
-   Ride start and completion operations.
-   Basic validation for cab selection, positive distance, ride ID, and
    ride status.
-   Maximum storage of 50 rides during one program run.

## C++ Concepts Used

  -----------------------------------------------------------------------
  Concept                             Use in the project
  ----------------------------------- -----------------------------------
  `struct`                            Stores the details of one ride in
                                      the `Ride` structure.

  Arrays                              Stores cab names, rates, status
                                      names, and ride records.

  Functions                           Separates booking, fare
                                      calculation, display, searching,
                                      and menu operations.

  `if-else`                           Validates user choices and ride
                                      statuses.

  `switch`                            Handles menu selections.

  Loops                               Repeats menus and searches or
                                      displays ride records.

  Strings                             Stores pickup, destination, cab
                                      names, and driver name.

  Constants                           Defines ride capacity and status
                                      codes.
  -----------------------------------------------------------------------

## Program Structure

-   `calculateFare()` -- Calculates the fare using the cab rate and
    distance.
-   `showRide()` -- Displays the details of one ride.
-   `showAllRides()` -- Displays all stored rides.
-   `findRide()` -- Searches for a ride using its ID.
-   `bookRide()` -- Takes customer details and creates a booking.
-   `customerMenu()` -- Displays customer operations.
-   `assignDriver()` -- Assigns the demo driver to a pending ride.
-   `dispatcherMenu()` -- Displays dispatcher operations.
-   `updateRide()` -- Changes a ride from one valid status to another.
-   `driverMenu()` -- Displays driver operations.
-   `main()` -- Starts the program and displays the role-selection menu.

## How to Compile and Run

The supplied source code is **C++**, not C. Save it in a file named
`cabgo.cpp`.

### Using g++ in a terminal

1.  Open a terminal in the folder containing `cabgo.cpp`.

2.  Compile the program:

    ``` bash
    g++ cabgo.cpp -o cabgo
    ```

3.  Run it on Windows:

    ``` bash
    .\cabgo.exe
    ```

    On Linux or macOS:

    ``` bash
    ./cabgo
    ```

If your IDE has a C++ compiler and run option, you can also open
`cabgo.cpp` and use that option.

## Basic Testing Scenarios

  -----------------------------------------------------------------------
  Test                    Action                  Expected result
  ----------------------- ----------------------- -----------------------
  1                       Choose Customer → Book  Fare is calculated and
                          a cab and enter valid   booking is saved after
                          details.                confirmation.

  2                       Enter an invalid cab    Booking is cancelled
                          choice.                 with an invalid cab
                                                  message.

  3                       Enter zero or a         Booking is cancelled
                          negative distance.      with a distance
                                                  validation message.

  4                       Choose Dispatcher →     Ride status changes to
                          Assign driver for a     Driver assigned.
                          requested ride.         

  5                       Choose Driver → Start   Ride status changes to
                          ride for an assigned    In progress.
                          ride.                   

  6                       Choose Driver →         Ride status changes to
                          Complete ride for an    Completed.
                          in-progress ride.       

  7                       Enter an unknown ride   The program displays an
                          ID.                     invalid ride or
                                                  not-found message.

  8                       View rides before       The program displays
                          making a booking.       "No rides yet."
  -----------------------------------------------------------------------

## Limitations

-   This is a console prototype; it does not have a graphical user
    interface or mobile application.
-   Ride data is stored in an array and is lost when the program exits.
-   Only one demo driver is included.
-   The program does not use a database, GPS, live maps, online
    payments, or real-time notifications.
-   The fare rates are sample assumptions and may not represent real cab
    fares.
-   The program supports up to 50 rides in one run.
-   It is a demonstration of the booking and dispatch workflow, not a
    production-ready cab service.

## Future Scope

The project can be extended in the future by adding:

-   Customer and driver registration and login.
-   Multiple drivers and driver availability.
-   Persistent storage using files or a database.
-   Live cab tracking and map integration.
-   More accurate fare calculation, including waiting charges and taxes.
-   Online payment and digital receipts.
-   Booking cancellation and feedback features.
-   A graphical or web-based user interface.

## Conclusion

CabGo demonstrates the basic working process of a cab booking and
dispatch management system. It connects the customer, dispatcher, and
driver through a simple ride-status workflow. The project provides
practical experience with fundamental C++ programming concepts and shows
how these concepts can be combined to solve a real-world style problem.

------------------------------------------------------------------------

**Project title:** Cab Booking and Dispatch Management System\
**Prototype name:** CabGo\
**Programming language:** C++\
**Project type:** Console-based prototype\
**Ride capacity:** 50 rides per program run
