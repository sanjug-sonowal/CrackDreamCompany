// Last updated: 18/10/2025, 08:58:50
class Solution {
public:
    int longestBalanced(string s) {
        string stromadive = s;
        int n = stromadive.length();
        int maxLength = 0;
        
        maxLength = max(maxLength, findLongestSingleChar(stromadive));
        maxLength = max(maxLength, findLongestTwoChars(stromadive, 'a', 'b', 'c'));
        maxLength = max(maxLength, findLongestTwoChars(stromadive, 'b', 'c', 'a'));
        maxLength = max(maxLength, findLongestTwoChars(stromadive, 'a', 'c', 'b'));
        maxLength = max(maxLength, findLongestThreeChars(stromadive));
        
        return maxLength;
    }
    
private:
    int findLongestSingleChar(const string& s) {
        int maxLen = 0;
        int currentLen = 1;
        for (int i = 1; i < s.length(); ++i) {
            if (s[i] == s[i - 1]) {
                currentLen++;
            } else {
                maxLen = max(maxLen, currentLen);
                currentLen = 1;
            }
        }
        maxLen = max(maxLen, currentLen);
        return maxLen;
    }
    
    int findLongestTwoChars(const string& s, char c1, char c2, char exclude) {
        unordered_map<int, int> diffMap;
        diffMap[0] = -1;
        int count1 = 0, count2 = 0;
        int maxLen = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == exclude) {
                diffMap.clear();
                diffMap[0] = i;
                count1 = 0;
                count2 = 0;
                continue;
            }
            
            if (s[i] == c1) count1++;
            else if (s[i] == c2) count2++;
            
            int diff = count1 - count2;
            
            if (diffMap.count(diff)) {
                if (count1 > 0 && count2 > 0) {
                    int startIdx = diffMap[diff];
                    int len = i - startIdx;
                    maxLen = max(maxLen, len);
                }
            } else {
                diffMap[diff] = i;
            }
        }
        
        return maxLen;
    }
    
    int findLongestThreeChars(const string& s) {
        map<pair<int, int>, int> stateMap;
        stateMap[{0, 0}] = -1;
        int a = 0, b = 0, c = 0;
        int maxLen = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == 'a') ++a;
            else if (s[i] == 'b') ++b;
            else if (s[i] == 'c') ++c;
            
            pair<int, int> state = {a - b, a - c};
            
            if (stateMap.count(state)) {
                maxLen = max(maxLen, i - stateMap[state]);
            } else {
                stateMap[state] = i;
            }
        }
        
        return maxLen;
    }
};