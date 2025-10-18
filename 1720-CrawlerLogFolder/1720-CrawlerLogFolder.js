// Last updated: 18/10/2025, 09:01:54
/**
 * @param {string[]} logs
 * @return {number}
 */
var minOperations = function(logs) {
    let ans = 0;

    for (let log of logs) {
        if (log === "./") {
            continue;
        }
        if (log === "../") {
            ans = Math.max(0, ans - 1);
        } else {
            ans++;
        }
    }

    return ans;
};
