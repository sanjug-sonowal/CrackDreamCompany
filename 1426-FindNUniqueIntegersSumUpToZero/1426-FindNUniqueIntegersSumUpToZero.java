// Last updated: 18/10/2025, 09:03:03
class Solution {
    public int[] sumZero(int n) {
        int arr[] = new int[n];
       int num = 1;
       for(int i = 0; i  < n / 2;i++){
        arr[i] = num;
        arr[n - i - 1] = -num;
        num++;
       }

       return arr;
    }
}