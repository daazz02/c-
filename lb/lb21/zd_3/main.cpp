#include <iostream>
#include <string>
#include <sstream>

class FlightBooking {
public:
    FlightBooking(int id, int capacity, int reserved);
    FlightBooking();
    void printStatus();
    bool reserveSeats(int numberOfSeats);
    bool cancelReservations(int numberOfSeats);
    int getId() { return id; }

private:
    int id;
    int capacity;
    int reserved;
};

FlightBooking::FlightBooking() {
    id = 0;
    capacity = 0;
    reserved = 0;
}

FlightBooking::FlightBooking(int id, int capacity, int reserved) {
    this->id = id;
    this->capacity = capacity;
    this->reserved = std::max(0, std::min(reserved, (int)(capacity * 1.05)));
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
    FlightBooking bookings[10];

    std::string command;
    std::cout << "No flights in the system" << std::endl;

    while (true) {
        std::cout << "What would you like to do?: ";
        std::getline(std::cin, command);
        if (command == "quit") break;

        std::stringstream ss(command);
        std::string action;
        int id, n;

        ss >> action >> id >> n;

        if (action == "create") {
            bool success = false;
            for (auto& booking : bookings) {
                if (booking.getId() == 0) {
                    booking = FlightBooking(id, n, 0);
                    success = true;
                    break;
                }
            }
            if (!success)
                std::cout << "Cannot perform this operation: limit reached" << std::endl;
        } else if (action == "delete") {
            bool found = false;
            for (auto& booking : bookings) {
                if (booking.getId() == id) {
                    booking = FlightBooking();
                    found = true;
                    break;
                }
            }
            if (!found)
                std::cout << "Cannot perform this operation: flight " << id << " not found" << std::endl;
        } else if (action == "add") {
            bool found = false;
            for (auto& booking : bookings) {
                if (booking.getId() == id) {
                    if (!booking.reserveSeats(n))
                        std::cout << "Cannot perform this operation: capacity reached" << std::endl;
                    found = true;
                    break;
                }
            }
            if (!found)
                std::cout << "Cannot perform this operation: flight " << id << " not found" << std::endl;
        } else if (action == "cancel") {
            bool found = false;
            for (auto& booking : bookings) {
                if (booking.getId() == id) {
                    if (!booking.cancelReservations(n))
                        std::cout << "Cannot perform this operation" << std::endl;
                    found = true;
                    break;
                }
            }
            if (!found)
                std::cout << "Cannot perform this operation: flight " << id << " not found" << std::endl;
        }

        // Печатаем все существующие рейсы
        for (auto& booking : bookings) {
            if (booking.getId() != 0) {
                booking.printStatus();
            }
        }
    }

    return 0;
}
