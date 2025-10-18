// Last updated: 18/10/2025, 09:06:19
class Solution {
public:
    int addDigits(int num) {
        while(num > 9){
   int ans = 0;int rem = 0;
        while(num!= 0){
            rem = num % 10;
            num /= 10;
            ans = ans + rem;
        }
      num = ans;
        }

        return num;
     
    }
};