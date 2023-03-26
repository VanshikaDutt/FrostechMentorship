//https://leetcode.com/problems/substring-with-concatenation-of-all-words/
class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> result;
		int n = s.length(), cnt = words.size();
		if (n == 0 || cnt == 0) {
			return result;
		}
		unordered_map<string, int> counts;
		for (const string& word : words) {
			counts[word]++;
		}
		int len = words[0].length();
		for (int i = 0; i < len; i++) {
			int left = i, count = 0;
			unordered_map<string, int> seen;
			for (int j = i; j <= n - len; j += len) {
				string word = s.substr(j, len);
				if (counts.count(word)) {
					seen[word]++;
					count++;
					while (seen[word] > counts[word]) {
						string temp = s.substr(left, len);
						seen[temp]--;
						count--;
						left += len;
					}
					if (count == cnt) {
						result.push_back(left);
						string temp = s.substr(left, len);
						seen[temp]--;
						count--;
						left += len;
					}
				} else {
					seen.clear();
					count = 0;
					left = j + len;
				}
			}
		}
		return result;
	}
};