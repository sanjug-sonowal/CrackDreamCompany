// Last updated: 18/10/2025, 09:06:58
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(int i = 0; i< tokens.size();i++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/" ){
                int val1 = st.top();
                st.pop();
                int val2 = st.top();
                st.pop();

                if(tokens[i] == "+"){
                    st.push(val2 + val1);
                }else if(tokens[i] == "-"){
                    st.push(val2 - val1);
                }else if(tokens[i] == "*"){
                    st.push(val2 * val1);
                }else if(tokens[i] == "/"){
                    st.push(val2 / val1);
                }
            }else{
                st.push(atoi(tokens[i].c_str()));
            }
        }
        return st.top();
    }
};