#include <iostream>

int main() {
    unsigned char input;

	std::cout << "Bitte Zeichen eingeben: ";
    std::cin >> input;
    std::cout << "ASCII Wert: " << (unsigned int)input << "\n";
    return 0;
}
