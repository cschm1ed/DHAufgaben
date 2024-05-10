
#include <iostream>
#include <sstream>

typedef struct s_person {
	char name[100];
	int age;
	double height;
} t_person;



int main() {
	t_person persons[3];
	std::string input;

	for (int i = 0; i < 3; ++i) {
		std::cout << "Name Person " << i + 1<< ": ";
		std::getline(std::cin, input);
		if (input.size() > 100) {
			input = input.substr(0, 99);
		}
		memcpy(persons[i].name, input.c_str(), 100);
		std::cout << "Alter Person " << i + 1 << ": ";
		std::getline(std::cin, input);
		std::stringstream(input) >> persons[i].age;
		std::cout << "Groeße der Person " << i + 1 << ": ";
		std::getline(std::cin, input);
		std::stringstream(input) >> persons[i].height;
	}
	std::cout << "Liste der Personen\n";
	for (int i = 0; i < 3; ++i) {
		std::cout << "Person " << i + 1 << "; Name: " << persons[i].name << " Alter: " << persons[i].age \
			<< " Groeße: " << persons[i].height << "\n";
	}
	return 0;
}
