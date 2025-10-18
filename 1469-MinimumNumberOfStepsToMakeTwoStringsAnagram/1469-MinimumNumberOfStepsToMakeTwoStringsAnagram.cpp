// Last updated: 18/10/2025, 09:02:47
class Solution {
public:
   int minSteps(std::string s, std::string t) {
        std::vector<int> count(26);

        for (int i = 0; i < s.size(); ++i)
            ++count[s[i] - 'a'];

        for (int i = 0; i < t.size(); ++i)
            --count[t[i] - 'a'];

        return std::accumulate(count.begin(), count.end(), 0,
                               [](int subtotal, int c) { return subtotal + std::abs(c); }) / 2;
    }
};