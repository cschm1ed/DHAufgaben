
#include <iostream>

void getVecInput(std::vector<double> & vec, int size) {
	double input;

	for (int i = 0; i < size; ++i) {
		std::cout << i + 1 << ": ";
		std::cin >> input;
		vec.push_back(input);
	}
}

double getScalar(const std::vector<double> vec1, const std::vector<double> vec2, int size) {
	double scalar = 0;

	for (int i = 0; i < size; ++i) {
		scalar += vec1[i] * vec2[i];
	}
	return scalar;
}

int main() {
	int size;
	std::vector<double> vec1, vec2;

	std::cout << "Länge der Vektoren eingeben (1-100)\n";
	std::cin >> size;
	if (size < 1 || size > 100) {
		std::cout << "ERROR: die Länge muss min 1 und max 100 betragen\n";
	}
	std::cout << "Vektor 1 eingeben: \n";
	getVecInput(vec1, size);
	std::cout << "Vektor 2 eingeben: \n";
	getVecInput(vec2, size);
	std::cout << "Skalarprodukt: " << getScalar(vec1, vec2, size) << "\n";
	return 0;
}
