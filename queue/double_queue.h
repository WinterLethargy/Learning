#pragma once
class double_queue
{
private:
	double* items;
	int front;
	int rear;
	int MAX;
	bool empty;
public:
	double_queue(int max_size);
	void insert(double item);
	double extract();
	bool isEmpty() { return empty; }
	int size();
	bool isFull() {	return ((front == rear) && (!empty)); }
	~double_queue();
};

