
#include <iostream>
#include <sstream>

void initVec(int * vec, int len) {
	std::string input;

	for (int i = 0; i < len; ++i) {
		std::cout << "Vektor Element " << i << ": ";
		std::getline(std::cin, input);
		std::stringstream(input) >> vec[i];
	}
}

long int calculateScalar(const int *vec1, const int *vec2, int len) {
	long int sum = 0;

	for (int i = 0; i < len; ++i) {
		sum += vec1[i] * vec2[2];
	}
	return sum;
}

int main() {
	std::string input;
	int *vec1, *vec2;
	long long int lenIn;

	std::cout << "Bitte Vektorgröße eingeben: ";
	std::getline(std::cin, input);
	std::stringstream(input) >> lenIn;
	if (lenIn < 1 || lenIn > INT_MAX) {
		std::cout << "ERROR: Invalid input\n";
		return 0;
	}
	vec1 = (int*)calloc(sizeof(int), lenIn);
	if (!vec1) {
		return perror("malloc: "), 1;
	}
	vec2 = (int*)calloc(sizeof(int), lenIn);
	if (!vec2) {
		free(vec1);
		return perror("malloc: "), 1;
	}
	std::cout << "allocated vecs of len: " << lenIn << "\n";
	initVec(vec1, lenIn);
	initVec(vec2, lenIn);
	std::cout << "SKP von v1 & v2 = " << calculateScalar(vec1, vec2, lenIn) << "\n";
	free(vec1);
	free(vec2);
	return 0;
}
