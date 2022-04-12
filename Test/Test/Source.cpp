#include <iostream>

int main() {
	std::cout << "Hello World!";
	std::cout << "\n++i\n";
	for (int i = 0; i < 10; ++i) {
		std::cout << i << "\n";
	}
	std::cout << "\ni++\n";
	for (int i = 0; i < 10; i++) {
		std::cout << i << "\n";
	}
	return 0;
}
