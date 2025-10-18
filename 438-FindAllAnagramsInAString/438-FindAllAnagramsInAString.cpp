// Last updated: 18/10/2025, 09:05:44
class Solution {
public:
    vector<int> findAnagrams(string txt, string pat) {
         int k = pat.size();
        int n = txt.size();

        vector<int> freqPat(26, 0), freqTxt(26, 0);
        vector<int>ans;

        // frequency of pattern
        for (char ch : pat) {
            freqPat[ch - 'a']++;
        }

        int i = 0, j = 0, count = 0;

        while (j < n) {
            // add current character at j
            freqTxt[txt[j] - 'a']++;

            // if window size < k → expand
            if (j - i + 1 < k) {
                j++;
            }
            // if window size == k → check
            else if (j - i + 1 == k) {
                if (freqTxt == freqPat) {

                    ans.push_back(i);
                }

                // slide the window: remove txt[i]
                freqTxt[txt[i] - 'a']--;
                i++;
                j++;
            }
        }
        return ans;
    }
};