
#include <iostream>

void printVec(const std::vector<int> & vec) {
	std::vector<int>::const_iterator it;

	std::cout << "Zerlegung: ";
	for (it = vec.begin(); it!= vec.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << "\n";
}

int isPrime(int n) {
	int i = 1;

	if (n == 1 || n == -1)
		return 0;
	if (n == 2)
		return 1;
	while (i += 2, i < n) {
		if (n % i == 0)
			return 0;
	}
	return 1;
}

int main() {
	int num, isNegativ = 0, quotient = 1, i = 1;
	std::vector<int> quotients;

	std::cout << "Zu zerlgende Zahl eingeben: ";
	std::cin >> num;
	if (num < 0) {
		num = num * -1;
		isNegativ = 1;
	}
	while (++i, quotient < num) {
		while (num % (quotient * i) == 0 && isPrime(i)) {
			quotient *= i;
			isNegativ ? quotients.push_back(i * -1) : quotients.push_back(i);
		}
	}
	printVec(quotients);
	return 0;
}
