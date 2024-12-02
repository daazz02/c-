#include <iostream>
#include <cmath>

int main() {
    double x, y;
    std::cout << "Введите координаты точки (x, y): ";
    std::cin >> x >> y;


    bool inTriangle = (x >= 0 && y >= 0 && y <= -x + 1);


    bool inSemiCircle = (x <= 0 && y <= 0 && (x * x + y * y <= 1));


    if (inTriangle || inSemiCircle) {
        std::cout << "Точка попадает в заштрихованную область." << std::endl;
    } else {
        std::cout << "Точка не попадает в заштрихованную область." << std::endl;
    }

    return 0;
}

















//2
// #include <iostream>
//
// using namespace std;
// int main() {
//     int student_number;
//
//     cout << "Введіть номер студента (1-7): ";
//     cin >> student_number;
//
//     switch (student_number) {
//         case 1:
//             cout << "Ім'я: Олена, Середній бал: 90" << endl;
//         break;
//         case 2:
//             cout << "Ім'я: Андрій, Середній бал: 85" << endl;
//         break;
//         case 3:
//             cout << "Ім'я: Ірина, Середній бал: 92" << endl;
//         break;
//         case 4:
//             cout << "Ім'я: Сергій, Середній бал: 78" << endl;
//         break;
//         case 5:
//             cout << "Ім'я: Марія, Середній бал: 88" << endl;
//         break;
//         case 6:
//             cout << "Ім'я: Дмитро, Середній бал: 81" << endl;
//         break;
//         case 7:
//             cout << "Ім'я: Юлія, Середній бал: 95" << endl;
//         break;
//         default:
//             cout << "Невірний номер студента!" << endl;
//         break;
//     }
//     return 0;
// }
//
//
//
//




//1
// #include <iostream>
//
// using namespace std;
//
// int main() {
//     int N;
//     cout << "Введіть тризначне додатнє число N: ";
//     cin >> N;
//
//     if (N < 100 || N > 999) {
//         cout << "Число повинно бути тризначним і додатнім!" << endl;
//         return 1;
//     }
//
//     int first_digit = N / 100;
//     int second_digit = (N / 10) % 10;
//     int third_digit = N % 10;
//
//     int count = 0;
//
//     if (first_digit < 7) count++;
//     if (second_digit < 7) count++;
//     if (third_digit < 7) count++;
//
//     cout << "Кількість цифр, менших за 7: " << count << endl;
//
//     return 0;
// }
