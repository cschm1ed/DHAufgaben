
#include <iostream>
#include <sstream>

unsigned long long int calcFacultyIter(int n) {
	long long int sum = 1;

	while (n > 0) {
		sum *= n;
		--n;
	}
	return sum;
}

unsigned long long int calcFacultyRec(int n, unsigned long long int sum) {
	if (n <= 0) {
		return sum;
	}
	sum *= n;
	return calcFacultyRec(n - 1, sum);
}

int main() {
	std::string input;
	int n;
	bool isNegativ = false;

	std::cout << "input number smaller than 21 and bigger than -21 :\n";
	std::getline(std::cin, input);
	std::stringstream(input) >> n;
	if (n < 0) {
		isNegativ = true;
		n =  n * -1;
	}
	if (n > 20) {
		std::cout << "ERROR: input number to large\n";
		return 1;
	}
	std::cout << "faculty of " << n << ":\n";
	if (!isNegativ) {
		std::cout << "iterativ: " << calcFacultyIter(n) << "\n";
		std::cout << "recursiv: " << calcFacultyRec(n, 1) << "\n";
	}
	else {
		std::cout << "iterativ: -" << calcFacultyIter(n) << "\n";
		std::cout << "recursiv: -" << calcFacultyRec(n, 1) << "\n";
	}
	return 0;

}
