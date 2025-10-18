// Last updated: 18/10/2025, 08:59:05
class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int count = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isPrefixAndSuffix(words[i], words[j])) {
                    count++;
                }
            }
        }

        return count;
    }

private:
    bool isPrefixAndSuffix(const string& str1, const string& str2) {
        int len1 = str1.size();
        int len2 = str2.size();

        // Check if str1 is both a prefix and a suffix of str2
        if (len1 > len2) return false;
        if (str2.substr(0, len1) == str1 && str2.substr(len2 - len1) == str1) {
            return true;
        }
        return false;
    }
};