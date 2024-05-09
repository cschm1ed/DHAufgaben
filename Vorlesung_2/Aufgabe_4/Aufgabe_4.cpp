#include <iostream>

double getAverage(double *arr, int size) {
	double sum = 0;

	for (int i = 0; i < size; ++i) {
		sum += arr[i];
	}
	return sum / size;
}

double getMedian(double *arr, int size) {
	std::sort(arr, arr + size);

	if (size % 2 == 0) {
		return (arr[size / 2] + arr[size / 2 - 1]) / 2;
	}
	return arr[size / 2];
}

void printArray(double *array, int size) {
	for (int i = 0; i < size; ++i) {
		std::cout << array[i] << " ";
	}
	std::cout << "\n";
}

int main() {
	int size;
	double *array = nullptr;

	std::cout << "Bitte länge der Zahlenliste eingeben: ";
	std::cin >> size;
	if (size < 1 || size > 100) {
		return std::cout << "ERROR: mindestens 1 oder maximal 100 Zahlen möglich\n", 1;
	}
	array = new double[size];
	if (array == nullptr)
		return perror("new: "), 1;
	std::cout << "Bitte " << size << " Zahlen eingeben\n";
	for (int i = 0; i < size; ++i) {
		std::cout << i + 1 << ": ";
		std::cin >> array[i];
	}
	std::cout << "Eingegebene Zahlen: \n";
	printArray(array, size);
	std::cout << "Mittelwert: " << getAverage(array, size) << "\n";
	std::cout << "Median: " << getMedian(array, size) << "\n";
	delete array;
}
