// Last updated: 18/10/2025, 09:06:57
class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string ans = "";
        int start = 0;
        int end = n - 1;
        while(start < end){
            char temp = s[start];
            s[start] = s[end];
            s[end] = temp;
            start++;
            end--;
        }

        for(int i = 0; i<n;i++){
            string word = "";
            while(i < n && s[i] != ' '){
                word += s[i];
                i++;
            }

            start = 0;
            end = word.length() - 1;
            while(start < end){
                char temp = word[start];
                word[start] = word[end];
                word[end] = temp;
                start++;
                end--;
            }

            if(word.length() > 0){
                ans += " "+word;
            }
        }
        return ans.substr(1);
    }
};