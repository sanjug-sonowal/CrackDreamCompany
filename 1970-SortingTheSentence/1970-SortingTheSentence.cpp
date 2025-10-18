// Last updated: 18/10/2025, 09:01:16
class Solution {
public:
    string sortSentence(string s) {
        string word = "";
        string ans = "";
        vector<string>res(10);

        for(int i = 0; i< s.length();i++){
            if(s[i] >= 48 && s[i] <= 57){
                res[s[i] - 48] = word + " ";
                word = "";
                i++;
            }else{
                word += s[i];
            }
        }

        for(string x:res){
            ans += x;
        }
        ans.pop_back();
        return ans;
    }
};