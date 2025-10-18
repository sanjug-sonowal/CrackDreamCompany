// Last updated: 18/10/2025, 09:01:36
/**
 * @param {string} s
 * @param {number} x
 * @param {number} y
 * @return {number}
 */
function maximumGain(s, x, y) {
    // Helper function to compute points based on removing substrings in a given order
    function gain(s, sub1, point1, sub2, point2) {
        let points = 0;
        let stack1 = [];
        let stack2 = [];
        
        // First remove sub1 and gain points
        for (const char of s) {
            if (stack1.length > 0 && stack1[stack1.length - 1] === sub1[0] && char === sub1[1]) {
                stack1.pop();
                points += point1;
            } else {
                stack1.push(char);
            }
        }
        
        // Then remove sub2 and gain points
        for (const char of stack1) {
            if (stack2.length > 0 && stack2[stack2.length - 1] === sub2[0] && char === sub2[1]) {
                stack2.pop();
                points += point2;
            } else {
                stack2.push(char);
            }
        }
        
        return points;
    }
    
    // Determine which order is optimal based on the given x and y
    if (x > y) {
        return gain(s, "ab", x, "ba", y);
    } else {
        return gain(s, "ba", y, "ab", x);
    }
}
