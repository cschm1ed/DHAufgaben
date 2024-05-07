#include <iostream>


int main() {
	std::string input;
	int length, width, height;

	std::cout << "Bitte Seitenlängen des Quaders durch Leerzeichen getrennt eingeben\n";
	std::getline(std::cin, input);
	sscanf(input.c_str(), "%i %i %i", &length, &width, &height);
	std::cout << "Volumen des Quaders: " << length * width * height << "\n";
    std::cout << "Oberfläche des Quaders: " << (length * height) * 2 + (length * width) * 2 \
                + (width * height) * 2 << "\n";
	return (0);
}
