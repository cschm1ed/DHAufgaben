#include <iostream>

int main() {
	std::string input;
	std::cout << "Eingabe Grad in Fahrenheit: ";
	std::getline(std::cin, input);

	std::cout << "Grad in Celsius: " << (std::stod(input) - 32) * ((double)5 / 9) << "\n";
	return (0);
}
