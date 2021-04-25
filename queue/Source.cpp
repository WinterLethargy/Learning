#include <iostream>
#include "double_queue.h"

int main() {
	double_queue wait(4);
	wait.insert(12.0);
	wait.insert(23.0);
	wait.insert(31.0);
	wait.insert(44.0);
	wait.insert(57.0);
	std::cout << "wait.extract(): " << wait.extract();
	std::cout << ' ' << wait.extract();
	std::cout << ' ' << wait.extract() << '\n';

	//std::cout << "wait.extract(): " << wait.extract() << ' ' << wait.extract() << ' ' << wait.extract();
	//печатает в обратном порядке 31 23 12

	try {
		wait.insert(6.0);
		wait.insert(7.0);
		wait.insert(8.0);
		std::cout << "wait.extract(): " << wait.extract() << ' ';
		std::cout << wait.extract() << ' ';
		std::cout << wait.extract() << ' ';
		std::cout << wait.extract() << " the queue must be empty\n";
		std::cout << std::flush << wait.extract();
	}
	catch (std::exception& exp) {
		std::cout << exp.what();
	}
}