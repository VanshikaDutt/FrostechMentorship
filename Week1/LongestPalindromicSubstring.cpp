//https://leetcode.com/problems/longest-palindromic-substring/
class Solution {
public:
	string longestPalindrome(string s) {
		int n = s.size();
		vector<vector<bool>> dp(n, vector<bool>(n, false));
		int start = 0, end = 0;
		for (int i = n - 1; i >= 0; i--) {
			for (int j = i; j < n; j++) {
				dp[i][j] = (s[i] == s[j] && (j - i < 2 || dp[i+1][j-1]));
				if (dp[i][j] && j - i > end - start) {
					start = i;
					end = j;
				}
			}
		}
		return s.substr(start, end - start + 1);
	}
};