// Last updated: 18/10/2025, 09:00:27
class Solution {
public:
    void selectionSort(vector<int> &arr){
        int n = arr.size();
        for(int i = 0;i<n - 1;i++){
            int idx = i;
            for(int j = i + 1;j<n;j++){
                if(arr[j] < arr[idx]){
                    idx = j;
                }
            }
            swap(arr[i],arr[idx]);
        }
    }
    int fillCups(vector<int>& amount) {
        int count = 0;
        while(amount[0] > 0 || amount[1] > 0 || amount[2] > 0){
            selectionSort(amount);

            if(amount[2] > 0){
                amount[2]--;
            }

            if(amount[1] > 0){
                amount[1]--;
            }

            count++;
        }
        return count;
    }
};