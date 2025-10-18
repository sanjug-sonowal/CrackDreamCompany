// Last updated: 18/10/2025, 09:00:42
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int m = bank.size();    // row size
        int n = bank[0].size(); // column size

        int totalBeams = 0;
        int totalDevice = 0;
        
        for(auto row : bank)
        {
            int currentDevice = 0;
            for(char device : row)
            {
                if(device == '1')
                {
                    currentDevice++;
                }
            }

            if(currentDevice > 0)
            {
                totalBeams += totalDevice * currentDevice;
                totalDevice = currentDevice;
            }
        }
            return totalBeams;
    }
};