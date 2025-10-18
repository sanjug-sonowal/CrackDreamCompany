// Last updated: 18/10/2025, 09:06:01
class Solution {
public:
    void reverseString(vector<char>& s) {
        int start = 0;
        int end = s.size() - 1;

        while(start < end){
            char temp = s[start];
            s[start] = s[end];
            s[end] = temp;
            start++;
            end--;
        }
        for(int i = 0; i<s.size();i++){
            cout<<s[i];
        }
    }
};