#include <iostream>
#include "template_queue.cpp"

using namespace std;

class twonumb {
public:
	twonumb(int32_t oneV = 0, int32_t twoV = 0) : one(oneV), two(twoV) 
	{	}
	int32_t one;
	int32_t two;
	void disp() {
		cout << "Two number: " << one << ", " << two << '\n';
	}
};

int main() {
	Tqueue<twonumb> numb_queue;

	for (int i = 0; i < 3; i++) {
		cout << "Enter two number:\n";
		int32_t one, two;
		cin >> one >> two;
		twonumb tn(one, two);
		numb_queue.push(tn);
	}

	cout << "\n\n";

	for (int i = 0; i < 3; i++) {
		twonumb tn;
		numb_queue.pop(tn);
		tn.disp();
	}
}