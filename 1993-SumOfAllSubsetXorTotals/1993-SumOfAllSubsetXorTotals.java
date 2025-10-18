// Last updated: 18/10/2025, 09:01:18
class Solution {
    public int subsetXORSum(int[] input) {
        int totalSum = 0;
        int n = input.length;

        for (int i = 0; i < (1 << n); i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) {
                if ((i & (1 << j)) != 0) {
                    sum ^= input[j];
                }
            }
            totalSum += sum;
        }
        
        return totalSum;
    }
}