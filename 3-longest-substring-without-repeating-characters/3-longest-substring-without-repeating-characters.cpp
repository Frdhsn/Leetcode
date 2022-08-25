class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int n = s.size(), res = 0;
		for (int i = 0; i < n; i++) {
			vector<int>f(500);
			int cnt = 0;
			for (int j = i; j < min(i + 95, n); j++) {
				if (f[s[j]]) {
					break;
				}
				f[s[j]]++;
				cnt++;
			}
			res = max(res, cnt);
		}
		return res;
	}
};