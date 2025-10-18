// Last updated: 18/10/2025, 08:58:59
class Solution {
 public:
  int scoreOfString(string s) {
    int ans = 0;

    for (int i = 1; i < s.length(); ++i)
      ans += abs(s[i] - s[i - 1]);

    return ans;
  }
};