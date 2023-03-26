//https://leetcode.com/problems/container-with-most-water/
class Solution {
public:
	int maxArea(vector<int>& height) {
		int n = height.size();
		int i = 0, j = n-1;
		int maxArea = 0;
		while (i < j) {
			int h = min(height[i], height[j]);
			maxArea = max(maxArea, h * (j - i));
			while (i < j && height[i] <= h) i++;
			while (i < j && height[j] <= h) j--;
		}
		return maxArea;
	}
};