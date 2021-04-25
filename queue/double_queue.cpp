#include "double_queue.h"
#include <iostream>
#include <exception>

double_queue::double_queue(int max_size) {
	items = new double[max_size];					//создать массив
	front = 0;										//начало и конец очереди на нуле
	rear = 0;
	MAX = max_size;
	empty = true;									//очередь пуста
}
void double_queue::insert(double item) {
	if (isFull()) {									//если очередь полна, вставить нельзя
		std::cout << "Queue is full\n";
		return;
	}
	if(empty) empty = false;						//если произошла вставка, то очередь перестала быть пустой
	items[rear++] = item;							//вставка
	if (rear == MAX) rear = 0;						//циклическая очередь
}
double double_queue::extract() {
	if(isEmpty()) {									//если очередь пуста, извлекать нечего
		std::cout << "Queue is empty\n"; 
		throw std::domain_error("messege from throw: Queue is empty\n");	//исключение
	}
	int auxilliary_index = front;					//перед return необходимо сделать некоторые проверки
	++front;
	if (front == MAX) front = 0;					//циклическая очередь
	if (front == rear) empty = true;				//если начало и конец сравнялись, то очередь пуста
	return items[auxilliary_index];					//возвращение первого в очереди
}

int double_queue::size() {
	return front > rear ? front - rear : MAX - (rear - front);
}

double_queue::~double_queue() { delete[] items; }