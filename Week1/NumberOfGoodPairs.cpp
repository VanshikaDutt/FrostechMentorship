//https://leetcode.com/problems/number-of-good-pairs/
class Solution {
public:
	int numIdenticalPairs(vector<int>& nums) {
		int n = nums.size();
		int count = 0;
		unordered_map<int, int> freq;
		for (int i = 0; i < n; i++) {
			count += freq[nums[i]]++;
		}
		return count;
	}
};
