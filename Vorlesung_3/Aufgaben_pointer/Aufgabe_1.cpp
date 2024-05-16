
#include <iostream>

void ausgabe_inhalt(const int* const ptr) {
	if (!ptr) {
		std::cout << "ERRROR: got nullptr as address\n";
		return ;
	}
	std::cout << "Pointer points to value of: " << *ptr << "\n";
}

int aendere_wert(int* const ptr, const int wert) {
	if (ptr == NULL) {
		return 1;
	}
	*ptr = wert;
	return 0;
}

int main() {
	int zahl = 5;
	int *ptr_zahl = NULL;

	ptr_zahl = &zahl;
	ausgabe_inhalt(ptr_zahl);
	ausgabe_inhalt(&zahl);
	if (aendere_wert(ptr_zahl, 23)) {
		std::cout << "ERROR: aendere_wert() got nullptr\n";
	} else {
		ausgabe_inhalt(ptr_zahl);
	}
	return 0;
}
