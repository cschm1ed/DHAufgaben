#include <iostream>

int main() {
	const std::string vowels = "aeiou";
	const std::string consonants = "bcdfghjklmnpqrstvwxyz";
	char input;

	std::cout << "Bitte Buchstaben eingeben: ";
	std::cin >> input;
	if (vowels.find(tolower(input)) != std::string::npos) {
		std::cout << "Vokal\n";
	} else if (consonants.find(tolower(input)) != std::string::npos) {
		std::cout << "Konsonant\n";
	} else {
		std::cout << "Weder noch\n";
	}
	return 0;
}
