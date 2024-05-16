
#include <iostream>
#include <sstream>

typedef struct s_person {
	char name[100];
	int age;
	double height;
	double weight;
} t_person;

double calcBmi(t_person const & person) {
	return person.weight / (pow(person.height, 2));
}

void printPerson(t_person & person) {
	std::cout << "Name: " << person.name << " Alter: " << person.age \
 		<< " Gewicht: " << person.weight << " Groeße: " <<person.height << " BMI: " << calcBmi(person) << "\n";
}

void initPerson(t_person & person, int i) {
	std::string input;

	std::cout << "Name Person " << i + 1 << ": ";
	std::getline(std::cin, input);
	if (input.size() > 100) {
		input = input.substr(0, 99);
	}
	memcpy(person.name, input.c_str(), 100);
	std::cout << "Alter Person " << i + 1 << ": ";
	std::getline(std::cin, input);
	std::stringstream(input) >> person.age;
	std::cout << "Groeße der Person " << i + 1 << ": ";
	std::getline(std::cin, input);
	std::stringstream(input) >> person.height;
	std::cout << "Gewicht der Person: " << i + 1 << ": ";
	std::getline(std::cin, input);
	std::stringstream(input) >> person.weight;
}

int main() {
	t_person persons[3];

	for (int i = 0; i < 3; ++i) {
		initPerson(persons[i], i);
	}
	std::cout << "Liste der Personen\n";
	for (int i = 0; i < 3; ++i) {
		std::cout << "Person " << i + 1 << ": ";
		printPerson(persons[i]);
	}
	return 0;
}
