// Last updated: 18/10/2025, 09:03:37
class Solution {
public:
    string defangIPaddr(string address) {
        int index = 0;
        string ans;
        while(index < address.size())
        {
            if(address[index] == '.')
            {
                ans = ans+"[.]";
            }else{
                ans = ans+address[index];
                
            }
            index++;
        }
        return ans;
    }
};