// Last updated: 18/10/2025, 09:00:17
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> diff(n + 1, 0); // Difference array of size n+1

        // Populate the difference array based on shifts
        for (const auto& shift : shifts) {
            int start = shift[0], end = shift[1], direction = shift[2];
            int val = (direction == 1) ? 1 : -1;
            diff[start] += val;
            if (end + 1 < n) diff[end + 1] -= val;
        }

        // Compute prefix sum to get the net effect of shifts
        int netShift = 0;
        for (int i = 0; i < n; ++i) {
            netShift += diff[i];
            // Apply the shift to the character, wrapping around using modulo 26
            int shiftAmount = (netShift % 26 + 26) % 26; // Ensure non-negative shift
            s[i] = 'a' + (s[i] - 'a' + shiftAmount) % 26;
        }

        return s;
    }
};
