#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    string name;
    int age;
};

void print(Person* person) {
    cout << person->name << " is " << person->age << " years old" << endl;
}

int main() {
    Person person1;
    person1.name = "Harry";
    person1.age = 23;

    cout << "Meet " << person1.name << endl;
    print(&person1);

    Person person2{"Alice", 30};
    print(&person2);

    Person person3{"Bob", 17};
    print(&person3);

    return 0;
}
