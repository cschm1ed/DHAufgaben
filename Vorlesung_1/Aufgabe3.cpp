#include <iostream>

int main() {
	std::string input;
	double r1, r2;

	std::cout << "2 Widerstandswerte durch Leerzeichen getrennt eingeben\n";
	std::getline(std::cin, input);
	sscanf(input.c_str(), "%lf %lf", &r1, &r2);
	std::cout << "Widerstand in Reihe: " << r1 + r2 << "\n";
	std::cout << "Widerstand Parallel: " << (r1 * r2)/(r1 + r2) << "\n";
	return 0;
}
