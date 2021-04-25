#include "double_queue.h"
#include <iostream>
#include <exception>

double_queue::double_queue(int max_size) {
	items = new double[max_size];					//������� ������
	front = 0;										//������ � ����� ������� �� ����
	rear = 0;
	MAX = max_size;
	empty = true;									//������� �����
}
void double_queue::insert(double item) {
	if (isFull()) {									//���� ������� �����, �������� ������
		std::cout << "Queue is full\n";
		return;
	}
	if(empty) empty = false;						//���� ��������� �������, �� ������� ��������� ���� ������
	items[rear++] = item;							//�������
	if (rear == MAX) rear = 0;						//����������� �������
}
double double_queue::extract() {
	if(isEmpty()) {									//���� ������� �����, ��������� ������
		std::cout << "Queue is empty\n"; 
		throw std::domain_error("messege from throw: Queue is empty\n");	//����������
	}
	int auxilliary_index = front;					//����� return ���������� ������� ��������� ��������
	++front;
	if (front == MAX) front = 0;					//����������� �������
	if (front == rear) empty = true;				//���� ������ � ����� ����������, �� ������� �����
	return items[auxilliary_index];					//����������� ������� � �������
}

int double_queue::size() {
	return front > rear ? front - rear : MAX - (rear - front);
}

double_queue::~double_queue() { delete[] items; }