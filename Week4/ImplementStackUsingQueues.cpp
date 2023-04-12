//https://leetcode.com/problems/implement-stack-using-queues/
class MyStack {
private:
	queue<int> q1, q2;
	int top_elem;
public:
	MyStack() {}
	void push(int x) {
		q1.push(x);
		top_elem = x;
	}
	int pop() {
		while (q1.size() > 1) {
			top_elem = q1.front();
			q2.push(top_elem);
			q1.pop();
		}
		int res = q1.front();
		q1.pop();
		swap(q1, q2);
		return res;
	}
	int top() {
		return top_elem;
	}
	bool empty() {
		return q1.empty() && q2.empty();
	}
};