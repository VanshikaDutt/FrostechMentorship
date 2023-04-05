//https://leetcode.com/problems/min-stack/

class MinStack {
private:
	stack<int> s; // main stack to store elements
	stack<int> minStack; // stack to store minimum element at the top

public:
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int val) {
		s.push(val);

		// if min stack is empty or new value is less than or equal to the current minimum
		if(minStack.empty() || val <= minStack.top()) {
			minStack.push(val);
		}
	}

	void pop() {
		// if top element of main stack is equal to top element of min stack, remove it
		if(s.top() == minStack.top()) {
			minStack.pop();
		}
		s.pop();
	}

	int top() {
		return s.top();
	}

	int getMin() {
		return minStack.top();
	}
};