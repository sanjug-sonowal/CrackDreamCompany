// Last updated: 18/10/2025, 09:02:52
class Solution {
public:
    int numberOfSteps(int n) {
        int counter = 0;

        while(n != 0){
            if(n % 2 == 0){
                n /= 2;
                counter++;
            }else{
                n--;
                counter++;
            }
        }
        return counter;
    }
};