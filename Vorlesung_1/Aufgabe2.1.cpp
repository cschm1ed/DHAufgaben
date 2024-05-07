#include <iostream>
#include <cmath>

void printQuadrant(double x, double y) {
    std::cout << "Quadrant: ";
    if (x >= 0) {
        if (y >= 0)
            std::cout << "I";
        else
            std::cout << "IV";
    }
    else {
        if (y >= 0)
            std::cout << "II";
        else
            std::cout << "III";
    }
    std::cout << "\n";
}

double getAngle(double x, double y, double len) {
	if (y >= 0)
		return acos(x / len) * 180 / M_PI;
	if (x <= 0 && y <= 0) {
		return acos(x / len) * 180 / M_PI + 90;
	}
	return acos(x / len) * 180 / M_PI - 90;
}

int main() {
    double x, y, len;
    std::string input;

    std::cout << "Bitte x und y Koordinate mit Leerzeichen getrennt eingeben\n";
    std::getline(std::cin, input);
    sscanf(input.c_str(), "%lf %lf", &x, &y);
    len = sqrt(pow(x, 2) + pow(y, 2));
    printQuadrant(x, y);
    std::cout << "Zeigerlänge: " << len << "\n";
    std::cout << "Zeigerwinkel: " << getAngle(x, y, len) << "°\n";
    return 0;
}
