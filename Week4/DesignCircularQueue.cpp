//https://leetcode.com/problems/design-circular-deque/submissions/933072419/
class MyCircularDeque {
private:
	vector<int> deque;
	int front;
	int rear;
	int size;
public:
	MyCircularDeque(int k) {
		deque.resize(k);
		front = -1;
		rear = -1;
		size = k;
	}
	bool insertFront(int value) {
		if (isFull()) {
			return false;
		}
		if (isEmpty()) {
			front = 0;
			rear = 0;
		} else {
			front = (front - 1 + size) % size;
		}
		deque[front] = value;
		return true;
	}
	bool insertLast(int value) {
		if (isFull()) {
			return false;
		}
		if (isEmpty()) {
			front = 0;
			rear = 0;
		} else {
			rear = (rear + 1) % size;
		}
		deque[rear] = value;
		return true;
	}
	bool deleteFront() {
		if (isEmpty()) {
			return false;
		}
		if (front == rear) {
			front = -1;
			rear = -1;
		} else {
			front = (front + 1) % size;
		}
		return true;
	}
	bool deleteLast() {
		if (isEmpty()) {
			return false;
		}
		if (front == rear) {
			front = -1;
			rear = -1;
		} else {
			rear = (rear - 1 + size) % size;
		}
		return true;
	}
	int getFront() {
		return isEmpty() ? -1 : deque[front];
	}
	int getRear() {
		return isEmpty() ? -1 : deque[rear];
	}
	bool isEmpty() {
		return front == -1 && rear == -1;
	}
	bool isFull() {
		return (rear + 1) % size == front;
	}
};