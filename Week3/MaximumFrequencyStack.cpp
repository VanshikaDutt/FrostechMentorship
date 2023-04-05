//https://leetcode.com/problems/maximum-frequency-stack/
class FreqStack {
public:
	FreqStack() {
		max_freq = 0;
	}

	void push(int val) {
		freq[val]++;
		max_freq = max(max_freq, freq[val]);
		freq_stack[freq[val]].push(val);
	}

	int pop() {
		int val = freq_stack[max_freq].top();
		freq_stack[max_freq].pop();
		freq[val]--;
		if (freq_stack[max_freq].empty()) {
			max_freq--;
		}
		return val;
	}

private:
	unordered_map<int, int> freq;
	unordered_map<int, stack<int>> freq_stack;
	int max_freq;
};
