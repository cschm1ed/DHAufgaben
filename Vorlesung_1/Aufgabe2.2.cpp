#include <iostream>
#include <cmath>

int main() {
    std::string input;
    double a, b, c, discriminant;

    std::cout << "Bitte a b und c der quadratischen Gleichung durch Leerzeichen getrennt eingeben\n";
    std::getline(std::cin, input);
    sscanf(input.c_str(), "%lf %lf %lf", &a, &b, &c);
    discriminant = pow(b, 2) - 4 * a * c;
    b = -b;
    if (discriminant == 0) {
        std::cout << "x = " << b / (2 * a) << "\n";
    } else if (discriminant > 0) {
        std::cout << "x_1 = " << (b + sqrt(discriminant)) / (2 * a);
        std::cout << "x_2 = " << (b - sqrt(discriminant)) / (2 * a);
    } else {
        std::cout << "x_1 = " << b / (2 * a) << " + " << sqrt(discriminant * -1) / (2 * a) << "i\n";
        std::cout << "x_2 = " << b / (2 * a) << " - " << sqrt(discriminant * -1) / (2 * a) << "i\n";
    }
    return 0;
}
