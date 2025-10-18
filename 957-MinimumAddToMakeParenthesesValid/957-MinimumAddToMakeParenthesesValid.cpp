// Last updated: 18/10/2025, 09:04:20
class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        int count = 0;
        for(int i = 0; i< s.size();i++)
        {
            //opening brackets
            if(s[i] == '(')
            st.push(s[i]);
            //closing brackets
            else
            {
                if(st.empty())
                count++;
                else
                st.pop();
            }
        }

        return count + st.size();
    }
};