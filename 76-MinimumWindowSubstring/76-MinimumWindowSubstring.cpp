// Last updated: 18/10/2025, 09:07:25
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int countRequired = t.length();

        if(t.length() > s.length())
        return "";

        int i = 0,j = 0;
        int start_i = 0;
        int minWindow = INT_MAX;
        unordered_map<char,int>mp;

        for(char &ch:t){
            mp[ch]++;
        }

        while(j < n){
            char ch = s[j];

            if(mp[ch] > 0)
                countRequired--;

            mp[ch]--;

            while(countRequired == 0){
                //shrink the window

                int currentWindow = j - i + 1;

                if(minWindow > currentWindow ){
                    minWindow = currentWindow;
                    start_i = i;
                }

                mp[s[i]]++;

                if(mp[s[i]] > 0){
                    countRequired++;
                }

                i++;
            }
            j++;
        }
        return minWindow == INT_MAX ? "" : s.substr(start_i,minWindow);
    }
};