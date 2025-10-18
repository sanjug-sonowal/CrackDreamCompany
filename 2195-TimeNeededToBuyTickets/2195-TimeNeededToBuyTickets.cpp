// Last updated: 18/10/2025, 09:00:47
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int>q;
        int n = tickets.size();
        int time = 0;

       for(int i = 0;i<n;i++)
       {
            if(i<k)
                time += min(tickets[k],tickets[i]);
            else if(i > k)
                time += min(tickets[k]-1,tickets[i]);
            else
                time += tickets[k];
       }

       return time;
    }
};