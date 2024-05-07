
#include <iostream>
#include <random>

double **alloc2dArray(int rows, int columns) {
	double **matrix;

	matrix = new double*[rows];
	for (int i = 0; i < rows; ++i) {
		matrix[i] = new double[columns];
	}
	return matrix;
}

void fillMatrixRandom(double **matrix, int rows, int cols) {
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			matrix[i][j] = std::rand() % 10;
		}
	}
}

void printMatrix(double **matrix, int rows, int cols) {
	std::cout << "\n";
	for (int i = 0; i < rows; ++i) {
		std::cout << "[";
		for (int j = 0; j < cols; ++j) {
			std::cout << matrix[i][j];
			if (j < cols - 1)
				std::cout << " ";
		}
		std::cout << "]\n";
	}
	std::cout << "\n";
}

double **multiply2dMatrix(double **m1, double **m2, std::pair<int, int> dims1, std::pair<int, int> dims2) {
	double **resulting = alloc2dArray(dims1.first, dims2.second);
	double sum;

	if (dims1.second != dims2.first) {
		return nullptr ;
	}
	for (int i = 0; i < dims1.first; ++i) {
		for (int j = 0; j < dims2.second; ++j) {
			sum = 0;
			for (int k = 0; k < dims1.second; k++) {
				sum += m1[i][k] * m2[k][j];
			}
			resulting[i][j] = sum;
		}
	}
	return resulting;
}

int main() {
	const int rowsM1 = 3, columnsM1 = 4, columnsM2 = 2;
	double **m1, **m2, **m3;

	std::srand(std::time(nullptr));
	m1 = alloc2dArray(rowsM1, columnsM1);
	m2 = alloc2dArray(columnsM1, columnsM2);
	fillMatrixRandom(m1, rowsM1, columnsM1);
	fillMatrixRandom(m2, columnsM1, columnsM2);
	std::cout << "Matrix1: ";
	printMatrix(m1, rowsM1, columnsM1);
	std::cout << "Matrix2: ";
	printMatrix(m2, columnsM1, columnsM2);
	m3 = multiply2dMatrix(m1, m2, std::pair<int, int> (rowsM1, columnsM1), std::pair<int, int> (columnsM1, columnsM2));
	if (m3 == nullptr)
		return 1;
	std::cout << "Ergebnis: ";
	printMatrix(m3, rowsM1, columnsM2);
	return 0;
}
