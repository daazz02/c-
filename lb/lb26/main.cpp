#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// Базовий клас
class IPAddress {
protected:
    string address;

public:
    IPAddress(const string& addr) : address(addr) {}
    IPAddress(const IPAddress& other) : address(other.address) {}

    virtual void print() const {
        cout << address;
    }

    virtual ~IPAddress() = default;
};

// Перевірка правильності IP
bool isValidIP(const string& ip) {
    stringstream ss(ip);
    string segment;
    int count = 0;

    while (getline(ss, segment, '.')) {
        if (++count > 4) return false;

        if (segment.empty() || segment.size() > 3) return false;

        for (char c : segment) {
            if (!isdigit(c)) return false;
        }

        int num = stoi(segment);
        if (num < 0 || num > 255) return false;
    }

    return count == 4;
}

// Похідний клас
class IPAddressChecked : public IPAddress {
    bool isCorrect;

public:
    IPAddressChecked(const string& addr)
        : IPAddress(addr), isCorrect(isValidIP(addr)) {}

    IPAddressChecked(const IPAddressChecked& other)
        : IPAddress(other), isCorrect(other.isCorrect) {}

    void print() const override {
        IPAddress::print();
        cout << " - " << (isCorrect ? "Correct" : "Not Correct");
    }
};

int main() {
    string ip1, ip2, ip3;

    // Ввід трьох IP-адрес
    getline(cin, ip1);
    getline(cin, ip2);
    getline(cin, ip3);

    // Створення об'єктів
    IPAddress ipObj(ip1);
    IPAddressChecked ipChecked1(ip2);
    IPAddressChecked ipChecked2(ip3);

    // Вивід
    ipObj.print();
    cout << endl;
    ipChecked1.print();
    cout << endl;
    ipChecked2.print();
    cout << endl;

    return 0;
}
