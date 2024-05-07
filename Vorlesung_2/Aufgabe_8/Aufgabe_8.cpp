#include <iostream>

int main() {
	std::string name1, name2;

	std::cout << "Bitte den ersten Namen eingeben: ";
	std::getline(std::cin, name1);
	std::cout << "Bitte den ersten Namen eingeben: ";
	std::getline(std::cin, name2);
	if (name1.size() > 100)
		name1 = name1.substr(0, 100);
	if (name2.size() > 100)
		name2 = name2.substr(0, 100);
	if (strcmp(name1.c_str(), name2.c_str()) < 0) {
		std::cout << name1 << name2 << "\n";
	}
	else {
		std::cout << name2 << name1 << "\n";
	}
	return 0;
}
