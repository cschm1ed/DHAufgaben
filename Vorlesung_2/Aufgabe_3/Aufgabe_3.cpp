#include <iostream>

enum e_state {
	AWAIT_H = 1,
	AWAIT_A = 2,
	AWAIT_H_OR_END = 3
};

void printError() {
	std::cout << "Error: given Word is invalid\n";
}

void printSuccess() {
	std::cout << "Success word is valid!\n";
}

int main() {
	e_state state = AWAIT_H;
	char input;
	std::cout << "Bitte nacheinander Zeichen eingeben: \n";

	while (1) {
		std::cin >> input;
		switch (state) {
			case (AWAIT_H):
				if (input != 'h')
					return printError(), 1;
				state = AWAIT_A;
				break;
			case (AWAIT_A):
				if (input != 'a')
					return printError(), 1;
				state = AWAIT_H_OR_END;
				break;
			case (AWAIT_H_OR_END):
				if (input == 'h') {
					state = AWAIT_A;
					break;
				} else if (input == '!') {
					return printSuccess(), 0;
				} else {
					return printError(), 1;
				}
				break;
			default:
				break ;
		}
	}
}
