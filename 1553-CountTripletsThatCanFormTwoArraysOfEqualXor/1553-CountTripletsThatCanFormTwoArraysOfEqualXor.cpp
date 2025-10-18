// Last updated: 18/10/2025, 09:02:30
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int ans = 0;
        vector<int> xors(1, 0);
        int prefix = 0;

        for (int a : arr) {
            prefix ^= a;
            xors.push_back(prefix);
        }

        for (int j = 1; j < arr.size(); ++j) {
            for (int i = 0; i < j; ++i) {
                int xors_i = xors[j] ^ xors[i];
                for (int k = j; k < arr.size(); ++k) {
                    int xors_k = xors[k + 1] ^ xors[j];
                    if (xors_i == xors_k) {
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};