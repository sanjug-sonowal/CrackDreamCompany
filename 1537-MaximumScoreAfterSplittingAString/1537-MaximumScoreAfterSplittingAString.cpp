// Last updated: 18/10/2025, 09:02:32
class Solution {
public:
    int onesCounter(string s) {
       int counter = 0;
       for(int i = 0;i < s.length();i++){
        if(s[i] == '1'){
            counter++;
        }
       }
       return counter;
    }
    int maxScore(string s) {
       int totalOnes = onesCounter(s);
       int max_score = 0;
       int leftOnes = 0;
       int rightOnes = totalOnes;

       for(int i = 0;i < s.length() - 1;i++){
        if(s[i] == '0'){
            leftOnes += 1;
        }else{
            rightOnes -= 1;
        }

        int scores = leftOnes + rightOnes;
        max_score = max(max_score,scores);
       }
       return max_score;
    }
};