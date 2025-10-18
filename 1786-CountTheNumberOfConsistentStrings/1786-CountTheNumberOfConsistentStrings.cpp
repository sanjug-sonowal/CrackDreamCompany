// Last updated: 18/10/2025, 09:01:42
class Solution {
 public:
  int countConsistentStrings(string allowed, vector<string>& words) {
    return accumulate(words.begin(), words.end(), 0,
                      [&allowed](int subtotal, const string& word) {
      return subtotal + ranges::all_of(word, [&allowed](char c) {
        return allowed.find(c) != string::npos;
      });
    });
  }
};