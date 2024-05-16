
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
	std::cout << "Recursiv current n: " << n << " current sum: " << sum << "\n";

	if (n <= 0) {
		return sum;
	}
	sum *= n;
	return calcFacultyRec(n - 1, sum);
}

int main() {
	std::cout << "faculty iterativ" << 1 << ": " << calcFacultyIter(1) << "\n";
	std::cout << "faculty iterativ" << 5 << ": " << calcFacultyIter(5) << "\n";
	std::cout << "faculty iterativ" << 20 << ": " << calcFacultyIter(20) << "\n";
	std::cout << "---------------\n\n";
	std::cout << "faculty recursiv" << 2 << ": " << calcFacultyRec(2, 1) << "\n";
	std::cout << "---------------\n\n";
	std::cout << "faculty recursiv" << 5 << ": " << calcFacultyRec(5, 1) << "\n";
	std::cout << "---------------\n\n";
	std::cout << "faculty recursiv" << 6 << ": " << calcFacultyRec(6, 1) << "\n";
	std::cout << "---------------\n\n";
	return 0;
}
