// Last updated: 18/10/2025, 09:00:49
/*
aeiouu => L = a =>

*/

class Solution {
public:
   int vowelIndex(char c) {
        if(c == 'a' || c == 'A') return 0;
        if(c == 'e' || c == 'E') return 1;
        if(c == 'i' || c == 'I') return 2;
        if(c == 'o' || c == 'O') return 3;
        if(c == 'u' || c == 'U') return 4;
        return -1; // not a vowel
    }
    int countVowelSubstrings(string word) {
        int n = word.size();
        int count = 0;

        for(int i = 0; i< n;i++){
            vector<int>freq(5,0);
            int uniqueVowels = 0;
            for(int j = i; j < n;j++){
                int idx = vowelIndex(word[j]);

                if(idx == -1) {
                    break;
                }

                if(freq[idx] == 0) {
                    uniqueVowels++;
                }
                freq[idx]++;

                if(uniqueVowels == 5){
                    count++;
                }
            }
        }
        return count;
    }
};