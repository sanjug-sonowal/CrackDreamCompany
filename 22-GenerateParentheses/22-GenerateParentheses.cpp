// Last updated: 18/10/2025, 09:08:00
class Solution {
public:
    void genP(vector<string>&ans,string curr,int left,int right,int n){
        if (left == n && right == n) {
            ans.push_back(curr);
            return;
        }

        if(left < n){
            genP(ans,curr + "(",left + 1,right,n);
        }
        
        if(right < left){
            genP(ans,curr + ")",left,right + 1,n);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        genP(ans,"",0,0,n);
        return ans;
    }
};