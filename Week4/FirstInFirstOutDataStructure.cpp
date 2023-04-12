//https://leetcode.com/explore/learn/card/queue-stack/228/first-in-first-out-data-structure/1337/
//Design Circular Queue
class MyCircularQueue {
private:
	int *data;
	int size, front, rear;
public:
	MyCircularQueue(int k) {
		data = new int[k];
		size = k;
		front = rear = -1;
	}
	bool enQueue(int value) {
		if (isFull()) return false;
		if (isEmpty()) front = 0;
		rear = (rear + 1) % size;
		data[rear] = value;
		return true;
	}
	bool deQueue() {
		if (isEmpty()) return false;
		if (front == rear) front = rear = -1;
		else front = (front + 1) % size;
		return true;
	}
	int Front() {
		if (isEmpty()) return -1;
		return data[front];
	}
	int Rear() {
		if (isEmpty()) return -1;
		return data[rear];
	}
	bool isEmpty() {
		return front == -1 && rear == -1;
	}
	bool isFull() {
		return (rear + 1) % size == front;
	}
};