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
	int arr[3] = { 0, 2, 6 };
	for (int i = 0; i < std::size(arr); ++i) {
		std::cout << arr[i] << "\n";
	}
	return 0;
}
