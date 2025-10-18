// Last updated: 18/10/2025, 09:08:19
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {

    let indices = [...Array(nums.length).keys()];
    
    // Sort indices based on corresponding values in nums
    indices.sort((a, b) => nums[a] - nums[b]);

    var start = 0
    var end = indices.length - 1

       while (start < end) {
        let sum = nums[indices[start]] + nums[indices[end]];
        if (sum === target) {
            return [indices[start], indices[end]];
        } else if (sum < target) {
            start++;
        } else {
            end--;
        }
    }
};