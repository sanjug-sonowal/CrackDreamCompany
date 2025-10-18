// Last updated: 18/10/2025, 09:00:15
class Solution {
private:
    int getDigitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
public:
    int maximumSum(vector<int>& nums) {
           unordered_map<int, int> digitSumMap;
        int maxSum = -1;

        for (int num : nums) {
            int sumOfDigits = getDigitSum(num);

            if (digitSumMap.find(sumOfDigits) != digitSumMap.end()) {
                maxSum = max(maxSum, digitSumMap[sumOfDigits] + num);
            }

            digitSumMap[sumOfDigits] = max(digitSumMap[sumOfDigits], num);
        }

        return maxSum;
    }
};