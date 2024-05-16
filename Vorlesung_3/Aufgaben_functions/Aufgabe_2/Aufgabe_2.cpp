
#include <iostream>

int isPrime(int n) {
	int i = 1;

	if (n == 1 || n == -1 || n % 2 == 0)
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
	for (int i = 2; i <= 1000; ++i) {
		if (isPrime(i))
			std::cout << i << " is a prime!\n";
	}
}
