// Last updated: 18/10/2025, 09:00:57
class Solution {
 public:
  string reversePrefix(string word, char ch) {
    reverse(word.begin(), word.begin() + word.find(ch) + 1);
    return word;
  }
};