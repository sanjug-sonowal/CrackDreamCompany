// Last updated: 18/10/2025, 09:05:36
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
       int content = 0;
       std::sort(g.begin(),g.end());
       std::sort(s.begin(),s.end());

        int i = 0;
        for(int j = 0; j < g.size();j++)
        {
            while(i < s.size() && s[i] < g[j])
            {
                i++;
            }

            if(i < s.size())
            {
                content++;
                i++;
            }else{
                break;
            }
        }

        return content;

    }
};