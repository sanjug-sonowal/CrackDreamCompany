// Last updated: 18/10/2025, 09:04:53
class Solution {
public:
    string toLowerCase(string s) {
        string ans = "";
        for(int i = 0; i< s.length();i++){
            if(s[i] >= 'A' && s[i] <= 'Z'){
                ans += (s[i] - 'A')+'a';
            }else{
                ans += s[i];
            }
        }
        return ans;
    }
};