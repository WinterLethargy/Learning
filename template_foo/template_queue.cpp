#include <iostream>

using namespace std;

template <typename T>
class item {
public:
	item(T& dt) : previous(nullptr), data(dt)
	{	}
	T data;
	item* next;				// у первого линка списка равен nullptr
							// вообще-то не нужен... здесь используется только в pop(), чтобы не искать с конца очереди первый
							// item для удаления. деструтор Tqueue() можно переписать, используя previous
	item* previous;			// у последнего линка равен nullptr
	~item() {
		if (previous)
		previous->next = nullptr;
	}
};

template<typename T>
class Tqueue {
private:
	item<T>* first;
	item<T>* last;
public:
	Tqueue() : first(nullptr), last(nullptr)
	{	}
	void push(T& dt) {
		if (!last) {
			last = new item<T>(dt);
			last->next = nullptr;
			first = last;
		}
		else {
			last->previous = new item<T>(dt);
			(*last).previous->next = last;
			last = last->previous;
		}
	}
	void pop(T& vl) {
		if (!first) {
			cout << "Sorry, queue is empty.";
			return;
		}
		vl = first->data;
		if (first->previous) {
			first = first->previous;
			delete first->next;
		}
		else {
			delete first;
			first = nullptr;
			last = nullptr;
		}
	}
	~Tqueue() {
		if (!last) return;


		item<T>* lastDel, * penultimateDel;
		penultimateDel = last;
		lastDel = last->next;

		while (true) {
			delete penultimateDel;
			if (lastDel) {
				penultimateDel = lastDel;
				lastDel = lastDel->next;
			}
			else return;
		}
	}
};