// Last updated: 18/10/2025, 09:00:52
class Solution {
public:
    bool areNumbersAscending(string s) {
        int prev = 0;
        bool flag = true;

        for(int i = 0; i< s.length();i++){
            if(s[i] >= '0' && s[i] <= '9'){
                int digit = 0;
                while(i < s.length() && s[i] >= '0' && s[i] <= '9'){
                    digit = digit * 10 + s[i] - '0';
                    i++;
                }
                i--;
                 if(digit <= prev){
                flag = false;
                }
                 prev = digit;
            }
           
        }
        return flag;
    }
};