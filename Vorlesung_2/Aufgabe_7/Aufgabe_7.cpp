#include <iostream>

int main() {
	std::string input;

	std::cout << "Wort eingeben (max 100 chars):";
	std::getline(std::cin, input);
	if (input.size() > 100) {
		input = input.substr(0, 100);
	}
	for (int i = 0; i < static_cast<int>(input.size()); ++i) {
		std::cout << input[i] << "\n";
	}
	return 0;
}
