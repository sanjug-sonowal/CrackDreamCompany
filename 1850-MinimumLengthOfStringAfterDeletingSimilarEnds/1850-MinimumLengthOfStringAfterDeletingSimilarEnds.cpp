// Last updated: 18/10/2025, 09:01:30
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int minimumLength(string s) {
        int L = 0, R = s.size() - 1;
        while (L < R && s[L] == s[R]) {
            char ch = s[L];
            while (L <= R && s[L] == ch) ++L;
            while (L <= R && s[R] == ch) --R;
        }
        return R - L + 1;
    }
};