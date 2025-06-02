#include <iostream>
#include <string>
#include <sstream>

class FlightBooking {
public:
    FlightBooking(int id, int capacity, int reserved);
    void printStatus();
    bool reserveSeats(int numberOfSeats);
    bool cancelReservations(int numberOfSeats);

private:
    int id;
    int capacity;
    int reserved;
};

FlightBooking::FlightBooking(int id, int capacity, int reserved) {
    this->id = id;
    this->capacity = capacity;
    if (reserved < 0) reserved = 0;
    if (reserved > capacity * 1.05) reserved = capacity * 1.05;
    this->reserved = reserved;
}

void FlightBooking::printStatus() {
    int percentage = (100 * reserved) / capacity;
    std::cout << "Flight " << id << " : " << reserved << "/" << capacity
              << " (" << percentage << "%) seats reserved" << std::endl;
}

bool FlightBooking::reserveSeats(int numberOfSeats) {
    if (numberOfSeats < 0 || reserved + numberOfSeats > capacity * 1.05)
        return false;
    reserved += numberOfSeats;
    return true;
}

bool FlightBooking::cancelReservations(int numberOfSeats) {
    if (numberOfSeats < 0 || reserved - numberOfSeats < 0)
        return false;
    reserved -= numberOfSeats;
    return true;
}

int main() {
    int reserved = 0, capacity = 0;
    std::cout << "Provide flight capacity: ";
    std::cin >> capacity;

    std::cout << "Provide number of reserved seats: ";
    std::cin >> reserved;

    std::cin.ignore(); // убрать лишний символ после ввода

    FlightBooking booking(1, capacity, reserved);

    std::string command = "";
    while (command != "quit") {
        booking.printStatus();
        std::cout << "What would you like to do?: ";
        std::getline(std::cin, command);

        std::stringstream ss(command);
        std::string action;
        int number;

        ss >> action >> number;

        if (action == "add") {
            if (!booking.reserveSeats(number))
                std::cout << "Cannot perform this operation" << std::endl;
        } else if (action == "cancel") {
            if (!booking.cancelReservations(number))
                std::cout << "Cannot perform this operation" << std::endl;
        } else if (action != "quit") {
            std::cout << "Unknown command" << std::endl;
        }
    }

    return 0;
}
