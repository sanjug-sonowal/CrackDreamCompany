// Last updated: 18/10/2025, 09:02:02
class Solution {
 public:
  string makeGood(string s) {
    string ans;
    for (const char c : s)
      if (!ans.empty() && isBadPair(ans.back(), c))
        ans.pop_back();
      else
        ans.push_back(c);
    return ans;
  }

  bool isBadPair(char a, char b) {
    return a != b && tolower(a) == tolower(b);
  }
};