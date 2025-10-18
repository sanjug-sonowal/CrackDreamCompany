// Last updated: 18/10/2025, 09:02:36
class Solution {
public:
    string getHappyString(int n, int k) {
        int total = 3 * (1 << (n - 1)); // Total happy strings = 3 × 2^(n-1)
        if (k > total) return ""; // If k is out of bounds, return ""

        string result;
        vector<char> choices = {'a', 'b', 'c'};
        k--; // Convert to 0-based index

        // Select first character based on k
        int blockSize = total / 3; // Size of each first-letter group
        int firstIndex = k / blockSize;
        result.push_back(choices[firstIndex]);
        k %= blockSize; // Reduce k to be within this block

        // Generate remaining characters
        for (int i = 1; i < n; i++) {
            blockSize /= 2; // Each next level has half choices
            char lastChar = result.back();

            // Find the next valid character
            char firstOption = (lastChar == 'a') ? 'b' : 'a';
            char secondOption = (lastChar == 'c') ? 'b' : 'c';

            if (k < blockSize) {
                result.push_back(firstOption);
            } else {
                result.push_back(secondOption);
                k -= blockSize; // Reduce k further
            }
        }

        return result;
    }
};
