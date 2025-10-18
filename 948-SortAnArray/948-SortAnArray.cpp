// Last updated: 18/10/2025, 09:04:21
class Solution {
public:
void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        
        merge(arr, left, mid, right);
    }
}

void merge(std::vector<int>& arr, int left, int mid, int right) {
    std::vector<int> temp(right - left + 1);
    
    int i = left;
    int j = mid + 1;
    int k = 0;
    
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    
    while (i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }
    
    while (j <= right) {
        temp[k] = arr[j];
        j++;
        k++;
    }
    
    for (int i = 0; i < k; i++) {
        arr[left + i] = temp[i];
    }
}
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size() - 1);
        return nums;
    }
};