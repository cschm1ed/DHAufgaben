
#include <iostream>

int main() {
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			std::cout << i * 10 + j << " ";
		}
		std::cout << "\n";
	}
}
