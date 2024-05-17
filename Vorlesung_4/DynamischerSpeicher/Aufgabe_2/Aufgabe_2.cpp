
#include <iostream>
#include <sstream>

int ist_primzahl(int n) {
	int i = 1;

	if (n == 2)
		return 1;
	if (n == 1 || n == -1 || n % 2 == 0)
		return 0;
	while (i += 2, i < n) {
		if (n % i == 0)
			return 0;
	}
	return 1;
}

void ausgabe_primzahlliste(int* liste, int anzahl) {
	for (int i = 0; i < anzahl; ++i) {
		std::cout << "Element " << i << ": " << (int)liste[i] << "\n";
	}
}

int main() {
	int *listOfPrimes = NULL, maxNum, len = 0;
	std::string input;

	std::cout << "Höchste zu prüfende Zahl eingeben: ";
	std::getline(std::cin, input);
	std::stringstream(input) >> maxNum;
	if (maxNum < 2) {
		std::cout << "Keine Primzahl gefunden\n";
		return 0;
	}
	for (int i = 1; i < maxNum; ++i) {
		if (ist_primzahl(i)) {
			listOfPrimes = (int*)realloc(listOfPrimes, (++len) * sizeof(int));
			if (!listOfPrimes)
				return perror("realloc: "), 1;
			listOfPrimes[len - 1] = i;
		}
	}
	ausgabe_primzahlliste(listOfPrimes, len);
	return 0;
}
