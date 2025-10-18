// Last updated: 18/10/2025, 08:59:43
class Solution {
public:
    vector<int> evenOddBit(int n) {
        int even = 0;
        int odd = 0;
        int idx = 0;

        while(n > 0){
            if((n & 1)){
                if(idx % 2 == 0)
                    even++;
                else
                odd++;
            }
            n >>= 1;
            idx++;
        }
 

        return {even,odd};
    }
};