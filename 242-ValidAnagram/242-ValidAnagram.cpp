// Last updated: 18/10/2025, 09:06:22
class Solution {
public:
    bool isAnagram(string s, string t) {
    if(s.length() != t.length())
    return false;

        vector<int>freq(26,false);
        for(int i = 0; i < s.length();i++){
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }
        for(int i = 0;i<26;i++){
            if(freq[i] != 0){
                return false;
            }
        }
        return true;
    }
};