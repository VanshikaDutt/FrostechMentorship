//https://leetcode.com/problems/two-sum/
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> hash_map;
		for (int i = 0; i < nums.size(); i++) {
			int complement = target - nums[i];
			if (hash_map.find(complement) != hash_map.end()) {
				return { hash_map[complement], i };
			}
			hash_map[nums[i]] = i;
		}
		return {};
	}
};