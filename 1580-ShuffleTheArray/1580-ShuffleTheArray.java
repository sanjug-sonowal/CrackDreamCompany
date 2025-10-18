// Last updated: 18/10/2025, 09:02:21
class Solution {
    public int[] shuffle(int[] nums, int n) {
        int[] arr =  new int[2 * n];
        int count = 0;
        for (int i = 0; i < n; i++) {
            arr[count++] = nums[i];
            arr[count++] = nums[i + n];
        }
        return arr;
    }
}
