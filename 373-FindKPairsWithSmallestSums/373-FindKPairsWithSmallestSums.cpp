// Last updated: 18/10/2025, 09:05:56
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
          vector<vector<int>> res;
        if(nums1.empty() || nums2.empty() || k == 0) return res;

        long long total = 1LL * nums1.size() * nums2.size();
        if(total < k) k = (int)total;

        using T = tuple<int,int,int>;
        auto cmp = [](T &a, T &b) {
            return get<0>(a) > get<0>(b);
        };
        priority_queue<T, vector<T>, decltype(cmp)> pq(cmp);

        for(int i = 0; i < nums1.size() && i < k; i++) {
            pq.push({nums1[i] + nums2[0], i, 0});
        }

        while(k-- > 0 && !pq.empty()) {
            auto [sum, i, j] = pq.top(); pq.pop();
            res.push_back({nums1[i], nums2[j]});

            if(j + 1 < nums2.size()) {
                pq.push({nums1[i] + nums2[j+1], i, j+1});
            }
        }
        return res;
    }
};