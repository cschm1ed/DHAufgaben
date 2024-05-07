
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
	std::cout << "{";
	for (int i = 0; i < rows; ++i) {
		std::cout << "[";
		for (int j = 0; j < rows; ++j) {
			std::cout << matrix[i][j] << "";
		}
		std::cout << "]\n";
	}
}

double **multiply2dMatrix(double **m1, double **m2, std::pair<int, int> dims1, std::pair<int, int> dims2) {
	double **resulting = alloc2dArray(dims2.second, dims1.first);
	double sum;

	if (dims1.second != dims2.first) {
		return NULL ;
	}
	for (int i = 0; i < dims2.second; ++i) {
		sum = 0;
		for (int j = 0; j < dims1.first; ++j) {

		}
	}
	return resulting;
}

int main() {
	const int rowsM1 = 3, columnsM1 = 4, columnsM2 = 2;
	double **m1, **m2, **m3;

	std::srand(std::time(NULL));
	m1 = alloc2dArray(rowsM1, columnsM1);
	m2 = alloc2dArray(columnsM1, columnsM2);
	fillMatrixRandom(m1, rowsM1, columnsM1);
	fillMatrixRandom(m2, columnsM1, columnsM2);

}
